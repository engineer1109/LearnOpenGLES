package com.engineer1109.openglesdemo.viewmodel;

import android.content.res.AssetManager;
import android.view.Surface;

import androidx.lifecycle.ViewModel;

import com.engineer1109.openglesdemo.render.BaseRender;

public class BaseRenderViewModel extends ViewModel {
    private BaseRender mRender = new BaseRender();

    private int mTouchMode = 0;

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

    public void setTouchPos(float x, float y){}

    public void setTouchPosSecond(float x, float y){}

    public void setTouchMode(int mode){ mTouchMode = mode;}

    public int getTouchMode() {return mTouchMode;}

    public void resetTouch(){}

    public int getRenderStatus() {return 1;}
}
