//
// Created by wjl on 21-1-27.
//

#ifndef OPENGLESDEMO_PHONGLIGHTINGCUBE_H
#define OPENGLESDEMO_PHONGLIGHTINGCUBE_H

#include "OpenGLESCube.h"

class PhongLightingCube : public OpenGLESTemplate::Cube {
public:
    PhongLightingCube();
    ~PhongLightingCube();

    void prepare();
    void update();

    void prepareShaders() override;


};


#endif //OPENGLESDEMO_PHONGLIGHTINGCUBE_H
