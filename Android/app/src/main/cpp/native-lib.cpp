#include <jni.h>
#include <string>

#include <android/asset_manager_jni.h>
#include "Triangle.h"
#include "Texture2DCube.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_createInstance(JNIEnv *env, jobject thiz,
                                                                    jint id) {
    // TODO: implement createInstance()
    if (id == 0) {
        OpenGLESEngine::OpenGLESBase *engine = new OpenGLESEngine::Triangle();
        return (long) engine;
    } else if (id == 1) {
        OpenGLESEngine::OpenGLESBase *engine = new OpenGLESEngine::Texture2DCube();
        return (long) engine;
    } else {
        return NULL;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_initGL(JNIEnv *env, jobject thiz,
                                                            jlong instance) {
    // TODO: implement initGL()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    engine->prepare();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_renderFrame(JNIEnv *env, jobject thiz,
                                                                 jlong instance) {
    // TODO: implement renderFrame()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    engine->renderFrame();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_setSurface(JNIEnv *env, jobject thiz,
                                                                jlong instance, jobject surface) {
    // TODO: implement setSurface()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    uint32_t width = static_cast<uint32_t >(ANativeWindow_getWidth(window));
    uint32_t height = static_cast<uint32_t >(ANativeWindow_getHeight(window));
    engine->setWindow(window);
    engine->setWidth(width);
    engine->setHeight(height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_setAssetManager(JNIEnv *env, jobject thiz,
                                                                     jlong instance,
                                                                     jobject asset_manager) {
    // TODO: implement setAssetManager()
    auto asset = AAssetManager_fromJava(env, asset_manager);
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    if (engine) {
        engine->setAssetManager(asset);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_setTouchPos(JNIEnv *env, jobject thiz,
                                                                 jlong instance, jfloat x,
                                                                 jfloat y) {
    // TODO: implement setTouchPos()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    if (engine) {
        engine->setTouchPos(x, y);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_setTouchPosSecond(JNIEnv *env, jobject thiz,
                                                                       jlong instance, jfloat x,
                                                                       jfloat y) {
    // TODO: implement setTouchPosSecond()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    if (engine) {
        engine->setTouchPosSecond(x, y);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_setTouchMode(JNIEnv *env, jobject thiz,
                                                                  jlong instance, jint mode) {
    // TODO: implement setTouchMode()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    if (engine) {
        engine->setTouchMode(OpenGLESEngine::OpenGLESBase::TouchMode(mode));
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_resetTouch(JNIEnv *env, jobject thiz,
                                                                jlong instance) {
    // TODO: implement resetTouch()
    OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
    if (engine) {
        engine->resetTouch();
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_BaseRender_deleteGL(JNIEnv *env, jobject thiz,
                                                              jlong instance, jint id) {
    // TODO: implement deleteGL()
    if (instance) {
        if (id == 0) {
            OpenGLESEngine::Triangle *engine = reinterpret_cast<OpenGLESEngine::Triangle *>(instance);
            delete (engine);
        } else if (id == 1) {
            OpenGLESEngine::Texture2DCube *engine = reinterpret_cast<OpenGLESEngine::Texture2DCube *>(instance);
            delete (engine);
        } else {
            OpenGLESEngine::OpenGLESBase *engine = reinterpret_cast<OpenGLESEngine::OpenGLESBase *>(instance);
            delete (engine);
        }
    }
}