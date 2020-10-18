//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESRENDER_H
#define OPENGLESTEST_OPENGLESRENDER_H

#include "OpenGLESBase.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Shader;

BEGIN_NAMESPACE(OpenGLESEngine)

class OpenGLESRender : public OpenGLESBase {
public:
    OpenGLESRender();
    ~OpenGLESRender();

    void prepare();
    void prepareShaders();
    void generateVertexs();
    void prepareUniforms();
    void updateUniforms(bool update);

    void render();

private:
    uint32_t m_vertexArray=0;
    uint32_t m_vertexBuffer=0;
    Shader* m_shader=nullptr;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
    struct UBO{
        glm::mat4 projection;
        glm::mat4 model;
    }m_uboVS;

    glm::vec3 rotation = glm::vec3();
    glm::vec3 cameraPos = glm::vec3();
    float zoom = 0;
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESTEST_OPENGLESRENDER_H
