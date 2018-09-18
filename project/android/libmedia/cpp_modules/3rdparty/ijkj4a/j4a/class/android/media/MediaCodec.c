/*
 * Copyright (C) 2015 Zhang Rui <bbcallen@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * https://github.com/Bilibili/jni4android
 * This file is automatically generated by jni4android, do not modify.
 */

#include "MediaCodec.h"

typedef struct J4AC_android_media_MediaCodec__BufferInfo {
    jclass id;

    jfieldID field_flags;
    jfieldID field_offset;
    jfieldID field_presentationTimeUs;
    jfieldID field_size;
    jmethodID constructor_BufferInfo;
} J4AC_android_media_MediaCodec__BufferInfo;
static J4AC_android_media_MediaCodec__BufferInfo class_J4AC_android_media_MediaCodec__BufferInfo;

typedef struct J4AC_android_media_MediaCodec {
    jclass id;

    jmethodID method_createByCodecName;
    jmethodID method_configure;
    jmethodID method_getOutputFormat;
    jmethodID method_getInputBuffers;
    jmethodID method_getInputBuffer;
    jmethodID method_getOutputBuffers;
    jmethodID method_getOutputBuffer;
    jmethodID method_createEncoderByType;
    jmethodID method_createInputSurface;
    jmethodID method_dequeueInputBuffer;
    jmethodID method_queueInputBuffer;
    jmethodID method_dequeueOutputBuffer;
    jmethodID method_releaseOutputBuffer;
    jmethodID method_start;
    jmethodID method_stop;
    jmethodID method_flush;
    jmethodID method_release;
} J4AC_android_media_MediaCodec;
static J4AC_android_media_MediaCodec class_J4AC_android_media_MediaCodec;

jint J4AC_android_media_MediaCodec__BufferInfo__flags__get(JNIEnv *env, jobject thiz)
{
    return (*env)->GetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_flags);
}

jint J4AC_android_media_MediaCodec__BufferInfo__flags__get__catchAll(JNIEnv *env, jobject thiz)
{
    jint ret_value = J4AC_android_media_MediaCodec__BufferInfo__flags__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__BufferInfo__flags__set(JNIEnv *env, jobject thiz, jint value)
{
    (*env)->SetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_flags, value);
}

void J4AC_android_media_MediaCodec__BufferInfo__flags__set__catchAll(JNIEnv *env, jobject thiz, jint value)
{
    J4AC_android_media_MediaCodec__BufferInfo__flags__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jint J4AC_android_media_MediaCodec__BufferInfo__offset__get(JNIEnv *env, jobject thiz)
{
    return (*env)->GetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_offset);
}

jint J4AC_android_media_MediaCodec__BufferInfo__offset__get__catchAll(JNIEnv *env, jobject thiz)
{
    jint ret_value = J4AC_android_media_MediaCodec__BufferInfo__offset__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__BufferInfo__offset__set(JNIEnv *env, jobject thiz, jint value)
{
    (*env)->SetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_offset, value);
}

void J4AC_android_media_MediaCodec__BufferInfo__offset__set__catchAll(JNIEnv *env, jobject thiz, jint value)
{
    J4AC_android_media_MediaCodec__BufferInfo__offset__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jlong J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__get(JNIEnv *env, jobject thiz)
{
    return (*env)->GetLongField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_presentationTimeUs);
}

jlong J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__get__catchAll(JNIEnv *env, jobject thiz)
{
    jlong ret_value = J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__set(JNIEnv *env, jobject thiz, jlong value)
{
    (*env)->SetLongField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_presentationTimeUs, value);
}

void J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__set__catchAll(JNIEnv *env, jobject thiz, jlong value)
{
    J4AC_android_media_MediaCodec__BufferInfo__presentationTimeUs__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jint J4AC_android_media_MediaCodec__BufferInfo__size__get(JNIEnv *env, jobject thiz)
{
    return (*env)->GetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_size);
}

jint J4AC_android_media_MediaCodec__BufferInfo__size__get__catchAll(JNIEnv *env, jobject thiz)
{
    jint ret_value = J4AC_android_media_MediaCodec__BufferInfo__size__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__BufferInfo__size__set(JNIEnv *env, jobject thiz, jint value)
{
    (*env)->SetIntField(env, thiz, class_J4AC_android_media_MediaCodec__BufferInfo.field_size, value);
}

void J4AC_android_media_MediaCodec__BufferInfo__size__set__catchAll(JNIEnv *env, jobject thiz, jint value)
{
    J4AC_android_media_MediaCodec__BufferInfo__size__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jobject J4AC_android_media_MediaCodec__BufferInfo__BufferInfo(JNIEnv *env)
{
    return (*env)->NewObject(env, class_J4AC_android_media_MediaCodec__BufferInfo.id, class_J4AC_android_media_MediaCodec__BufferInfo.constructor_BufferInfo);
}

jobject J4AC_android_media_MediaCodec__BufferInfo__BufferInfo__catchAll(JNIEnv *env)
{
    jobject ret_object = J4AC_android_media_MediaCodec__BufferInfo__BufferInfo(env);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__BufferInfo__BufferInfo__asGlobalRef__catchAll(JNIEnv *env)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__BufferInfo__BufferInfo__catchAll(env);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

int J4A_loadClass__J4AC_android_media_MediaCodec__BufferInfo(JNIEnv *env)
{
    int         ret                   = -1;
    const char *J4A_UNUSED(name)      = NULL;
    const char *J4A_UNUSED(sign)      = NULL;
    jclass      J4A_UNUSED(class_id)  = NULL;
    int         J4A_UNUSED(api_level) = 0;

    if (class_J4AC_android_media_MediaCodec__BufferInfo.id != NULL)
        return 0;

    sign = "android/media/MediaCodec$BufferInfo";
    class_J4AC_android_media_MediaCodec__BufferInfo.id = J4A_FindClass__asGlobalRef__catchAll(env, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.id == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec__BufferInfo.id;
    name     = "flags";
    sign     = "I";
    class_J4AC_android_media_MediaCodec__BufferInfo.field_flags = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.field_flags == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec__BufferInfo.id;
    name     = "offset";
    sign     = "I";
    class_J4AC_android_media_MediaCodec__BufferInfo.field_offset = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.field_offset == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec__BufferInfo.id;
    name     = "presentationTimeUs";
    sign     = "J";
    class_J4AC_android_media_MediaCodec__BufferInfo.field_presentationTimeUs = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.field_presentationTimeUs == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec__BufferInfo.id;
    name     = "size";
    sign     = "I";
    class_J4AC_android_media_MediaCodec__BufferInfo.field_size = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.field_size == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec__BufferInfo.id;
    name     = "<init>";
    sign     = "()V";
    class_J4AC_android_media_MediaCodec__BufferInfo.constructor_BufferInfo = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec__BufferInfo.constructor_BufferInfo == NULL)
        goto fail;

    J4A_ALOGD("J4ALoader: OK: '%s' loaded\n", "android.media.MediaCodec$BufferInfo");
    ret = 0;
    fail:
    return ret;
}

jobject J4AC_android_media_MediaCodec__createByCodecName(JNIEnv *env, jstring name)
{
    return (*env)->CallStaticObjectMethod(env, class_J4AC_android_media_MediaCodec.id, class_J4AC_android_media_MediaCodec.method_createByCodecName, name);
}

jobject J4AC_android_media_MediaCodec__createByCodecName__catchAll(JNIEnv *env, jstring name)
{
    jobject ret_object = J4AC_android_media_MediaCodec__createByCodecName(env, name);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createByCodecName__asGlobalRef__catchAll(JNIEnv *env, jstring name)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__createByCodecName__catchAll(env, name);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createByCodecName__withCString(JNIEnv *env, const char *name_cstr__)
{
    jobject ret_object = NULL;
    jstring name = NULL;

    name = (*env)->NewStringUTF(env, name_cstr__);
    if (J4A_ExceptionCheck__throwAny(env) || !name)
        goto fail;

    ret_object = J4AC_android_media_MediaCodec__createByCodecName(env, name);
    if (J4A_ExceptionCheck__throwAny(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &name);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createByCodecName__withCString__catchAll(JNIEnv *env, const char *name_cstr__)
{
    jobject ret_object = NULL;
    jstring name = NULL;

    name = (*env)->NewStringUTF(env, name_cstr__);
    if (J4A_ExceptionCheck__catchAll(env) || !name)
        goto fail;

    ret_object = J4AC_android_media_MediaCodec__createByCodecName__catchAll(env, name);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &name);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createByCodecName__withCString__asGlobalRef__catchAll(JNIEnv *env, const char *name_cstr__)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__createByCodecName__withCString__catchAll(env, name_cstr__);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

void J4AC_android_media_MediaCodec__configure(JNIEnv *env, jobject thiz, jobject format, jobject surface, jobject crypto, jint flags)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_configure, format, surface, crypto, flags);
}

void J4AC_android_media_MediaCodec__configure__catchAll(JNIEnv *env, jobject thiz, jobject format, jobject surface, jobject crypto, jint flags)
{
    J4AC_android_media_MediaCodec__configure(env, thiz, format, surface, crypto, flags);
    J4A_ExceptionCheck__catchAll(env);
}

jobject J4AC_android_media_MediaCodec__getOutputFormat(JNIEnv *env, jobject thiz)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_getOutputFormat);
}

jobject J4AC_android_media_MediaCodec__getOutputFormat__catchAll(JNIEnv *env, jobject thiz)
{
    jobject ret_object = J4AC_android_media_MediaCodec__getOutputFormat(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__getOutputFormat__asGlobalRef__catchAll(JNIEnv *env, jobject thiz)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__getOutputFormat__catchAll(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobjectArray J4AC_android_media_MediaCodec__getInputBuffers(JNIEnv *env, jobject thiz)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_getInputBuffers);
}

jobjectArray J4AC_android_media_MediaCodec__getInputBuffers__catchAll(JNIEnv *env, jobject thiz)
{
    jobjectArray ret_object = J4AC_android_media_MediaCodec__getInputBuffers(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobjectArray J4AC_android_media_MediaCodec__getInputBuffers__asGlobalRef__catchAll(JNIEnv *env, jobject thiz)
{
    jobjectArray ret_object   = NULL;
    jobjectArray local_object = J4AC_android_media_MediaCodec__getInputBuffers__catchAll(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__getInputBuffer(JNIEnv *env, jobject thiz, jint index)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_getInputBuffer, index);
}

jobject J4AC_android_media_MediaCodec__getInputBuffer__catchAll(JNIEnv *env, jobject thiz, jint index)
{
    jobject ret_object = J4AC_android_media_MediaCodec__getInputBuffer(env, thiz, index);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__getInputBuffer__asGlobalRef__catchAll(JNIEnv *env, jobject thiz, jint index)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__getInputBuffer__catchAll(env, thiz, index);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobjectArray J4AC_android_media_MediaCodec__getOutputBuffers(JNIEnv *env, jobject thiz)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_getOutputBuffers);
}

jobjectArray J4AC_android_media_MediaCodec__getOutputBuffers__catchAll(JNIEnv *env, jobject thiz)
{
    jobjectArray ret_object = J4AC_android_media_MediaCodec__getOutputBuffers(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobjectArray J4AC_android_media_MediaCodec__getOutputBuffers__asGlobalRef__catchAll(JNIEnv *env, jobject thiz)
{
    jobjectArray ret_object   = NULL;
    jobjectArray local_object = J4AC_android_media_MediaCodec__getOutputBuffers__catchAll(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__getOutputBuffer(JNIEnv *env, jobject thiz, jint index)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_getOutputBuffer, index);
}

jobject J4AC_android_media_MediaCodec__getOutputBuffer__catchAll(JNIEnv *env, jobject thiz, jint index)
{
    jobject ret_object = J4AC_android_media_MediaCodec__getOutputBuffer(env, thiz, index);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__getOutputBuffer__asGlobalRef__catchAll(JNIEnv *env, jobject thiz, jint index)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__getOutputBuffer__catchAll(env, thiz, index);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createEncoderByType(JNIEnv *env, jstring type)
{
    return (*env)->CallStaticObjectMethod(env, class_J4AC_android_media_MediaCodec.id, class_J4AC_android_media_MediaCodec.method_createEncoderByType, type);
}

jobject J4AC_android_media_MediaCodec__createEncoderByType__catchAll(JNIEnv *env, jstring type)
{
    jobject ret_object = J4AC_android_media_MediaCodec__createEncoderByType(env, type);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createEncoderByType__asGlobalRef__catchAll(JNIEnv *env, jstring type)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__createEncoderByType__catchAll(env, type);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createEncoderByType__withCString(JNIEnv *env, const char *type_cstr__)
{
    jobject ret_object = NULL;
    jstring type = NULL;

    type = (*env)->NewStringUTF(env, type_cstr__);
    if (J4A_ExceptionCheck__throwAny(env) || !type)
        goto fail;

    ret_object = J4AC_android_media_MediaCodec__createEncoderByType(env, type);
    if (J4A_ExceptionCheck__throwAny(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &type);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createEncoderByType__withCString__catchAll(JNIEnv *env, const char *type_cstr__)
{
    jobject ret_object = NULL;
    jstring type = NULL;

    type = (*env)->NewStringUTF(env, type_cstr__);
    if (J4A_ExceptionCheck__catchAll(env) || !type)
        goto fail;

    ret_object = J4AC_android_media_MediaCodec__createEncoderByType__catchAll(env, type);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &type);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createEncoderByType__withCString__asGlobalRef__catchAll(JNIEnv *env, const char *type_cstr__)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__createEncoderByType__withCString__catchAll(env, type_cstr__);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createInputSurface(JNIEnv *env, jobject thiz)
{
    return (*env)->CallObjectMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_createInputSurface);
}

jobject J4AC_android_media_MediaCodec__createInputSurface__catchAll(JNIEnv *env, jobject thiz)
{
    jobject ret_object = J4AC_android_media_MediaCodec__createInputSurface(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jobject J4AC_android_media_MediaCodec__createInputSurface__asGlobalRef__catchAll(JNIEnv *env, jobject thiz)
{
    jobject ret_object   = NULL;
    jobject local_object = J4AC_android_media_MediaCodec__createInputSurface__catchAll(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = J4A_NewGlobalRef__catchAll(env, local_object);
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, &local_object);
    return ret_object;
}

jint J4AC_android_media_MediaCodec__dequeueInputBuffer(JNIEnv *env, jobject thiz, jlong timeoutUs)
{
    return (*env)->CallIntMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_dequeueInputBuffer, timeoutUs);
}

jint J4AC_android_media_MediaCodec__dequeueInputBuffer__catchAll(JNIEnv *env, jobject thiz, jlong timeoutUs)
{
    jint ret_value = J4AC_android_media_MediaCodec__dequeueInputBuffer(env, thiz, timeoutUs);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__queueInputBuffer(JNIEnv *env, jobject thiz, jint index, jint offset, jint size, jlong presentationTimeUs, jint flags)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_queueInputBuffer, index, offset, size, presentationTimeUs, flags);
}

void J4AC_android_media_MediaCodec__queueInputBuffer__catchAll(JNIEnv *env, jobject thiz, jint index, jint offset, jint size, jlong presentationTimeUs, jint flags)
{
    J4AC_android_media_MediaCodec__queueInputBuffer(env, thiz, index, offset, size, presentationTimeUs, flags);
    J4A_ExceptionCheck__catchAll(env);
}

jint J4AC_android_media_MediaCodec__dequeueOutputBuffer(JNIEnv *env, jobject thiz, jobject info, jlong timeoutUs)
{
    return (*env)->CallIntMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_dequeueOutputBuffer, info, timeoutUs);
}

jint J4AC_android_media_MediaCodec__dequeueOutputBuffer__catchAll(JNIEnv *env, jobject thiz, jobject info, jlong timeoutUs)
{
    jint ret_value = J4AC_android_media_MediaCodec__dequeueOutputBuffer(env, thiz, info, timeoutUs);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void J4AC_android_media_MediaCodec__releaseOutputBuffer(JNIEnv *env, jobject thiz, jint index, jboolean render)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_releaseOutputBuffer, index, render);
}

void J4AC_android_media_MediaCodec__releaseOutputBuffer__catchAll(JNIEnv *env, jobject thiz, jint index, jboolean render)
{
    J4AC_android_media_MediaCodec__releaseOutputBuffer(env, thiz, index, render);
    J4A_ExceptionCheck__catchAll(env);
}

void J4AC_android_media_MediaCodec__start(JNIEnv *env, jobject thiz)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_start);
}

void J4AC_android_media_MediaCodec__start__catchAll(JNIEnv *env, jobject thiz)
{
    J4AC_android_media_MediaCodec__start(env, thiz);
    J4A_ExceptionCheck__catchAll(env);
}

void J4AC_android_media_MediaCodec__stop(JNIEnv *env, jobject thiz)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_stop);
}

void J4AC_android_media_MediaCodec__stop__catchAll(JNIEnv *env, jobject thiz)
{
    J4AC_android_media_MediaCodec__stop(env, thiz);
    J4A_ExceptionCheck__catchAll(env);
}

void J4AC_android_media_MediaCodec__flush(JNIEnv *env, jobject thiz)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_flush);
}

void J4AC_android_media_MediaCodec__flush__catchAll(JNIEnv *env, jobject thiz)
{
    J4AC_android_media_MediaCodec__flush(env, thiz);
    J4A_ExceptionCheck__catchAll(env);
}

void J4AC_android_media_MediaCodec__release(JNIEnv *env, jobject thiz)
{
    (*env)->CallVoidMethod(env, thiz, class_J4AC_android_media_MediaCodec.method_release);
}

void J4AC_android_media_MediaCodec__release__catchAll(JNIEnv *env, jobject thiz)
{
    J4AC_android_media_MediaCodec__release(env, thiz);
    J4A_ExceptionCheck__catchAll(env);
}

int J4A_loadClass__J4AC_android_media_MediaCodec(JNIEnv *env)
{
    int         ret                   = -1;
    const char *J4A_UNUSED(name)      = NULL;
    const char *J4A_UNUSED(sign)      = NULL;
    jclass      J4A_UNUSED(class_id)  = NULL;
    int         J4A_UNUSED(api_level) = 0;

    if (class_J4AC_android_media_MediaCodec.id != NULL)
        return 0;

    api_level = J4A_GetSystemAndroidApiLevel(env);

    if (api_level < 16) {
        J4A_ALOGW("J4ALoader: Ignore: '%s' need API %d\n", "android.media.MediaCodec", api_level);
        goto ignore;
    }

    sign = "android/media/MediaCodec";
    class_J4AC_android_media_MediaCodec.id = J4A_FindClass__asGlobalRef__catchAll(env, sign);
    if (class_J4AC_android_media_MediaCodec.id == NULL)
        goto fail;

    ret = J4A_loadClass__J4AC_android_media_MediaCodec__BufferInfo(env);
    if (ret)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "createByCodecName";
    sign     = "(Ljava/lang/String;)Landroid/media/MediaCodec;";
    class_J4AC_android_media_MediaCodec.method_createByCodecName = J4A_GetStaticMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_createByCodecName == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "configure";
    sign     = "(Landroid/media/MediaFormat;Landroid/view/Surface;Landroid/media/MediaCrypto;I)V";
    class_J4AC_android_media_MediaCodec.method_configure = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_configure == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "getOutputFormat";
    sign     = "()Landroid/media/MediaFormat;";
    class_J4AC_android_media_MediaCodec.method_getOutputFormat = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_getOutputFormat == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "getInputBuffers";
    sign     = "()[Ljava/nio/ByteBuffer;";
    class_J4AC_android_media_MediaCodec.method_getInputBuffers = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_getInputBuffers == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "getInputBuffer";
    sign     = "(I)Ljava/nio/ByteBuffer;";
    class_J4AC_android_media_MediaCodec.method_getInputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_getInputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "getOutputBuffers";
    sign     = "()[Ljava/nio/ByteBuffer;";
    class_J4AC_android_media_MediaCodec.method_getOutputBuffers = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_getOutputBuffers == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "getOutputBuffer";
    sign     = "(I)Ljava/nio/ByteBuffer;";
    class_J4AC_android_media_MediaCodec.method_getOutputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_getOutputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "createEncoderByType";
    sign     = "(Ljava/lang/String;)Landroid/media/MediaCodec;";
    class_J4AC_android_media_MediaCodec.method_createEncoderByType = J4A_GetStaticMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_createEncoderByType == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "createInputSurface";
    sign     = "()Landroid/view/Surface;";
    class_J4AC_android_media_MediaCodec.method_createInputSurface = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_createInputSurface == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "dequeueInputBuffer";
    sign     = "(J)I";
    class_J4AC_android_media_MediaCodec.method_dequeueInputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_dequeueInputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "queueInputBuffer";
    sign     = "(IIIJI)V";
    class_J4AC_android_media_MediaCodec.method_queueInputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_queueInputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "dequeueOutputBuffer";
    sign     = "(Landroid/media/MediaCodec$BufferInfo;J)I";
    class_J4AC_android_media_MediaCodec.method_dequeueOutputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_dequeueOutputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "releaseOutputBuffer";
    sign     = "(IZ)V";
    class_J4AC_android_media_MediaCodec.method_releaseOutputBuffer = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_releaseOutputBuffer == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "start";
    sign     = "()V";
    class_J4AC_android_media_MediaCodec.method_start = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_start == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "stop";
    sign     = "()V";
    class_J4AC_android_media_MediaCodec.method_stop = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_stop == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "flush";
    sign     = "()V";
    class_J4AC_android_media_MediaCodec.method_flush = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_flush == NULL)
        goto fail;

    class_id = class_J4AC_android_media_MediaCodec.id;
    name     = "release";
    sign     = "()V";
    class_J4AC_android_media_MediaCodec.method_release = J4A_GetMethodID__catchAll(env, class_id, name, sign);
    if (class_J4AC_android_media_MediaCodec.method_release == NULL)
        goto fail;

    J4A_ALOGD("J4ALoader: OK: '%s' loaded\n", "android.media.MediaCodec");
    ignore:
    ret = 0;
    fail:
    return ret;
}