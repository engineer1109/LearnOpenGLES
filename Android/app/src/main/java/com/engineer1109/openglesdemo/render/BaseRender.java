package com.engineer1109.openglesdemo.render;

import android.content.res.AssetManager;
import android.util.Log;
import android.view.Surface;

public class BaseRender {
    static {
        System.loadLibrary("BaseRender");
    }

    static final String TAG = "OpenGLESRender";

    private int mID = 0;

    private long mInstance = 0;

    private boolean mQuit = false;

    private boolean mStarted = false;

    class RenderThread extends Thread {
        @Override
        public void run() {
            mStarted = true;
            initGL(mInstance);
            while (mQuit == false) {
                renderFrame(mInstance);
            }
            deleteGL(mInstance, mID);
            mInstance = 0;
            Log.i(TAG, "Finish Render");
        }
    }

    private RenderThread mThread;

    public BaseRender() {
    }

    public void init(int id) {
        mID = id;
        mInstance = createInstance(mID);
    }

    public void setSurface(Surface surface) {
        setSurface(mInstance, surface);
    }

    public void setAssetManager(AssetManager assetManager) {
        setAssetManager(mInstance, assetManager);
    }

    public void render() {
        mThread = new RenderThread();
        mThread.start();
    }

    public void setTouchPos(float x, float y) {
        setTouchPos(mInstance, x, y);
    }

    public void setTouchPosSecond(float x, float y) {
        setTouchPosSecond(mInstance, x, y);
    }

    public void setTouchMode(int mode) {
        setTouchMode(mInstance, mode);
    }

    public void resetTouch() {
        resetTouch(mInstance);
    }

    public void quit() {
        mQuit = true;
    }

    public long getInstance() {
        return mInstance;
    }

    public boolean isStarted() {
        return mStarted;
    }

    public void destroySurface(){
        destroySurface(mInstance);
    }

    public void rebuildSurface(){
        rebuildSurface(mInstance);
    }

    public void resume() {
        resume(mInstance);
    }

    public void pause() {
        pause(mInstance);
    }

    //public native long createInstance();

    public native long createInstance(int id);

    public native void initGL(long instance);

    public native void renderFrame(long instance);

    public native void setSurface(long instance, Surface surface);

    public native void setAssetManager(long instance, AssetManager assetManager);

    public native void setTouchPos(long instance, float x, float y);

    public native void setTouchPosSecond(long instance, float x, float y);

    public native void setTouchMode(long instance, int mode);

    public native void resetTouch(long instance);

    public native void deleteGL(long instance, int id);

    public native void destroySurface(long instance);

    public native void rebuildSurface(long instance);

    public native void pause(long instance);

    public native void resume(long instance);
}
