//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_OPENGLESTEXTURE2D_H
#define LEARNOPENGLES_OPENGLESTEXTURE2D_H

#include "OpenGLESTexture.h"
#include "AssetReader.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESTexture2D : public OpenGLESTexture {
public:
    OpenGLESTexture2D() = default;
    virtual ~OpenGLESTexture2D() = default;

    // If you turn off autoFree, you can use getImgPtr Later.But you need free manually.
    void loadFromFile(std::string file, GLint format = GL_RGBA, GLint addressMode = GL_REPEAT, GLint filter = GL_LINEAR,
                      bool autoFree = true);

    void loadFromFile(std::string file, AAssetManager* asset, GLint format = GL_RGBA, GLint addressMode = GL_REPEAT, GLint filter = GL_LINEAR,
                      bool autoFree = true);

    void loadFromArray(uint8_t *data, uint32_t width, uint32_t height, uint32_t channels, GLint format = GL_RGBA,
                       GLint addressMode = GL_REPEAT, GLint filter = GL_LINEAR);

    uint32_t getWidth();
    uint32_t getHeight();
    uint32_t getChannels();
    uint32_t getSize();
    uint8_t *getImgPtr();

    // only for loadFromFile when turning off autoFree
    void freeImgPtr();

protected:
    uint32_t m_width = 0;
    uint32_t m_height = 0;
    uint32_t m_channels = 0;
    uint8_t *m_data = nullptr;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESTEXTURE2D_H
