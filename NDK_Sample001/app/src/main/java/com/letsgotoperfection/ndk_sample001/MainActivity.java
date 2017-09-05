package com.letsgotoperfection.ndk_sample001;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ListView;
import android.widget.Toast;

import com.letsgotoperfection.ndk_sample001.adapters.AdapterTestsList;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements AdapterTestsList.OnTestViewClicked {
    ArrayList<String> testsList;
    ListView testsListView;
    AdapterTestsList adapterTestsList;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("algorithms");
    }

//    Button btnCalculateSum;
//    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
        // Example of a call to a native method
//        tv = (TextView) findViewById(R.id.sample_text);
//        btnCalculateSum = (Button) findViewById(R.id.btnCalculateSum);
//        btnCalculateSum.setOnClickListener(this);
//        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int calculateSumJNI();

//    @Override
//    public void onClick(View view) {
//        if (view.getId() == btnCalculateSum.getId()) {
//            try {
//                String x = "The sum is equals to = " + calculateSumJNI();
//                tv.setText(x);
//            } catch (Exception e) {
//                Instabug.reportException(e);
//            }
//        }
//    }

    void init() {
        testsList = new ArrayList<>();
        testsListView = (ListView) findViewById(R.id.testsList);

        for (int i = 1; i <= 31; i++) {
            testsList.add("Throw  " + i + "  Signal");
        }

        adapterTestsList = new AdapterTestsList(this, testsList, this);
        testsListView.setAdapter(adapterTestsList);


//        testsListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
//
//            @Override
//            public void onItemClick(AdapterView<?> parent, final View view,
//                                    int position, long id) {
//                String itemData = testsList.get(position);
//                Toast.makeText(MainActivity.this, itemData, Toast.LENGTH_LONG).show();
////                if (position == 6) {
////                    calculateSumJNI();
////                }
//            }
//        });
    }

    @Override
    public void onTestViewClicked(int signal) {
        String itemData = testsList.get(signal);
        Toast.makeText(MainActivity.this, itemData, Toast.LENGTH_LONG).show();
        raiseSignal(signal);
//        if (signal == 6) {
//            calculateSumJNI();
//        }
    }

    public native void raiseSignal(int signal);
}
