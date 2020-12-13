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

BEGIN_NAMESPACE(OpenGLESEngine)

class PhongLighting : public OpenGLESBase {
public:
    PhongLighting();
    ~PhongLighting();




};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESDEMO_PHONGLIGHTING_H
