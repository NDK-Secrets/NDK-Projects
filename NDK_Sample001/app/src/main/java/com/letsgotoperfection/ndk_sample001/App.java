package com.letsgotoperfection.ndk_sample001;

import android.app.Application;

import com.bugsnag.android.Bugsnag;
import com.instabug.library.Instabug;
import com.instabug.library.invocation.InstabugInvocationEvent;

/**
 * @author hossam.
 */

public class App extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        new Instabug.Builder(this, "Token")
                .build();
        Instabug.changeInvocationEvent(InstabugInvocationEvent.FLOATING_BUTTON);
        Bugsnag.init(this);

    }
}
