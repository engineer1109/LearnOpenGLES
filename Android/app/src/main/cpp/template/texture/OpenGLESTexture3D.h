//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_OPENGLESTEXTURE3D_H
#define LEARNOPENGLES_OPENGLESTEXTURE3D_H

#include "OpenGLESTexture.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESTexture3D : public OpenGLESTexture {
public:
    OpenGLESTexture3D() = default;
    virtual ~OpenGLESTexture3D() = default;

    void loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t depth, uint32_t channels,
                       GLint format = GL_RGBA, GLint addressMode = GL_REPEAT, GLint filter = GL_LINEAR);
    uint32_t getWidth();
    uint32_t getHeight();
    uint32_t getDepth();
    uint32_t getChannels();
    uint32_t getSize();
    uint8_t *getImgPtr();

    // void freeImgPtr();

protected:
    uint32_t m_width = 0;
    uint32_t m_height = 0;
    uint32_t m_depth = 0;
    uint32_t m_channels = 0;
    uint8_t *m_data = nullptr;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESTEXTURE3D_H
