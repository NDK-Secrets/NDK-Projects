//
// Created by Hossam Hassan on 8/16/17.
//

#include <jni.h>
#include <string>
#include "algorithms.h"


extern "C"
JNIEXPORT jint JNICALL
Java_com_letsgotoperfection_ndk_1sample000_MainActivity_generateRandomNumber
        (JNIEnv* env, jobject /* this */,jint max) {
    algorithms algorithms1;
    jint randomNumber = (jint)algorithms1.generateRandomNumber(max) ;
    return randomNumber;
}