package com.engineer1109.openglesdemo;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import androidx.lifecycle.ViewModelProviders;

import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.widget.TextView;

import com.engineer1109.openglesdemo.fragments.SimpleExampleFragment;
import com.engineer1109.openglesdemo.viewmodel.MainViewModel;
import com.engineer1109.openglesdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    static final String TAG="MainActivity";

    private ActivityMainBinding mBinding = null;

    private MainViewModel mMainViewModel = null;

    private FragmentManager mFragmentManager = null;

    private SimpleExampleFragment mSimpleExampleFragment = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding=ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());

        mMainViewModel = new ViewModelProvider(this).get(MainViewModel.class);
        mBinding.setMainViewModel(mMainViewModel);

        mFragmentManager = getSupportFragmentManager();
        mBinding.setFragmentManager(mFragmentManager);
        mMainViewModel.setFragmentManager(mFragmentManager);

//        mBinding.fragmentPage1st.bringChildToFront(mSimpleExampleFragment.mB);

//        FragmentTransaction transaction = mFragmentManager.beginTransaction();
//        mSimpleExampleFragment = (SimpleExampleFragment) mFragmentManager.findFragmentById(R.id.fragment_page1st);
//        transaction.hide(mSimpleExampleFragment);
//        transaction.commit();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
}
