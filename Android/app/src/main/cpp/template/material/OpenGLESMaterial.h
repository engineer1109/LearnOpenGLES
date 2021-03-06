//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_OPENGLESMATERIAL_H
#define LEARNOPENGLES_OPENGLESMATERIAL_H

#include "render_common.h"
#include "shader_m.h"
#include "OpenGLESObject.h"
#include "OpenGLESTexture.h"

BEGIN_NAMESPACE(OpenGLESTemplate)

class OpenGLESMaterial : public OpenGLESObject {
public:
    OpenGLESMaterial() = default;

    virtual ~OpenGLESMaterial() = default;

    virtual void prepare() override;

    virtual void update() override;

    void setTextureIndex(const std::vector<uint32_t> &index) {m_textureIndex = index;}

    void setShader(Shader *shader) { m_shader = shader; }

    void setTextures(const std::vector<OpenGLESTexture *> &textures) { m_textures = textures; }

protected:
    Shader *m_shader = nullptr;
    std::vector<OpenGLESTexture *> m_textures;
    std::vector<uint32_t> m_textureIndex;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESMATERIAL_H
