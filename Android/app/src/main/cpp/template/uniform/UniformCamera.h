//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_UNIFORMCAMERA_H
#define LEARNOPENGLES_UNIFORMCAMERA_H

#include "OpenGLESUniform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

BEGIN_NAMESPACE(OpenGLESTemplate)

class UniformCamera : public OpenGLESUniform {
public:
    struct CameraMatrix {
        glm::mat4 projection;
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 normal;
        glm::vec4 lightpos;
    };
public:
    UniformCamera() = default;

    void prepareUniforms() override;

    void updateUniforms() override;

    void setScreenSizePtr(uint32_t *w, uint32_t *h) {
        m_pScreenWidth = w;
        m_pScreenHeight = h;
    }

    void setZoomPtr(float *zoom) { m_pZoom = zoom; }

    void setRotationPtr(glm::vec3 *rotation) { m_pRotation = rotation; }

    void setCameraPosPtr(glm::vec3 *cameraPos) { m_pCameraPos = cameraPos; }

public:
    CameraMatrix m_cameraMat;

    uint32_t *m_pScreenWidth = nullptr;
    uint32_t *m_pScreenHeight = nullptr;
    float *m_pZoom = nullptr;
    glm::vec3 *m_pRotation = nullptr;
    glm::vec3 *m_pCameraPos = nullptr;
};

END_NAMESPACE(OpenGLESTemplate)

#endif //LEARNOPENGLES_UNIFORMCAMERA_H
