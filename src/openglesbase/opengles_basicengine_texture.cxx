#include "opengles_basicengine_texture.h"
#include <stb_image_aug.h>
BEGIN_NAMESPACE(OpenGLESTemplate)
void Texture2D::loadFromFile(std::string file, GLint format, GLint addressMode, GLint filter, bool autoFree) {
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
        std::cout << "error size:" << m_size << std::endl;
    }

    if (m_data) {
        glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    if (autoFree and m_data) {
        stbi_image_free(m_data);
        m_data = nullptr;
    }
}

void Texture2D::loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t channels, GLint format,
                              GLint addressMode, GLint filter) {
    // init member vars
    m_width = width;
    m_height = height;
    m_channels = channels;
    m_size = width * height * channels;

    if (m_size <= 0) {
        std::cout << "error size:" << m_size << std::endl;
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
        std::cout << "Failed to load texture" << std::endl;
    }
}

uint32_t Texture2D::getWidth() { return m_width; }

uint32_t Texture2D::getHeight() { return m_height; }

uint32_t Texture2D::getChannels() { return m_channels; }

uint32_t Texture2D::getSize() { return m_size; }

uint8_t *Texture2D::getImgPtr() { return m_data; }

void Texture2D::freeImgPtr() {
    if (m_data) {
        stbi_image_free(m_data);
        m_data = nullptr;
    }
}

//////////////////Texture 3D////////////////
void Texture3D::loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t depth, uint32_t channels,
                              GLint format, GLint addressMode, GLint filter) {
    // init member vars
    m_width = width;
    m_height = height;
    m_depth = depth;
    m_channels = channels;
    m_size = width * height * depth * channels;

    if (m_size <= 0) {
        std::cout << "error size:" << m_size << std::endl;
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
        std::cout << "Failed to load texture" << std::endl;
    }
}

uint32_t Texture3D::getWidth() { return m_width; }

uint32_t Texture3D::getHeight() { return m_height; }

uint32_t Texture3D::getDepth() { return m_depth; }

uint32_t Texture3D::getChannels() { return m_channels; }

uint32_t Texture3D::getSize() { return m_size; }

uint8_t *Texture3D::getImgPtr() { return m_data; }

END_NAMESPACE(OpenGLESTemplate)
