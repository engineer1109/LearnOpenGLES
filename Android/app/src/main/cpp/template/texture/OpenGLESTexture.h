#ifndef OPENGLES_BASICENGINE_TEXTURE_H
#define OPENGLES_BASICENGINE_TEXTURE_H
#include "render_common.h"
#include "OpenGLESObject.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESTexture : public OpenGLESObject {
public:
    OpenGLESTexture() = default;
    virtual ~OpenGLESTexture() {
        if (m_textureID) {
            glDeleteTextures(1, &m_textureID);
            m_textureID = NULL;
        }
    }

    void prepare() override {}

    void update() override {}

    uint32_t getSize() { return m_size; }

    uint32_t getTextureID() { return m_textureID; }

protected:
    uint32_t m_textureID = 0;
    uint32_t m_size = 0;
};

END_NAMESPACE(OpenGLESTemplate)

#endif // OPENGLES_BASICENGINE_TEXTURE_H
