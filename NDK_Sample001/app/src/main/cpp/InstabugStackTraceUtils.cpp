//
// Created by Hossam Hassan on 9/10/17.
//

#include <dlfcn.h>
#include <android/log.h>

#define  LOG_TAG    "InstabugNdk"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "InstabugStackTraceUtils.h"
#include <sstream>

_Unwind_Reason_Code
InstabugStackTraceUtils::unwindReasonCodeCallback(struct _Unwind_Context *context, void *arg) {
    BacktraceState *state = static_cast<BacktraceState *>(arg);
    uintptr_t pc = _Unwind_GetIP(context);
    if (pc) {
        if (state->current == state->end) {
            return _URC_END_OF_STACK;
        } else {
            *state->current++ = reinterpret_cast<void *>(pc);
        }

    }
    return _URC_NO_REASON;
}

size_t InstabugStackTraceUtils::captureBacktrace(void **buffer, size_t max) {
    BacktraceState state = {buffer, buffer + max};
    _Unwind_Backtrace(unwindReasonCodeCallback, &state);

    return state.current - buffer;
}

void InstabugStackTraceUtils::dumpBacktrace(std::ostream &os, void **buffer, size_t count) {

    for (size_t index = 0; index < count; ++index) {
        const void *address = buffer[index];
        const char *symbol = "";

        Dl_info info;
        if (dladdr(address, &info) && info.dli_sname) {
            symbol = info.dli_sname;
        }
        //LOGE("Instabug NDK: %d\t0x%0x\t%s\n", index, address, symbol);

        os << " #" << index << ": " << address << "  " << symbol << "\n";
    }
}

void InstabugStackTraceUtils::backtraceToLogcat() {
    const size_t max = 30;
    void *buffer[max];
    std::ostringstream oss;

    dumpBacktrace(oss, buffer, captureBacktrace(buffer, max));
    LOGE("Instabug NDK\n%s", oss.str().c_str());
}


