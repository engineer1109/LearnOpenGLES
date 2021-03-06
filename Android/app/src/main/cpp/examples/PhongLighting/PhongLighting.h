//
// Created by wjl on 20-12-13.
//

#ifndef OPENGLESDEMO_PHONGLIGHTING_H
#define OPENGLESDEMO_PHONGLIGHTING_H

#include "ThirdPersonEngine.h"
#include "vertex_struct.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

class PhongLightingCube;

BEGIN_NAMESPACE(OpenGLESEngine)

class PhongLighting : public ThirdPersonEngine {
public:
    PhongLighting();
    virtual ~PhongLighting();

    void prepareMyObjects();

    void render();

    void createPhongLightingCube();

private:
    PhongLightingCube* m_PhongLightingCube = nullptr;
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESDEMO_PHONGLIGHTING_H
