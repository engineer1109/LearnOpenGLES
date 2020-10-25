package com.engineer1109.openglesdemo.viewmodel;

import android.content.res.AssetManager;
import android.view.Surface;

import androidx.lifecycle.ViewModel;

import com.engineer1109.openglesdemo.render.BaseRender;

public class BaseRenderViewModel extends ViewModel {
    private BaseRender mRender = new BaseRender();

    public void init(int id) {
        mRender.init(id);
    }

    public void setSurface(Surface surface) {
        mRender.setSurface(surface);
    }

    public void setAssetManager(AssetManager assetManager) {
        mRender.setAssetManager(assetManager);
    }

    public void render() {
        mRender.render();
    }
}
