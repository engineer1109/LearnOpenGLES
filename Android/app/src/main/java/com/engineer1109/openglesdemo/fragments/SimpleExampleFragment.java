package com.engineer1109.openglesdemo.fragments;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.engineer1109.openglesdemo.R;
import com.engineer1109.openglesdemo.databinding.FragmentSimpleExampleBinding;
import com.engineer1109.openglesdemo.viewmodel.MainViewModel;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link SimpleExampleFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class SimpleExampleFragment extends Fragment {

    private FragmentSimpleExampleBinding mBinding = null;

    private MainViewModel mMainViewModel = null;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        mBinding = FragmentSimpleExampleBinding.inflate(inflater, container, false);
        mMainViewModel = new ViewModelProvider(this).get(MainViewModel.class);
        mBinding.setMainViewModel(mMainViewModel);
        mBinding.btnTriangle.bringToFront();
        return mBinding.getRoot();
    }
}