#include <jni.h>
#include "algorithms.h"



extern "C"
JNIEXPORT jint JNICALL
Java_com_letsgotoperfection_ndk_1sample001_MainActivity_calculateSumJNI(JNIEnv *env,
                                                                     jobject instance) {
    algorithms algorithms1;
    return algorithms1.generateRandomNumber(100);
}