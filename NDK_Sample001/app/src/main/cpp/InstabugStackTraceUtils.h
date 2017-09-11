//
// Created by Hossam Hassan on 9/10/17.
//

#ifndef NDK_SAMPLE001_INSTABUGSTACKTRACEUTILS_H
#define NDK_SAMPLE001_INSTABUGSTACKTRACEUTILS_H


#include <unwind.h>
#include <iosfwd>

struct BacktraceState {
    void **current;
    void **end;
};

class InstabugStackTraceUtils {
    static _Unwind_Reason_Code unwindReasonCodeCallback(struct _Unwind_Context *context, void *arg);

    size_t captureBacktrace(void **buffer, size_t max);

    void dumpBacktrace(std::ostream &os, void **buffer, size_t count);

public:
    void backtraceToLogcat();
};


#endif //NDK_SAMPLE001_INSTABUGSTACKTRACEUTILS_H
