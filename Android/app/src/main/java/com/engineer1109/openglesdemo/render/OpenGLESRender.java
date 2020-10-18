package com.engineer1109.openglesdemo.render;

import android.content.res.AssetManager;
import android.view.Surface;

public class OpenGLESRender {
    static {
        System.loadLibrary("native-lib");
    }

    static final String TAG="OpenGLESRender";

    private long mInstance=0;

    class RenderThread extends Thread {
        @Override
        public void run(){
            initGL(mInstance);
            while(true){
                renderFrame(mInstance);
            }
        }
    }

    private RenderThread mThread;

    public OpenGLESRender(){
        mInstance=createInstance();
    }

    public void setSurface(Surface surface){setSurface(mInstance,surface);}

    public void setAssetManager(AssetManager assetManager){
        setAssetManager(mInstance, assetManager);
    }

    public void render(){
        mThread=new RenderThread();
        mThread.start();
    }

    public native long createInstance();
    public native void initGL(long instance);
    public native void renderFrame(long instance);
    public native void setSurface(long instance,Surface surface);
    public native void setAssetManager(long instance, AssetManager assetManager);
}
