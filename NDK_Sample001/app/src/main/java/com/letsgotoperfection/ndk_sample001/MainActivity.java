package com.letsgotoperfection.ndk_sample001;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.instabug.library.Instabug;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("algorithms");
    }

    Button btnCalculateSum;
    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);
        btnCalculateSum = (Button) findViewById(R.id.btnCalculateSum);
        btnCalculateSum.setOnClickListener(this);
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int calculateSumJNI();

    @Override
    public void onClick(View view) {
        if (view.getId() == btnCalculateSum.getId()) {
            try {
                String x = "The sum is equals to = " + calculateSumJNI();
                tv.setText(x);
            }catch (Exception e){
                Instabug.reportException(e);
            }
        }
    }
}
