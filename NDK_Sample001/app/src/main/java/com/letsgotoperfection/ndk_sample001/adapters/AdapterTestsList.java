package com.letsgotoperfection.ndk_sample001.adapters;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;

import com.letsgotoperfection.ndk_sample001.R;

import java.util.ArrayList;

import static com.letsgotoperfection.ndk_sample001.R.id.btnTest;

/**
 * @author hossam.
 */

public class AdapterTestsList extends ArrayAdapter<String> {
    ArrayList<String> testsList;
    Context context;
    private OnTestViewClicked listener;

    private static class ViewHolder {
        private Button btnTest;
    }

    public interface OnTestViewClicked {
        void onTestViewClicked(int signal);
    }

    public AdapterTestsList(@NonNull Context context, ArrayList<String> testsList,
                            OnTestViewClicked onTestViewClicked) {
        super(context, -1, testsList);
        this.testsList = testsList;
        this.context = context;
        listener = onTestViewClicked;
    }


    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        ViewHolder holder;
        if (convertView == null) {
            holder = new ViewHolder();

            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context
                    .LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.item_tests_list, parent, false);
            holder.btnTest = convertView.findViewById(btnTest);
            holder.btnTest.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if (listener != null) {
                        listener.onTestViewClicked(position);
                    }
                }
            });
            convertView.setTag(holder);

        } else {
            holder = (ViewHolder) convertView.getTag();
        }

        holder.btnTest.setText(testsList.get(position));

        return convertView;
    }

}
