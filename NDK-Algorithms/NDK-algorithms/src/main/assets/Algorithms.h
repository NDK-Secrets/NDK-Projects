/** Public API for interacting with Bugsnag */
#ifndef BUGSNAG_ANDROID_NDK_BUGSNAG_API_H
#define BUGSNAG_ANDROID_NDK_BUGSNAG_API_H

#include <jni.h>
#include "Algorithms.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Configure the Bugsnag interface, optionally including the JNI environment.
 * @param env  The JNI environment to use when using convenience methods
 */
void printHossamHassanMessage();

#ifdef __cplusplus
}
#endif

#endif //BUGSNAG_ANDROID_NDK_BUGSNAG_API_H
