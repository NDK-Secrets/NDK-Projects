//
// Created by Hossam Hassan on 9/14/17.
//

#include "Algorithms.h"
#include <ctime>
#include "cstdlib"
#include <android/log.h>


#define  LOG_TAG    "Hoss"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

using namespace std;
Algorithms::Algorithms() {

}

Algorithms::~Algorithms() {

}

int Algorithms::generateRandomNumber(int max) {
    srand((unsigned int) time(0));
    int random = 1 + (rand() % max);
    return random;
}

void Algorithms::printHossamHassanMessage() {
    LOGE("printHossamHassanMessage() has been called");
}

//int algorithms::generateRandomNumber(int min, int max) {
//    int random = min + (rand() % static_cast<int>(max - min + 1));
//    return random;
//}
