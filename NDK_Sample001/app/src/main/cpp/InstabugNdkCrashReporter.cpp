//
// Created by Hossam Hassan on 8/30/17.
//
#include "InstabugNdkCrashReporter.h"
#include "InstabugStackTraceUtils.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "your-log-tag"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "InstabugStackTraceUtils.cpp"

void InstabugNdkCrashReporter::signal_callback_handler(int signum) {
    //printf("Caught signal %d\n", signum);
    LOGD("Caught signal %d\n", signum);
    InstabugStackTraceUtils instabugStackTraceUtils;
    instabugStackTraceUtils.backtraceToLogcat();
    // Cleanup and close up stuff here

    // Terminate recipes
    //exit(signum);
}


InstabugNdkCrashReporter::InstabugNdkCrashReporter() {
    // Register signal and signal handler
    for (int i = 1; i < 33; ++i) {
        signal(i, signal_callback_handler);
    }
}

InstabugNdkCrashReporter::~InstabugNdkCrashReporter() {
    LOGD("InstabugNdkCrashReporter has destroyed");
}

void InstabugNdkCrashReporter::init() {
    LOGD("InstabugNdkCrashReporter is initialized");
}

extern "C"
JNIEXPORT void JNICALL
Java_com_letsgotoperfection_ndk_1sample001_App_initInstabugNdk(JNIEnv *env, jobject instance) {
    InstabugNdkCrashReporter instabugNdkCrashReporter;
    instabugNdkCrashReporter.init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_letsgotoperfection_ndk_1sample001_MainActivity_raiseSignal(
        JNIEnv *env, jobject instance, jint signal) {
    raise(signal);
}


//// Define the function to be called when ctrl-c (SIGINT) signal is sent to recipes
//void
//signal_callback_handler(int signum) {
//
//}