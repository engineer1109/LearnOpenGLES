package com.engineer1109.openglesdemo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;

import android.os.Bundle;

import com.engineer1109.openglesdemo.viewmodel.MainViewModel;
import com.engineer1109.openglesdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    static final String TAG = "MainActivity";

    private ActivityMainBinding mBinding = null;

    private MainViewModel mMainViewModel = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());

        mMainViewModel = new ViewModelProvider(this).get(MainViewModel.class);
        mBinding.setMainViewModel(mMainViewModel);
        mMainViewModel.setBinding(mBinding);
        mMainViewModel.showMenu(mBinding.rcMenu);

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
}
