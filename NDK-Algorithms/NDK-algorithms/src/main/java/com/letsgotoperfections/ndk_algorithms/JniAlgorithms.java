package com.letsgotoperfections.ndk_algorithms;

import android.util.Log;

/**
 * @author hossam.
 */

public class JniAlgorithms {
    static {
        System.loadLibrary("Algorithms");
        Log.e("Hoss", "Algorithms has been loaded successfully");
    }

    private static volatile JniAlgorithms algorithmsInstance;

    private JniAlgorithms() {
        //Prevent form the reflection api.
        if (algorithmsInstance != null) {
            throw new RuntimeException("Use getInstance() method to get " +
                    "the single instance of this class.");
        }

    }

    public static JniAlgorithms getInstance() {
        if (algorithmsInstance == null) { //if there is no instance available... create new one
            synchronized (JniAlgorithms.class) {
                if (algorithmsInstance == null) algorithmsInstance = new JniAlgorithms();
            }
        }

        return algorithmsInstance;
    }

    public void init() {
        Log.d("HOSS", "init: Has called ");
    }

    public int randomNumber(int max) {
        return generateRandomNumber(max);
    }

    public void printMessage(){
        printHossamHassanMessage();
    }

    public static native void printHossamHassanMessage();

    public static native int generateRandomNumber(int max);
//    public static native void printHossamHassanMessage();
    //public static native int generateRandomNumber(int min, int max);
}
