package com.letsgotoperfections.sample;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.letsgotoperfections.ndk_algorithms.JniAlgorithms;


public class MainActivity extends AppCompatActivity {

    TextView tvRandomNumber;
//    static {
//        System.loadLibrary("Algorithms");
//        Log.e("Hoss", "Algorithms has been loaded successfully");
//    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tvRandomNumber = (TextView) findViewById(R.id.tvRandomNumber);
        JniAlgorithms.getInstance().init();
        String text = "NDK generated this number randomly:  " + JniAlgorithms.getInstance().randomNumber(100);
        tvRandomNumber.setText(text);
        JniAlgorithms.getInstance().printMessage();
        //printForMainActivity();
    }
    public native void printForMainActivity();


}
