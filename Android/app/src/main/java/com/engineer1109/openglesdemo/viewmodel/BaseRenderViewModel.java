package com.engineer1109.openglesdemo.viewmodel;

import android.view.Surface;

import androidx.lifecycle.ViewModel;

import com.engineer1109.openglesdemo.render.OpenGLESRender;

public class BaseRenderViewModel extends ViewModel {
    private OpenGLESRender mRender = new OpenGLESRender();

    public void setSurface(Surface surface) {
        mRender.setSurface(surface);
    }

    public void render() {
        mRender.render();
    }
}
