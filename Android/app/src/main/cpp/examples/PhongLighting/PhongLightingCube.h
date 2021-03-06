//
// Created by wjl on 21-1-27.
//

#ifndef OPENGLESDEMO_PHONGLIGHTINGCUBE_H
#define OPENGLESDEMO_PHONGLIGHTINGCUBE_H

#include "OpenGLESCube.h"

class PhongLightingCube : public OpenGLESTemplate::OpenGLESCube {
public:
    PhongLightingCube();

    ~PhongLightingCube();

    void prepare();

    void update();

    void prepareShaders() override;

    void prepareUniforms() override;

    void updateUniforms() override;

    void prepareTextures();

    void setZoomPtr(float *zoom) { m_zoom = zoom; }

    void setCameraPosPtr(glm::vec3 *cameraPos) { m_cameraPos = cameraPos; }

    void setRotationPtr(glm::vec3 *rotation) { m_rotation = rotation; }

private:
    float *m_zoom = nullptr;
    glm::vec3 *m_cameraPos = nullptr;
    glm::vec3 *m_rotation = nullptr;

    uint32_t m_texture1 = 0;
    uint32_t m_texture2 = 0;

};


#endif //OPENGLESDEMO_PHONGLIGHTINGCUBE_H
