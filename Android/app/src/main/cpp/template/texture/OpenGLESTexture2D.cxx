//
// Created by wjl on 21-3-6.
//

#include "OpenGLESTexture2D.h"

#include <stb_image_aug.h>

BEGIN_NAMESPACE(OpenGLESTemplate)

void OpenGLESTexture2D::loadFromFile(std::string file, GLint format, GLint addressMode, GLint filter, bool autoFree) {
    // Gen Texture
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, addressMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, addressMode);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    // load image, create texture and generate mipmaps
    int w, h, c;

    m_data = stbi_load(file.c_str(), &w, &h, &c, 0);
    m_width = w;
    m_height = h;
    m_channels = c;
    m_size = m_width * m_height * m_channels;

    if (m_size <= 0) {
        LOGI("error size: %d", m_size);
    }

    if (m_data) {
        glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        LOGI("Failed to load texture");
    }
    if (autoFree and m_data) {
        stbi_image_free(m_data);
        m_data = nullptr;
    }
}

void OpenGLESTexture2D::loadFromFile(std::string file, AAssetManager* asset, GLint format, GLint addressMode, GLint filter, bool autoFree) {
    // texture 1
    // ---------
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;

    AssetReader *assetReader = new AssetReader(file.c_str(), asset);
    assetReader->run();

    unsigned char *data = stbi_load_from_memory((uint8_t*)assetReader->getOutData(),assetReader->getSize(), &width, &height, &nrChannels, 0);
    if (data or assetReader->getSize()==0) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        LOGI("Failed Load Texture1");
    }
    stbi_image_free(data);
    delete assetReader;
}

void OpenGLESTexture2D::loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t channels, GLint format,
                              GLint addressMode, GLint filter) {
    // init member vars
    m_width = width;
    m_height = height;
    m_channels = channels;
    m_size = width * height * channels;

    if (m_size <= 0) {
        LOGI("error size: %d", m_size);
    }

    // Gen Texture
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, addressMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, addressMode);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    // load image, create texture and generate mipmaps
    int w, h, c;
    w = static_cast<int32_t>(m_width);
    h = static_cast<int32_t>(m_height);
    c = static_cast<int32_t>(m_channels);
    m_data = data;
    if (m_data) {
        glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        LOGI("Failed to load texture");
    }
}

uint32_t OpenGLESTexture2D::getWidth() { return m_width; }

uint32_t OpenGLESTexture2D::getHeight() { return m_height; }

uint32_t OpenGLESTexture2D::getChannels() { return m_channels; }

uint32_t OpenGLESTexture2D::getSize() { return m_size; }

uint8_t *OpenGLESTexture2D::getImgPtr() { return m_data; }

void OpenGLESTexture2D::freeImgPtr() {
    if (m_data) {
        stbi_image_free(m_data);
        m_data = nullptr;
    }
}

END_NAMESPACE(OpenGLESTemplate)