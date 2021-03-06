#pragma once

#include "core/media_common/media_struct.h"
#include "core/media_common/bsf_filter.h"
#include "core/media_common/raw_stream_parser.h"
#include "core/media_common/av_demuxer.h"
#include "core/media_common/av_muxer.h"
#include "core/media_common/av_decoder.h"
#include "core/utils/jas_getopt.h"
#include "core/media_common/av_encoder.h"
#include "core/media_common/raw_filter.h"
#include <iostream>
#include <functional>
#include <iostream>
#include <thread>
#include <string>
#include <algorithm>   
#include <type_traits>
#include <thread>
#include <mutex>
#include <memory>
#include <map>
#include <list>
#include <deque>

namespace av {

constexpr const char *VP_SMALL = "vp_small";
constexpr const char *VP_LARGER = "vp_larger";

enum class InsertType :uint8_t
{
    Small,
    LargeInSmall,
    Large
};

typedef struct VideoPadding {
    InsertType streamType = InsertType::Small;
    int64_t start_pts{ AV_NOPTS_VALUE };
    int64_t end_pts{ AV_NOPTS_VALUE };
    int64_t write_end_pts{ AV_NOPTS_VALUE };
    VideoPadding(InsertType type, int64_t startpts, int64_t endpts) :
        streamType(type), start_pts(startpts), end_pts(endpts)
    {
    }
}VideoPadding;

using std::unique_ptr;
class MergerCtx {

public:
    MergerCtx() = default;
    ~MergerCtx() {
        m_aStream1.reset();
        m_vStream1.reset();
        m_vStream2.reset();
        m_decodeV.reset();
        m_output.reset();
        m_encodeV.reset();
    }

    int openInputStreams(const char *input1, const char *input2, const char *output);

    int openOutputFile(const char *file);

    int cfgCodec();

    int mergerLoop();
    
private:
    unique_ptr<FilterGraph> m_filterGraph{ nullptr };
    unique_ptr<AVDemuxer> m_aStream1{ nullptr };
    unique_ptr<AVDemuxer> m_vStream1{ nullptr };
    unique_ptr<AVDemuxer> m_vStream2{ nullptr };
    unique_ptr<AVDecoder> m_decodeV{ nullptr };
    unique_ptr<AVMuxer> m_output{ nullptr };
    unique_ptr<AVEncoder> m_encodeV{ nullptr };

    std::map<int64_t, VideoPadding> m_segment_info;

    std::unique_ptr<AVBSFContext, AVBSFContextDeleter> mp4H264_bsf{ nullptr };

    AVRational m_frame_rate;
    int64_t m_frame_duration{ 0 };
    int m_videIndex{ -1 };
    int m_audioIndex{ -1 };
    int64_t m_small_offset{ 0 };
    int64_t m_previous_audio_pts{ AV_NOPTS_VALUE };
    std::deque<std::pair<int64_t, int64_t>> m_large_correct;

    std::list<std::unique_ptr<AVPacket, AVPacketDeleter>> m_packet_queue;
    void writeVideoPacket(AVPacket *packet);
    int insertVideoPacket(AVPacket *packet);
    int getVideoFrame(AVDemuxer *demuxer, AVDecoder *decoder, AVFrame *frame);
    int writeAudioPacket(AVDemuxer *input, AVMuxer  *output, int64_t pts_flag, int index);
    int encodeWriteFrame(AVEncoder *encoder, AVFrame *frame);
    int frameScale(AVFrame *frame);
    int readSlicePacket(int64_t small_pts);
    int filterConf(const AVCodecParameters *parm);

    void genCommentInfo(std::map<int64_t, VideoPadding> &sei_info);
    void setCommentInfo();

    int correctTimestamp(const char *file1, const char *file2, const char *output);
};

typedef struct CommandCtx
{
    std::string input1;
    std::string input2;
    std::string output;
    std::string vcodec;

}CommandCtx;

static CommandCtx command_t;

static void print_help() {
    printf("Usage: \n"
        "  [-h                                  printf help info]\n"
        "  [--input1    input1.mp4              input file name]\n"
        "  [--input2    input2.mp4              input file name]\n"
        "  [--output    output.mp4              output file name]\n"
        "  [--cv        crf=22:aq-mode=1        output file name]\n"
    );
}

static int parser_option(int argc,  char *argv[]) {
    jas_opt_t opt_list[] = {
    { ID_FOURCC('h', 'e', 'l', 'p'), "h",           0 },
    { ID_FOURCC('i', 'p', 't', '1'), "input1",      JAS_OPT_HASARG },
    { ID_FOURCC('i', 'p', 't', '2'), "input2",      JAS_OPT_HASARG },
    { ID_FOURCC('o', 'p', 't', ' '), "output",      JAS_OPT_HASARG },
    { ID_FOURCC('c', 'o', 'd', 'v'), "cv",          JAS_OPT_HASARG },
    { -1, nullptr, 0 }
    };

    for (;;) {
        int tag = jas_getopt(argc, argv, opt_list);
        if (tag == JAS_GETOPT_EOF)
            break;
        switch (tag)
        {
        case ID_FOURCC('h', 'e', 'l', 'p'): {
            print_help();
            exit(0);
            break;
        }
        case ID_FOURCC('i', 'p', 't', '1'): {
            command_t.input1 = jas_optarg;
            break;
        }
        case ID_FOURCC('i', 'p', 't', '2'): {
            command_t.input2 = jas_optarg;
            break;
        }
        case ID_FOURCC('o', 'p', 't', ' '): {
            command_t.output = jas_optarg;
            break;
        }
        case ID_FOURCC('c', 'o', 'd', 'v'): {
            command_t.vcodec = jas_optarg;
            break;
        }
        default:
            break;
        }
    }
    if (command_t.input1.empty() ||
        command_t.input2.empty() ||
        command_t.output.empty()) {
        print_help();
        return -1;
    }
    return 0;
}

}
