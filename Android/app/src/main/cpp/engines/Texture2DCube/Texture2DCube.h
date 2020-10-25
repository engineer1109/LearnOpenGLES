#ifndef TEXTURE2D_CUBE_H
#define TEXTURE2D_CUBE_H

#include "OpenGLESBase.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

BEGIN_NAMESPACE(OpenGLESEngine)

class Texture2DCube : public OpenGLESBase {
public:
    Texture2DCube();

    ~Texture2DCube();

    void prepare();

    void render();

private:
    void generateVertexs();

    void prepareTextures();

    void prepareShaders();

    void prepareUniforms();

    void updateUniforms(bool update = false);

    void startAutoRotation();

private:
    uint32_t m_vertexArray = 0;
    uint32_t m_vertexBuffer = 0;
    uint32_t m_texture1 = 0;
    uint32_t m_texture2 = 0;
    Shader *m_shader = nullptr;
    struct UBO {
        glm::mat4 projection;
        glm::mat4 model;
    } m_uboVS;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
    bool m_autoRotation = false;
    float m_zoom = 0.f;
};


END_NAMESPACE(OpenGLESEngine)

#endif