//
// Created by wjl on 21-3-6.
//

#include "OpenGLESMaterial.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

// AVOID CRASH
void OpenGLESMaterial::prepare() {
    if (m_textureIndex.size() != m_textures.size()) {
        LOGW("m_textureIndex.size()!=m_textures.size()");
        if (m_textureIndex.size() < m_textures.size()) {
            m_textureIndex.resize(m_textures.size());
        }
    }
}

void OpenGLESMaterial::update() {
    for (int i = 0; i < m_textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + m_textureIndex[i]);
        glBindTexture(GL_TEXTURE_2D, m_textures[i]->getTextureID());
    }
}

END_NAMESPACE(OpenGLESTemplate)
