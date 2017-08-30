//
// Created by Hossam Hassan on 8/16/17.
//
//#if _pragma_once_support
//#    pragma once
//#endif
#ifndef NDK_SAMPLE000_ALGORITHMS_H
#define NDK_SAMPLE000_ALGORITHMS_H

#include "iostream"
#include "ctime"
#include "cstdlib"

class algorithms {

public:
    int generateRandomNumber(int max) {
        srand(time(0));
        int random = 1 + (rand() % max);
        throw 23;
        return random;
    }
};

#endif //NDK_SAMPLE000_ALGORITHMS_H
