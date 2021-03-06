//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESRENDER_H
#define OPENGLESTEST_OPENGLESRENDER_H

#include "ThirdPersonEngine.h"
#include "UniformCamera.h"

#include <glm/gtc/matrix_transform.hpp>

class Shader;

BEGIN_NAMESPACE(OpenGLESEngine)

class TriangleObject;

class Triangle : public ThirdPersonEngine {
public:
    Triangle();

    ~Triangle();

    void prepareMyObjects() override;

    void prepareShaders();

    void render() override;

protected:
    void createTriangle();

    void createUniformCamera();

private:
    TriangleObject* m_triangleObject = nullptr;
    OpenGLESTemplate::UniformCamera* m_uniformCamera = nullptr;

    Shader *m_shader = nullptr;

    struct UBO {
        glm::mat4 projection;
        glm::mat4 model;
    } m_uboVS;
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESTEST_OPENGLESRENDER_H
