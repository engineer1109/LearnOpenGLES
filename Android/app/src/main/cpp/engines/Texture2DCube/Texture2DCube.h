#ifndef TEXTURE2D_CUBE_H
#define TEXTURE2D_CUBE_H

#include "OpenGLESBase.h"
#include "vertex_struct.h"
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

    bool m_autoRotation = false;
    glm::vec3 m_rotation = glm::vec3();
    glm::vec3 m_cameraPos = glm::vec3();
    const float m_baseZoom = -4.f;
    float m_zoom = m_baseZoom;
};


END_NAMESPACE(OpenGLESEngine)

#endif