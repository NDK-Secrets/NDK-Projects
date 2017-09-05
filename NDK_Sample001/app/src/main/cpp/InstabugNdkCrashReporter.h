//
// Created by Hossam Hassan on 8/30/17.
//

#pragma once

class InstabugNdkCrashReporter{
public:
    InstabugNdkCrashReporter();
    ~InstabugNdkCrashReporter();
    void init();
    static void signal_callback_handler(int signum);
};
