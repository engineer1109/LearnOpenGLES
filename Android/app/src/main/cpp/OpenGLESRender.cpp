//
// Created by wjl on 20-9-6.
//

#include "OpenGLESRender.h"
BEGIN_NAMESPACE(OpenGLESEngine)
OpenGLESRender::OpenGLESRender(){}

OpenGLESRender::~OpenGLESRender() {}

void OpenGLESRender::prepare() {
    prepareBase();
}

void OpenGLESRender::render() {
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,uint32_t(m_width),uint32_t(m_height));
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1,0.2,0.3,1.0);

    glFlush();
}
END_NAMESPACE(OpenGLESEngine)