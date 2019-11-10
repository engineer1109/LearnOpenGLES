#ifndef OPENGLESBASE_H
#define OPENGLESBASE_H

#include <string.h>
#include <iostream>
#include <GLES3/gl3.h>
#include <EGL/egl.h>

#ifdef OPENGLES_USE_XCB
#include <xcb/xcb.h>
#endif

#include "openglesbase_def.h"
class OPENGLESBASE_EXPORT OpenGLESBase{
public:
    OpenGLESBase();
    ~OpenGLESBase();

    virtual void initWindow();
    virtual void prepare();
    virtual void renderLoop();
    virtual void render();

    std::string getWindowTitle(){return title;}

#ifdef OPENGLES_USE_XCB
    xcb_window_t getWindowPtr(){return window;}
#endif
private:
    void setupWindow();
#ifdef OPENGLES_USE_XCB
    void initxcbConnection();
#endif
public:
    struct Settings {
            /** @brief Set to true if fullscreen mode has been requested via command line */
            bool fullscreen = false;
            /** @brief Set to true if v-sync will be forced for the swapchain */
            bool vsync = false;
            /** @brief Enable UI overlay */
            bool overlay = false;
        } settings;
    std::string title = "OpenGLES Example";
    std::string name = "OpenGLES Example";
    uint32_t width = 1280;
    uint32_t height = 720;
    uint32_t destWidth=0;
    uint32_t destHeight=0;
    bool prepared=false;
private:
    bool m_quit=false;
    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;
    NativeWindowType native_window;
    EGLint num_config;
#ifdef OPENGLES_USE_XCB
    xcb_connection_t *connection;
    xcb_screen_t *screen;
    xcb_window_t window;
    xcb_intern_atom_reply_t *atom_wm_delete_window;
#endif
#ifdef WIN32UI
    HWND window;
#endif
};
#endif
