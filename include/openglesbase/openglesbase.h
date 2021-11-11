/*
* LearnOpenGLES Examples
*
* Copyright (C) by engineer1109 - https://github.com/engineer1109/LearnOpenGLES
*
* This code is licensed under GNU General Public License v3.0  (GPL-3.0) (https://opensource.org/licenses/GPL-3.0)
*/
#ifndef OPENGLESBASE_H
#define OPENGLESBASE_H

#include <string.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <GLES3/gl3.h>
#include <EGL/egl.h>

#ifdef OPENGLES_USE_XCB
#include <xcb/xcb.h>
#endif
#ifdef OPENGLES_USE_WIN32
#pragma comment(linker, "/subsystem:console")
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <ShellScalingAPI.h>
#endif

#include "camera.h"
#include "opengles_imgui.h"
#include "openglesbase_export.h"

class OPENGLESBASE_EXPORT OpenGLESBase{
public:
    OpenGLESBase();
    virtual ~OpenGLESBase();

    virtual void initWindow();
    virtual void prepare();
    virtual void prepareBase();
    virtual void renderLoop();
    virtual void render();
    virtual void updateOverlay();
    virtual void OnUpdateUIOverlay(ImguiOverlay* overlay);

    virtual void renderAsyncThread();
    virtual void renderJoin();
    virtual void renderPlugin(){}

    //Custom Event Function
    virtual void windowResize();
    virtual void windowResized(){}
    virtual void viewChanged() {}
    virtual void keyPressed(uint32_t) {}
    virtual void mouseMoved(double x, double y, bool & handled) {}

    void handleMouseMove(int32_t x, int32_t y);

    std::string getWindowTitle(){return title;}

#ifdef OPENGLES_USE_XCB
    xcb_window_t getWindowHandle(){return window;}
    void setWindowHandle(xcb_window_t winID){window=winID;}
#endif
#ifdef OPENGLES_USE_WIN32
	void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif

private:
    void setupWindow();

#ifdef OPENGLES_USE_XCB
    void initxcbConnection();
    void handleEvent(const xcb_generic_event_t *event);
#endif
public:
    struct Settings {
            /** @brief Set to true if fullscreen mode has been requested via command line */
            bool fullscreen = false;
            /** @brief Set to true if v-sync will be forced for the swapchain */
            bool vsync = false;
            /** @brief Enable UI overlay */
            bool overlay = true;
        } settings;
    struct {
        bool left = false;
        bool right = false;
        bool middle = false;
    } mouseButtons;
    struct {
        bool up=false;
        bool down=false;
    } mouseWheel;

    Camera camera;
    glm::vec3 rotation = glm::vec3();
    glm::vec3 cameraPos = glm::vec3();
    glm::vec2 mousePos;

    std::string title = "OpenGLES Example";
    std::string name = "OpenGLES Example";
    uint32_t width = 1280;
    uint32_t height = 720;
    uint32_t destWidth=0;
    uint32_t destHeight=0;
    bool prepared=false;
    bool paused = false;
    bool viewUpdated=false;

    // Use to adjust mouse rotation speed
    float rotationSpeed = 1.0f;
    // Use to adjust mouse zoom speed
    float zoomSpeed = 1.0f;
    float zoom = 0;

    uint32_t frameCounter=0;
    float frameTimer = 1.0f;
	bool enableWindow = true;
	bool resizing = false;

	std::chrono::time_point<std::chrono::high_resolution_clock> lastTimestamp;
	uint32_t lastFPS = 0;
	float timer = 0.0f;
	float timerSpeed = 0.25f;
protected:
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
#ifdef OPENGLES_USE_WIN32
    HWND window;
	HINSTANCE windowInstance;
#endif

    ImguiOverlay* imgui;
    std::thread* m_thread=nullptr;
};
#endif
