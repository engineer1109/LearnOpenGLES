//
// Created by wjl on 21-3-6.
//

#include "OpenGLESUniform.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

OpenGLESUniform::~OpenGLESUniform() {
    if(m_uniformBuffer){
        glDeleteBuffers(1, &m_uniformBuffer);
        m_uniformBuffer = NULL;
    }
}

void OpenGLESUniform::prepare() {
    prepareUniforms();
}

void OpenGLESUniform::update() {
    if(m_alwaysUpdate or m_updateSignal){
        updateUniforms();
    }
}

END_NAMESPACE(OpenGLESTemplate)
