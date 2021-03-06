//
// Created by wjl on 20-9-6.
//

#include "OpenGLESBase.h"

BEGIN_NAMESPACE(OpenGLESEngine)

OpenGLESBase::OpenGLESBase() {

}

OpenGLESBase::~OpenGLESBase() {
    eglDestroyContext(m_display, m_context);
    eglDestroySurface(m_display, m_surface);
    eglTerminate(m_display);
    ANativeWindow_release(m_window);
    LOGI("OpenGL Destroy");
}

void OpenGLESBase::prepare() {
    prepareBase();
    prepareMyObjects();
}

void OpenGLESBase::prepareBase() {
    static EGLint const attribute_list[] = {EGL_RED_SIZE, 8,  // red
                                            EGL_GREEN_SIZE, 8,  // green
                                            EGL_BLUE_SIZE, 8,  // blue
                                            EGL_ALPHA_SIZE, 8,  // alpha
                                            EGL_DEPTH_SIZE, 16, // depth must need this!!!!
                                            EGL_STENCIL_SIZE, 8,  // stencil
                                            EGL_NONE};
    EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE, EGL_NONE};
    EGLint majorVersion;
    EGLint minorVersion;

    /* get an EGL display connection */
    m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    /* initialize the EGL display connection */
    eglInitialize(m_display, &majorVersion, &minorVersion);
    /* get an appropriate EGL frame buffer configuration */
    eglChooseConfig(m_display, attribute_list, &m_config, 1, &m_numConfig);
    /* create an EGL rendering context */
    m_context = eglCreateContext(m_display, m_config, EGL_NO_CONTEXT, contextAttribs);
    /* create an EGL window surface */
    m_surface = eglCreateWindowSurface(m_display, m_config, m_window, NULL);

    if (m_surface == EGL_NO_SURFACE) {
        LOGI("No Surface Error.");
    }

    //m_context = eglCreateContext(m_display, m_config, EGL_NO_CONTEXT, contextAttribs);
    if (m_context == EGL_NO_CONTEXT) {
        LOGI("error eglCreateContext.");
    }
    eglMakeCurrent(m_display, m_surface, m_surface, m_context);

    LOGI("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
    LOGI("GL_VERSION: %s\n", glGetString(GL_VERSION));
    LOGI("GL_SHADING_LANGUAGE_VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void OpenGLESBase::renderLoop() {
    while (m_quit) {
        renderFrame();
    }
}

void OpenGLESBase::renderFrame() {
    if(m_pause) return;
    render();
    auto result = eglSwapBuffers(m_display, m_surface);
    if(!result){
        destroySurface();
        rebuildSurface();
    }
}

void OpenGLESBase::render() {}

void OpenGLESBase::defaultTouchOperation() {
    if (m_touchMode == TouchMode::SINGLE) {
        if (m_mousePosOld[0].x == 0 and m_mousePosOld[0].y == 0) {
            m_mousePosOld[0].x = m_mousePos[0].x;
            m_mousePosOld[0].y = m_mousePos[0].y;
        }
    } else if (m_touchMode == TouchMode::DOUBLE) {
        float distance =
                (m_mousePos[1].x - m_mousePos[0].x) * (m_mousePos[1].x - m_mousePos[0].x) +
                (m_mousePos[1].y - m_mousePos[0].y) * (m_mousePos[1].y - m_mousePos[0].y);
        if (m_oldDistance == 0.f) { m_oldDistance = distance; }
        else {
            if (distance > m_oldDistance) { m_distance += 0.1f; }
            else if (distance < m_oldDistance) { m_distance -= 0.1f; }
        }
        m_oldDistance = distance;
    }
}

void OpenGLESBase::destroySurface() {
    eglDestroySurface(m_display, m_surface);
}

void OpenGLESBase::rebuildSurface() {
    if(!m_window) return;
    m_surface = eglCreateWindowSurface(m_display, m_config, m_window, NULL);

    if (m_surface == EGL_NO_SURFACE) {
        LOGI("No Surface Error.");
    }
    eglMakeCurrent(m_display, m_surface, m_surface, m_context);
    resume();
}

END_NAMESPACE(OpenGLESEngine)