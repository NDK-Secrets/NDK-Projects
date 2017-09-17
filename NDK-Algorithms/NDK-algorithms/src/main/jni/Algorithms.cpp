#include <jni.h>
#include <android/log.h>
#include <Algorithms.h>

#define  LOG_TAG    "Hoss"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)



#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_letsgotoperfections_ndk_1algorithms_JniAlgorithms_printHossamHassanMessage(JNIEnv *env,
                                                                                    jclass type) {
    LOGE("Java_com_letsgotoperfections_ndk_1algorithms_JniAlgorithms_printHossamHassanMessage has been called");
}

JNIEXPORT void JNICALL
Java_com_letsgotoperfections_sample_MainActivity_printForMainActivity(JNIEnv *env,
                                                                      jobject instance) {
    LOGE("Java_com_letsgotoperfections_sample_MainActivity_printForMainActivity has been called");
}

JNIEXPORT jint JNICALL
Java_com_letsgotoperfections_ndk_1algorithms_JniAlgorithms_generateRandomNumber(JNIEnv *env,
                                                                                jclass type,
                                                                                jint max) {
    Algorithms algorithms;
    return algorithms.generateRandomNumber(max);

}
#ifdef __cplusplus
}
#endif