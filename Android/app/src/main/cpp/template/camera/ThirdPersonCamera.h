//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_THIRDPERSONCAMERA_H
#define LEARNOPENGLES_THIRDPERSONCAMERA_H

#include "render_common.h"

#include <glm/glm.hpp>

class ThirdPersonCamera {
public:
    ThirdPersonCamera()=default;
    virtual ~ThirdPersonCamera()=default;

    glm::vec3 m_rotation = glm::vec3();
    glm::vec3 m_cameraPos = glm::vec3();
    const float m_baseZoom = -2.f;
    float m_zoom = m_baseZoom;
};


#endif //LEARNOPENGLES_THIRDPERSONCAMERA_H
