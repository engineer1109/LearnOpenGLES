package com.engineer1109.openglesdemo.render;

import android.content.res.AssetManager;
import android.view.Surface;

public class BaseRender {
    static {
        System.loadLibrary("BaseRender");
    }

    static final String TAG = "OpenGLESRender";

    private int mID = 0;

    private long mInstance = 0;

    class RenderThread extends Thread {
        @Override
        public void run() {
            initGL(mInstance);
            while (true) {
                renderFrame(mInstance);
            }
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

    //public native long createInstance();

    public native long createInstance(int id);

    public native void initGL(long instance);

    public native void renderFrame(long instance);

    public native void setSurface(long instance, Surface surface);

    public native void setAssetManager(long instance, AssetManager assetManager);
}
