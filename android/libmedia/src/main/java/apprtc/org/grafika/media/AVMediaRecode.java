package apprtc.org.grafika.media;

import android.media.MediaFormat;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.util.Log;

import java.io.File;
import java.nio.ByteBuffer;
import java.util.concurrent.TimeUnit;

import apprtc.org.grafika.AVRecodeInterface;
import apprtc.org.grafika.JNIBridge;
import apprtc.org.grafika.Logging;
import apprtc.org.grafika.gles.EglBase;
import apprtc.org.grafika.gles.EglBase14;
import apprtc.org.grafika.media.AVStruct.*;

import static apprtc.org.grafika.media.AVMediaCodec.AV_CODEC_ID_H264;
import static apprtc.org.grafika.media.AVMediaCodec.AV_CODEC_ID_VP8;
import static apprtc.org.grafika.media.AVMediaCodec.AV_CODEC_ID_VP9;

public class AVMediaRecode implements AVRecodeInterface {

    private static String TAG = "AVMediaRecode";
    private ReportInfo mReportInfo = new ReportInfo();
    private MediaCodecVideoDecoder mVideoDecoder = null;
    private MediaCodecVideoEncoder mVideoEncoder = null;

    private Handler mHandler = null;
    private EglBase rootEglBase = null;
    private SurfaceTextureHelper mSurfaceTextureHelper = null;

    private MediaInfo mMediaInfo = new MediaInfo();
    private AVPacket mAVPacketBuffer = new AVPacket((int) (1920 * 1080 * 1.5));
    private long mEngineHandleDemuxer = 0;
    private boolean recodeIsRunning = false;
    private int mErrorCode = 0;
    private String inputSource;
    private String clipDirectory;
    private String clipPrefix;
    private int clipBitrate = 0;
    private int clipWidth = 0;
    private int clipHeight = 0;
    private int clipDurationMs;
    private int clipIndex = 0;
    private Handler eventListenerHandler = null;
    private onRecodeEventListener eventListener = null;
    private onRecodeEventListener eventListener_inner = new onRecodeEventListener() {
        @Override
        public void onPrintReport(final String message) {
            if(eventListener != null){
                eventListenerHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        eventListener.onPrintReport(message);
                    }
                });
            }
        }

        @Override
        public void onErrorMessage(final int errorCode, final String errorMessage) {
            if(eventListener != null){
                eventListenerHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        mErrorCode = errorCode;
                        eventListener.onErrorMessage(errorCode, errorMessage);
                    }
                });
            }
        }

        @Override
        public void onRecodeFinish() {
            if(eventListener != null){
                eventListenerHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        eventListener.onRecodeFinish();
                    }
                });
            }
        }
    };


    public AVMediaRecode(){ }

    private boolean initVideoDecoder(){
        MediaFormat format = null;
        if(mMediaInfo.width <= 0 || mMediaInfo.height <= 0){
            return false;
        }

        if(mMediaInfo.videoCodecID == AV_CODEC_ID_H264){
            format = MediaFormat.createVideoFormat(MediaFormat.MIMETYPE_VIDEO_AVC, mMediaInfo.width, mMediaInfo.height);
        }
        else if(mMediaInfo.videoCodecID == AV_CODEC_ID_VP8){
            format = MediaFormat.createVideoFormat(MediaFormat.MIMETYPE_VIDEO_VP8, mMediaInfo.width, mMediaInfo.height);
        }
        else if(mMediaInfo.videoCodecID == AV_CODEC_ID_VP9){
            format = MediaFormat.createVideoFormat(MediaFormat.MIMETYPE_VIDEO_VP9, mMediaInfo.width, mMediaInfo.height);
        }
        else{
            return false;
        }
        format.setInteger(MediaFormat.KEY_FRAME_RATE, mMediaInfo.framerate);
        mVideoDecoder = new MediaCodecVideoDecoder();
        return mVideoDecoder.initDecode(format, mSurfaceTextureHelper);
    }

    private boolean  initVideoEncoder(int width, int height, int bitrate, int fps, EglBase.Context sharedContext){
        if(mVideoEncoder != null)
            throw new RuntimeException("forget  release encoder?");

        if(sharedContext instanceof EglBase14.Context){
            mVideoEncoder = new MediaCodecVideoEncoder();
            return mVideoEncoder.initEncode(width, height, bitrate, fps, (EglBase14.Context) sharedContext);
        }
        else{
            Log.e(TAG, "unsupport EglBase14");
            return false;
        }
    }


    private AVPacket readPacket(){
        if(mAVPacketBuffer.bufferSize == 0){
            while(true){
                mAVPacketBuffer.buffer.rewind();
                int ret = JNIBridge.native_demuxer_readPacket(mEngineHandleDemuxer, mAVPacketBuffer);
                if(ret < 0)
                    return null;
                if(mAVPacketBuffer.bufferSize == 0)
                    continue;
                if(mAVPacketBuffer.mediaType == AVMediaType.VIDEO){
                    break;
                }
            }
            mAVPacketBuffer.buffer.position(0);
            mAVPacketBuffer.buffer.limit(mAVPacketBuffer.bufferSize);
        }

        if(mReportInfo.start_time_ms ==  Long.MIN_VALUE)
            mReportInfo.start_time_ms = System.currentTimeMillis();
        if(mReportInfo.first_pts_ms ==  Long.MIN_VALUE)
            mReportInfo.first_pts_ms = TimeUnit.MICROSECONDS.toMillis(mAVPacketBuffer.ptsUs);

        return new AVPacket(mAVPacketBuffer.mediaType, mAVPacketBuffer.ptsUs, mAVPacketBuffer.dtsUs, mAVPacketBuffer.buffer,
                mAVPacketBuffer.bufferSize, mAVPacketBuffer.bufferOffset, mAVPacketBuffer.bufferFlags);
    }

    boolean advance(){
        mAVPacketBuffer.bufferSize = 0;
        mAVPacketBuffer.buffer.rewind();
        return true;
    }

    boolean writePacket(AVPacket packet){
        int ret = -1;
        if(mEngineHandleDemuxer != 0){
            ret = JNIBridge.native_demuxer_writePacket(mEngineHandleDemuxer, packet);
            mReportInfo.frames += 1;
            mReportInfo.sum_data_kb +=  packet.bufferSize/1024;
            print_report(TimeUnit.MICROSECONDS.toMillis(packet.ptsUs));
        }
        return ret == 0;
    }


    void print_report(long ptsMs){
        long current = System.currentTimeMillis();
        if(current - mReportInfo.last_report_time < 500)
            return;

        double duration_time_s = (current - mReportInfo.start_time_ms)/1000.0;
        mReportInfo.last_report_time = current;
        mReportInfo.fps = (int) (mReportInfo.frames / duration_time_s);

        double duration_pts_s = (ptsMs - mReportInfo.first_pts_ms)/1000.0;
        duration_pts_s = duration_pts_s <= 0 ? 0.04 : duration_pts_s;
        mReportInfo.bitrate_bit = (int) (mReportInfo.sum_data_kb * 8 / duration_pts_s);
        eventListener_inner.onPrintReport(mReportInfo.toString());
        return;
    }


    void recodeLoopThread(){
        if(mVideoDecoder == null || mEngineHandleDemuxer == 0){
            release();
            mHandler.getLooper().quitSafely();
            return;
        }

        generatorClip(Long.MAX_VALUE);
        while(recodeIsRunning && mErrorCode == 0){
            AVPacket packet = readPacket();
            if(packet == null) {
                break;
            }
            int ret = sendPacket(packet.buffer, packet.bufferSize, packet.ptsUs, packet.mediaType);
            if(ret == 0){
                advance();
            }

            if(mVideoDecoder != null){
                MediaCodecVideoDecoder.DecodedTextureBuffer textureBuffer = mVideoDecoder.receiveFrame();
                if(textureBuffer != null){
                    generatorClip(TimeUnit.MICROSECONDS.toMillis(textureBuffer.ptsUs));
                    encoderWrietPacket(textureBuffer.textureID, textureBuffer.transformMatrix, textureBuffer.ptsUs);
                    mSurfaceTextureHelper.returnTextureFrame();
                }
            }

        }

        //flush video decoder
        while (mVideoDecoder != null){
            MediaCodecVideoDecoder.DecodedTextureBuffer textureBuffer = mVideoDecoder.flushDecoder();
            if(textureBuffer == null)
                break;
            generatorClip(TimeUnit.MICROSECONDS.toMillis(textureBuffer.ptsUs));
            encoderWrietPacket(textureBuffer.textureID, textureBuffer.transformMatrix, textureBuffer.ptsUs);
            mSurfaceTextureHelper.returnTextureFrame();

        }

        flushEncoder();
        release();
        eventListener_inner.onRecodeFinish();
        mHandler.getLooper().quitSafely();
    }




    void generatorClip(long ptsMs){
//        long start = clipIndex * clipDurationMs;
        long end = (clipIndex + 1) * clipDurationMs + mMediaInfo.startTime;

        if(ptsMs >= end && ptsMs != Long.MAX_VALUE){
            clipIndex++;
            flushEncoder();
        }

        if(ptsMs >= end){
            String output = clipDirectory + clipPrefix + new Integer(clipIndex).toString() + ".mp4";
            Logging.w(TAG, "new output " + output);
            JNIBridge.native_demuxer_openOutputFormat(mEngineHandleDemuxer, output);
            if(mVideoDecoder != null){
                if(!initVideoEncoder(clipWidth, clipHeight, clipBitrate,
                        mMediaInfo.framerate, rootEglBase.getEglBaseContext())){
                    if(mVideoEncoder != null){mVideoEncoder.release(); mVideoEncoder = null;}
                    eventListener_inner.onErrorMessage(-1, "open video encode error");
                }
            };
        }
    }

    boolean encoderWrietPacket(int oesTextureId, float[] transformationMatrix, long presentationTimestampUs){
        if(mVideoEncoder == null)
            return false;

        boolean ret = mVideoEncoder.sendFrame(oesTextureId, transformationMatrix, presentationTimestampUs);
        while (ret) {
            AVPacket pkt = null;
            CodecBufferInfo bufferinfo = mVideoEncoder.receivePacket();
            if(bufferinfo != null) {
                pkt =  new AVPacket(AVMediaType.VIDEO, bufferinfo.ptsUs, bufferinfo.ptsUs, bufferinfo.buffer,
                        bufferinfo.size, bufferinfo.offset, bufferinfo.flags);
            }
            if (pkt == null)
                break;
            if(!(ret = writePacket(pkt)))
                break;
        }
        return ret;
    }


    void flushEncoder(){
        //flush video encoder
        while(mVideoEncoder != null){
            AVPacket  packet = null;
            CodecBufferInfo bufferinfo = mVideoEncoder.flushEncoder();
            if(bufferinfo != null) {
                packet = new AVPacket(AVMediaType.VIDEO, bufferinfo.ptsUs, bufferinfo.ptsUs, bufferinfo.buffer,
                        bufferinfo.size, bufferinfo.offset, bufferinfo.flags);
            }
            if(packet == null){
                break;
            }

            writePacket(packet);
            mVideoEncoder.signalEndOfInputStream();
        }
        JNIBridge.native_demuxer_closeOutputFormat(mEngineHandleDemuxer);
        if(mVideoEncoder != null){mVideoEncoder.release(); mVideoEncoder = null;}
    }

    int sendPacket(ByteBuffer buffer, int size, long pts, int mediaType){
        int ret = -1;
        if(mediaType == AVMediaType.VIDEO){
            ret = mVideoDecoder.sendPacket(buffer, size, pts);
        }
        return ret;
    }
    void release()
    {
        if(mEngineHandleDemuxer != 0){JNIBridge.native_demuxer_closeInputFormat(mEngineHandleDemuxer); mEngineHandleDemuxer = 0;}
        if(mVideoDecoder != null){ mVideoDecoder.release(); mVideoDecoder = null; }
        if(mVideoEncoder != null){ mVideoEncoder.release(); mVideoEncoder = null; }
        if(mSurfaceTextureHelper != null){mSurfaceTextureHelper.dispose();}
        if(rootEglBase != null){rootEglBase.release();}
        Log.w(TAG, "!!!!!!!!release all source");
    }

    @Override
    public boolean openInputSource(String input) {
        this.inputSource = input;
        if(mHandler == null){
            final HandlerThread thread = new HandlerThread("vp_recode");
            thread.start();
            mHandler = new Handler(thread.getLooper(), mCallback);
        }
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                mEngineHandleDemuxer = JNIBridge.native_demuxer_createEngine();
                if(JNIBridge.native_demuxer_openInputFormat(mEngineHandleDemuxer, inputSource) < 0){
                    eventListener_inner.onErrorMessage(-1, "openInputFormat error");
                    return;
                }
                JNIBridge.native_demuxer_getMediaInfo(mEngineHandleDemuxer, mMediaInfo);
                rootEglBase = EglBase.create();
                mSurfaceTextureHelper = SurfaceTextureHelper.create("vp_texturehelp", rootEglBase.getEglBaseContext());
                if(!initVideoDecoder()){
                    if(mVideoDecoder != null){mVideoDecoder.release(); mVideoDecoder = null;}
                    eventListener_inner.onErrorMessage(-1, "open video decoder error");
                }
            }
        });

        return true;
    }


    @Override
    public boolean setOutputSourceParm(String clipDirectory, String clipPrefix, int clipWidth, int clipHeight, int clipBitrate, int clipDurationMs) {
        this.clipPrefix = clipPrefix;
        this.clipDurationMs = clipDurationMs;
        this.clipWidth = clipWidth;
        this.clipHeight = clipHeight;
        this.clipBitrate = clipBitrate;
        this.clipDirectory = clipDirectory;
        if(clipDirectory.charAt(clipDirectory.length() -1) != File.separatorChar){
            this.clipDirectory = this.clipDirectory + File.separatorChar;
        }
        return true;
    }

    @Override
    public void setRecodeEventListener(onRecodeEventListener listener, Handler handler){
        eventListener = listener;
        eventListenerHandler = handler;
    }

    @Override
    public void starRecode() {
        mHandler.sendMessage(mHandler.obtainMessage(MSE_START_RECODER, this));

    }

    @Override
    public void stopRecode() {
        recodeIsRunning = false;
    }

    public class ReportInfo{
        long start_time_ms = Long.MIN_VALUE;
        long first_pts_ms = Long.MIN_VALUE;
        long frames = 0;
        long sum_data_kb = 0;
        int fps = 0;
        int bitrate_bit = 0;
        long last_report_time = 0;

        @Override
        public String toString() {
            String message = ("frames= " + mReportInfo.frames + "  fps= " + mReportInfo.fps + " bitrate " + mReportInfo.bitrate_bit+"kbit/s");
            return message;
        }
    }


    static private final int MSE_START_RECODER = 0x0001;
    static private final int MSE_STOP_RECODER = 0x0002;
    static private Handler.Callback mCallback = new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            final AVMediaRecode thisObj = (AVMediaRecode) msg.obj;
            switch (msg.what) {
                case MSE_START_RECODER: {
                    if (!thisObj.recodeIsRunning) {
                        thisObj.recodeIsRunning = true;
                        thisObj.recodeLoopThread();
                    }
                    break;
                }
                case MSE_STOP_RECODER: {
//                stopRecoder();
                    break;
                }
                default:
                    throw new RuntimeException("Unknown message " + msg.what);
            }
            return true;
        }
    };


}
