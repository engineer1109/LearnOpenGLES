#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "openglesbase.h"
OpenGLESBase::OpenGLESBase(){
#ifdef OPENGLES_USE_XCB
    initxcbConnection();
#endif
}

OpenGLESBase::~OpenGLESBase(){

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
}

void OpenGLESBase::renderLoop(){
#ifdef OPENGLES_USE_XCB
    xcb_flush(connection);
#endif
    while(!m_quit){
        render();
        eglSwapBuffers(display, surface);
    }
}

void OpenGLESBase::render(){

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
#endif
