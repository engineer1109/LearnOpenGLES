//
// Created by wjl on 21-3-6.
//

#include "OpenGLESMaterial.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

// AVOID CRASH
void OpenGLESMaterial::prepare() {
    m_shader->use();
    for (int i = 0; i< m_textureLayout.size(); i++){
        m_shader->setInt(m_textureLayout[i].textureShaderName, m_textureLayout[i].textureShaderID);
    }
}

void OpenGLESMaterial::update() {
    m_shader->use();
    for (int i = 0; i < m_textureLayout.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + m_textureLayout[i].textureShaderID);
        glBindTexture(GL_TEXTURE_2D, m_textureLayout[i].texture->getTextureID());
    }
}

END_NAMESPACE(OpenGLESTemplate)
