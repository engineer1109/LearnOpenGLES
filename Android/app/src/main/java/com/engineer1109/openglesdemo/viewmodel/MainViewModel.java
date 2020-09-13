package com.engineer1109.openglesdemo.viewmodel;

import android.content.Intent;
import android.view.Surface;
import android.view.View;

import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.lifecycle.ViewModel;

import com.engineer1109.openglesdemo.R;
import com.engineer1109.openglesdemo.activities.BaseRenderActivity;
import com.engineer1109.openglesdemo.fragments.SimpleExampleFragment;
import com.engineer1109.openglesdemo.render.OpenGLESRender;

public class MainViewModel extends ViewModel {
    private FragmentManager mFragmentManager = null;

    public void setFragmentManager(FragmentManager fragmentManager){mFragmentManager=fragmentManager;}

    public void showPage1st(View view){
        FragmentTransaction transaction = mFragmentManager.beginTransaction();
        SimpleExampleFragment simpleExampleFragment = (SimpleExampleFragment) mFragmentManager.findFragmentById(R.id.fragment_page1st);
        transaction.show(simpleExampleFragment);
        transaction.commit();
    }

    public void showTriangleRender(View view){
        Intent intent = new Intent(view.getContext(), BaseRenderActivity.class);
        view.getContext().startActivity(intent);
    }
}
