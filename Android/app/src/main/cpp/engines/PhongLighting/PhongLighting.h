//
// Created by wjl on 20-12-13.
//

#ifndef OPENGLESDEMO_PHONGLIGHTING_H
#define OPENGLESDEMO_PHONGLIGHTING_H

#include "OpenGLESBase.h"
#include "vertex_struct.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

class PhongLightingCube;

BEGIN_NAMESPACE(OpenGLESEngine)

class PhongLighting : public OpenGLESBase {
public:
    PhongLighting();
    ~PhongLighting();

    void prepare();

    void render();

    void createPhongLightingCube();

private:
    PhongLightingCube* m_PhongLightingCube = nullptr;

    glm::vec3 m_rotation = glm::vec3();
    glm::vec3 m_cameraPos = glm::vec3();
    const float m_baseZoom = -4.f;
    float m_zoom = m_baseZoom;

};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESDEMO_PHONGLIGHTING_H
