#include <jni.h>
#include <string>

#include "OpenGLESRender.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_engineer1109_openglesdemo_render_OpenGLESRender_createInstance(JNIEnv *env, jobject thiz) {
    // TODO: implement createInstance()
    OpenGLESEngine::OpenGLESRender* engine= new OpenGLESEngine::OpenGLESRender();
    return (long)engine;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_OpenGLESRender_initGL(JNIEnv *env, jobject thiz,
                                                           jlong instance) {
    // TODO: implement initGL()
    OpenGLESEngine::OpenGLESRender* engine= reinterpret_cast<OpenGLESEngine::OpenGLESRender *>(instance);
    engine->prepare();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_OpenGLESRender_renderFrame(JNIEnv *env, jobject thiz,
                                                                jlong instance) {
    // TODO: implement renderFrame()
    OpenGLESEngine::OpenGLESRender* engine= reinterpret_cast<OpenGLESEngine::OpenGLESRender *>(instance);
    engine->renderFrame();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_engineer1109_openglesdemo_render_OpenGLESRender_setSurface(JNIEnv *env, jobject thiz,
                                                               jlong instance, jobject surface) {
    // TODO: implement setSurface()
    OpenGLESEngine::OpenGLESRender* engine= reinterpret_cast<OpenGLESEngine::OpenGLESRender *>(instance);
    ANativeWindow* window = ANativeWindow_fromSurface(env,surface);
    uint32_t width = static_cast<uint32_t >(ANativeWindow_getWidth(window));
    uint32_t height = static_cast<uint32_t >(ANativeWindow_getHeight(window));
    engine->setWindow(window);
    engine->setWidth(width);
    engine->setHeight(height);
}