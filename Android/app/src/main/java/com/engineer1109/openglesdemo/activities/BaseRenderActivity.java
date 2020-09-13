package com.engineer1109.openglesdemo.activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;

import android.os.Bundle;

import com.engineer1109.openglesdemo.databinding.ActivityBaseRenderBinding;
import com.engineer1109.openglesdemo.databinding.ActivityMainBinding;
import com.engineer1109.openglesdemo.viewmodel.BaseRenderViewModel;
import com.engineer1109.openglesdemo.viewmodel.MainViewModel;

public class BaseRenderActivity extends AppCompatActivity {
    static final String TAG = "BaseRenderActivity";

    private ActivityBaseRenderBinding mBinding = null;

    private BaseRenderViewModel mViewModel = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding= ActivityBaseRenderBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());

        mViewModel = new ViewModelProvider(this).get(BaseRenderViewModel.class);
        mBinding.setBaseRenderViewModel(mViewModel);
    }
}