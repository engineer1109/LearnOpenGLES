//
// Created by wjl on 21-3-6.
//

#include "OpenGLESTexture3D.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

void OpenGLESTexture3D::loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t depth, uint32_t channels,
                              GLint format, GLint addressMode, GLint filter) {
    // init member vars
    m_width = width;
    m_height = height;
    m_depth = depth;
    m_channels = channels;
    m_size = width * height * depth * channels;

    if (m_size <= 0) {
        LOGI("error size: %d", m_size);
    }

    // Gen Texture
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_3D, m_textureID);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, addressMode);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, addressMode);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, addressMode);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, filter);
    // load image, create texture and generate mipmaps
    int w, h, c, d;
    w = static_cast<int32_t>(m_width);
    h = static_cast<int32_t>(m_height);
    d = static_cast<int32_t>(m_depth);
    c = static_cast<int32_t>(m_channels);
    m_data = data;
    if (m_data) {
        glTexImage3D(GL_TEXTURE_3D, 0, format, w, h, d, 0, GL_RED, GL_UNSIGNED_BYTE, m_data);
        // glGenerateMipmap(GL_TEXTURE_3D);
    }
    else {
        LOGI("Failed to load texture");
    }
}

uint32_t OpenGLESTexture3D::getWidth() { return m_width; }

uint32_t OpenGLESTexture3D::getHeight() { return m_height; }

uint32_t OpenGLESTexture3D::getDepth() { return m_depth; }

uint32_t OpenGLESTexture3D::getChannels() { return m_channels; }

uint32_t OpenGLESTexture3D::getSize() { return m_size; }

uint8_t *OpenGLESTexture3D::getImgPtr() { return m_data; }

END_NAMESPACE(OpenGLESTemplate)
