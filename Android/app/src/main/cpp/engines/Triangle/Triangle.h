//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESRENDER_H
#define OPENGLESTEST_OPENGLESRENDER_H

#include "OpenGLESBase.h"
#include "vertex_struct.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

BEGIN_NAMESPACE(OpenGLESEngine)

class Triangle : public OpenGLESBase {
public:
    Triangle();

    ~Triangle();

    void prepare();

    void prepareShaders();

    void generateVertexs();

    void prepareUniforms();

    void updateUniforms(bool update);

    void render();

private:
    uint32_t m_vertexArray = 0;
    uint32_t m_vertexBuffer = 0;
    Shader *m_shader = nullptr;

    struct UBO {
        glm::mat4 projection;
        glm::mat4 model;
    } m_uboVS;

    glm::vec3 m_rotation = glm::vec3();
    glm::vec3 m_cameraPos = glm::vec3();
    const float m_baseZoom = -2.f;
    float m_zoom = m_baseZoom;
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESTEST_OPENGLESRENDER_H
