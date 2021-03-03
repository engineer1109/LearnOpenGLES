//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESBASE_H
#define OPENGLESTEST_OPENGLESBASE_H

#include "render_common.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

BEGIN_NAMESPACE(OpenGLESEngine)

class OpenGLESBase {
public:
    enum class TouchMode{
        NONE = 0,
        SINGLE = 1,
        DOUBLE = 2,
    };
public:
    OpenGLESBase();

    ~OpenGLESBase();

    void setWindow(ANativeWindow *window) { m_window = window; }

    void setWidth(const uint32_t &width) { m_width = width; }

    void setHeight(const uint32_t &height) { m_height = height; }

    void setAssetManager(AAssetManager *asset) { m_asset = asset; }

    virtual void prepare();

    virtual void prepareBase();

    virtual void renderLoop();

    virtual void renderFrame();

    virtual void render();

    virtual void defaultTouchOperation();

    void destroySurface();

    void rebuildSurface();

    void setTouchPos(const float &x, const float &y){
        m_mousePos[0] = {x, y};
    }

    void setTouchPosSecond(const float &x, const float &y){
        m_mousePos[1] = {x, y};
    }

    void setTouchMode(TouchMode mode){
        m_touchMode = mode;
    }

    void resetTouch(){
        m_mousePos[0] = {0.f,0.f};
        m_mousePos[1] = {0.f,0.f};
        m_mousePosOld[0] = {0.f,0.f};
        m_mousePosOld[1] = {0.f,0.f};
        m_touchMode = TouchMode::NONE;
    }

    void resume(){
        m_pause = false;
    }

    void pause(){
        m_pause = true;
    }

protected:
    ANativeWindow *m_window = nullptr;
    AAssetManager *m_asset = nullptr;
    uint32_t m_width = 1280;
    uint32_t m_height = 720;

    EGLDisplay m_display;
    EGLConfig m_config;
    EGLContext m_context;
    EGLSurface m_surface;
    EGLint m_numConfig;

    bool m_quit = false;
    bool m_pause = false;

    glm::vec2 m_mousePos[2];
    glm::vec2 m_mousePosOld[2];
    TouchMode m_touchMode = TouchMode::NONE;

    float m_distance = 0.f;
    float m_oldDistance = 0.f;
};

END_NAMESPACE(OpenGLESEngine)
#endif //OPENGLESTEST_OPENGLESBASE_H
