#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#include "keycodes.h"
#include "opengles_imgui.h"
#include "openglesbase.h"
OpenGLESBase::OpenGLESBase(){
    imgui=new ImguiOverlay();
#ifdef OPENGLES_USE_XCB
    initxcbConnection();
#endif
}

OpenGLESBase::~OpenGLESBase(){
    if(imgui){
        delete imgui;
        imgui=nullptr;
    }
}

void OpenGLESBase::initWindow(){
    setupWindow();
}

void OpenGLESBase::prepare(){
    static EGLint const attribute_list[] = {
            EGL_RED_SIZE, 1,
            EGL_GREEN_SIZE, 1,
            EGL_BLUE_SIZE, 1,
            EGL_NONE
    };

    /* get an EGL display connection */
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    /* initialize the EGL display connection */
    eglInitialize(display, NULL, NULL);
    /* get an appropriate EGL frame buffer configuration */
    eglChooseConfig(display, attribute_list, &config, 1, &num_config);
    /* create an EGL rendering context */
    context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
    /* create a native window */
    native_window = this->window;
    /* create an EGL window surface */
    surface = eglCreateWindowSurface(display, config, native_window, NULL);
    /* connect the context to the surface */
    eglMakeCurrent(display, surface, surface, context);

    imgui->init();
}

void OpenGLESBase::renderLoop(){
#ifdef OPENGLES_USE_XCB
    xcb_flush(connection);
#endif
    while(!m_quit){
        auto tStart = std::chrono::high_resolution_clock::now();
        if (viewUpdated)
        {
            viewUpdated = false;
            viewChanged();
        }
        xcb_generic_event_t *event;
        while ((event = xcb_poll_for_event(connection)))
        {
            handleEvent(event);
            free(event);
        }
        render();

        frameCounter++;
        auto tEnd = std::chrono::high_resolution_clock::now();
        auto tDiff = std::chrono::duration<double, std::milli>(tEnd - tStart).count();
        frameTimer = tDiff / 1000.0f;
        camera.update(frameTimer);
        if (camera.moving())
        {
            viewUpdated = true;
        }
        imgui->render();

        eglSwapBuffers(display, surface);
    }
}

void OpenGLESBase::render(){

}

void OpenGLESBase::handleMouseMove(int32_t x, int32_t y)
{
    int32_t dx = (int32_t)mousePos.x - x;
    int32_t dy = (int32_t)mousePos.y - y;

    bool handled = false;

//    if (settings.overlay) {
//        ImGuiIO& io = ImGui::GetIO();
//        handled = io.WantCaptureMouse;
//    }
    mouseMoved((float)x, (float)y, handled);

    if (handled) {
        mousePos = glm::vec2((float)x, (float)y);
        return;
    }

    if (mouseButtons.left) {
        rotation.x += dy * 1.25f * rotationSpeed;
        rotation.y -= dx * 1.25f * rotationSpeed;
        camera.rotate(glm::vec3(dy * camera.rotationSpeed, -dx * camera.rotationSpeed, 0.0f));
        viewUpdated = true;
    }
    if (mouseButtons.right) {
        zoom += dy * .005f * zoomSpeed;
        camera.translate(glm::vec3(-0.0f, 0.0f, dy * .005f * zoomSpeed));
        viewUpdated = true;
    }
    if (mouseButtons.middle) {
        cameraPos.x -= dx * 0.01f;
        cameraPos.y -= dy * 0.01f;
        camera.translate(glm::vec3(-dx * 0.01f, -dy * 0.01f, 0.0f));
        viewUpdated = true;
    }
    mousePos = glm::vec2((float)x, (float)y);
}

#ifdef OPENGLES_USE_XCB
static inline xcb_intern_atom_reply_t* intern_atom_helper(xcb_connection_t *conn, bool only_if_exists, const char *str)
{
    xcb_intern_atom_cookie_t cookie = xcb_intern_atom(conn, only_if_exists, strlen(str), str);
    return xcb_intern_atom_reply(conn, cookie, NULL);
}

void OpenGLESBase::setupWindow(){
    uint32_t value_mask, value_list[32];

        window = xcb_generate_id(connection);

        value_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
        value_list[0] = screen->black_pixel;
        value_list[1] =
            XCB_EVENT_MASK_KEY_RELEASE |
            XCB_EVENT_MASK_KEY_PRESS |
            XCB_EVENT_MASK_EXPOSURE |
            XCB_EVENT_MASK_STRUCTURE_NOTIFY |
            XCB_EVENT_MASK_POINTER_MOTION |
            XCB_EVENT_MASK_BUTTON_PRESS |
            XCB_EVENT_MASK_BUTTON_RELEASE;

        if (settings.fullscreen)
        {
            width = destWidth = screen->width_in_pixels;
            height = destHeight = screen->height_in_pixels;
        }

        xcb_create_window(connection,
            XCB_COPY_FROM_PARENT,
            window, screen->root,
            0, 0, width, height, 0,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            screen->root_visual,
            value_mask, value_list);

        /* Magic code that will send notification when window is destroyed */
        xcb_intern_atom_reply_t* reply = intern_atom_helper(connection, true, "WM_PROTOCOLS");
        atom_wm_delete_window = intern_atom_helper(connection, false, "WM_DELETE_WINDOW");

        xcb_change_property(connection, XCB_PROP_MODE_REPLACE,
            window, (*reply).atom, 4, 32, 1,
            &(*atom_wm_delete_window).atom);

        std::string windowTitle = getWindowTitle();
        xcb_change_property(connection, XCB_PROP_MODE_REPLACE,
            window, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
            title.size(), windowTitle.c_str());

        free(reply);

        if (settings.fullscreen)
        {
            xcb_intern_atom_reply_t *atom_wm_state = intern_atom_helper(connection, false, "_NET_WM_STATE");
            xcb_intern_atom_reply_t *atom_wm_fullscreen = intern_atom_helper(connection, false, "_NET_WM_STATE_FULLSCREEN");
            xcb_change_property(connection,
                    XCB_PROP_MODE_REPLACE,
                    window, atom_wm_state->atom,
                    XCB_ATOM_ATOM, 32, 1,
                    &(atom_wm_fullscreen->atom));
            free(atom_wm_fullscreen);
            free(atom_wm_state);
        }

        xcb_map_window(connection, window);

        return;
}

void OpenGLESBase::initxcbConnection(){
    const xcb_setup_t *setup;
    xcb_screen_iterator_t iter;
    int scr;

    connection = xcb_connect(NULL, &scr);
    if (connection == NULL) {
        printf("Could not find a compatible OpenGLES ICD!\n");
        fflush(stdout);
        exit(1);
    }

    setup = xcb_get_setup(connection);
    iter = xcb_setup_roots_iterator(setup);
    while (scr-- > 0)
        xcb_screen_next(&iter);
    screen = iter.data;
}

void OpenGLESBase::handleEvent(const xcb_generic_event_t *event)
{
    switch (event->response_type & 0x7f)
    {
    case XCB_CLIENT_MESSAGE:
        if ((*(xcb_client_message_event_t*)event).data.data32[0] ==
            (*atom_wm_delete_window).atom) {
            m_quit = true;
        }
        break;
    case XCB_MOTION_NOTIFY:
    {
        xcb_motion_notify_event_t *motion = (xcb_motion_notify_event_t *)event;
        handleMouseMove((int32_t)motion->event_x, (int32_t)motion->event_y);
        break;
    }
    break;
    case XCB_BUTTON_PRESS:
    {
        xcb_button_press_event_t *press = (xcb_button_press_event_t *)event;
        if (press->detail == XCB_BUTTON_INDEX_1)
            mouseButtons.left = true;
        if (press->detail == XCB_BUTTON_INDEX_2)
            mouseButtons.middle = true;
        if (press->detail == XCB_BUTTON_INDEX_3)
            mouseButtons.right = true;
        if (press->detail == XCB_BUTTON_INDEX_4)
            mouseWheel.up = true;
        if (press->detail == XCB_BUTTON_INDEX_5)
            mouseWheel.down = true;
    }
    break;
    case XCB_BUTTON_RELEASE:
    {
        xcb_button_press_event_t *press = (xcb_button_press_event_t *)event;
        if (press->detail == XCB_BUTTON_INDEX_1)
            mouseButtons.left = false;
        if (press->detail == XCB_BUTTON_INDEX_2)
            mouseButtons.middle = false;
        if (press->detail == XCB_BUTTON_INDEX_3)
            mouseButtons.right = false;
        if (press->detail == XCB_BUTTON_INDEX_4)
            mouseWheel.up = false;
        if (press->detail == XCB_BUTTON_INDEX_5)
            mouseWheel.down = false;
    }
    break;
    case XCB_KEY_PRESS:
    {
        const xcb_key_release_event_t *keyEvent = (const xcb_key_release_event_t *)event;
        switch (keyEvent->detail)
        {
            case KEY_W:
                camera.keys.up = true;
                break;
            case KEY_S:
                camera.keys.down = true;
                break;
            case KEY_A:
                camera.keys.left = true;
                break;
            case KEY_D:
                camera.keys.right = true;
                break;
            case KEY_P:
                paused = !paused;
                break;
            case KEY_F1:
                if (settings.overlay) {
                    settings.overlay = !settings.overlay;
                }
                break;
        }
    }
    break;
    case XCB_KEY_RELEASE:
    {
        const xcb_key_release_event_t *keyEvent = (const xcb_key_release_event_t *)event;
        switch (keyEvent->detail)
        {
            case KEY_W:
                camera.keys.up = false;
                break;
            case KEY_S:
                camera.keys.down = false;
                break;
            case KEY_A:
                camera.keys.left = false;
                break;
            case KEY_D:
                camera.keys.right = false;
                break;
            case KEY_ESCAPE:
                m_quit = true;
                break;
        }
        keyPressed(keyEvent->detail);
    }
    break;
    case XCB_DESTROY_NOTIFY:
        m_quit = true;
        break;
    case XCB_CONFIGURE_NOTIFY:
    {
        const xcb_configure_notify_event_t *cfgEvent = (const xcb_configure_notify_event_t *)event;
        if ((prepared) && ((cfgEvent->width != width) || (cfgEvent->height != height)))
        {
                destWidth = cfgEvent->width;
                destHeight = cfgEvent->height;
                if ((destWidth > 0) && (destHeight > 0))
                {
                    windowResize();
                }
        }
    }
    break;
    default:
        break;
    }
}
#endif
