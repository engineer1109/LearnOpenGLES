//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESBASE_H
#define OPENGLESTEST_OPENGLESBASE_H

#include "render_common.h"

BEGIN_NAMESPACE(OpenGLESEngine)

class OpenGLESBase {
public:
    OpenGLESBase();
    ~OpenGLESBase();

    void setWindow(ANativeWindow* window){m_window=window;}
    void setWidth(const uint32_t &width){m_width=width;}
    void setHeight(const uint32_t &height){m_height=height;}

    void setAssetManager(AAssetManager* asset){m_asset=asset;}

    virtual void prepare();
    virtual void prepareBase();
    virtual void renderLoop();
    virtual void renderFrame();
    virtual void render();

protected:
    ANativeWindow* m_window = nullptr;
    AAssetManager* m_asset = nullptr;
    uint32_t m_width = 1280;
    uint32_t m_height = 720;

    EGLDisplay m_display;
    EGLConfig m_config;
    EGLContext m_context;
    EGLSurface m_surface;
    EGLint m_numConfig;

    bool m_quit=false;
};

END_NAMESPACE(OpenGLESEngine)
#endif //OPENGLESTEST_OPENGLESBASE_H
