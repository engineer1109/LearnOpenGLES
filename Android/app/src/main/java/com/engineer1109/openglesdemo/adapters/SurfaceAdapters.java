package com.engineer1109.openglesdemo.adapters;

import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.databinding.BindingAdapter;

import com.engineer1109.openglesdemo.viewmodel.BaseRenderViewModel;
import com.engineer1109.openglesdemo.viewmodel.MainViewModel;

public class SurfaceAdapters {
    @BindingAdapter("android:surfaceViewCallback")
    public static void setSurfaceViewCallback(final SurfaceView view, final BaseRenderViewModel viewModel) {
        view.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(@NonNull SurfaceHolder surfaceHolder) {

            }

            @Override
            public void surfaceChanged(@NonNull SurfaceHolder surfaceHolder, int i, int i1, int i2) {
                viewModel.setSurface(view.getHolder().getSurface());
                viewModel.setAssetManager(view.getContext().getAssets());
                viewModel.render();
            }

            @Override
            public void surfaceDestroyed(@NonNull SurfaceHolder surfaceHolder) {

            }
        });
    }
}
