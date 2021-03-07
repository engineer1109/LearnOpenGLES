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
    struct TextureLayout {
        int textureShaderID;
        std::string textureShaderName;
        OpenGLESTexture *texture;
    };
public:
    OpenGLESMaterial() = default;

    virtual ~OpenGLESMaterial() = default;

    virtual void prepare() override;

    virtual void update() override;

    void setShader(Shader *shader) { m_shader = shader; }

    void setTextures(
            const std::vector<TextureLayout> &textureLayout) { m_textureLayout = textureLayout; }

protected:
    Shader *m_shader = nullptr;
    std::vector<TextureLayout> m_textureLayout;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_OPENGLESMATERIAL_H
