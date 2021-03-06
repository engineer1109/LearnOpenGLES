//
// Created by wjl on 21-3-6.
//

#ifndef LEARNOPENGLES_THIRDPERSONENGINE_H
#define LEARNOPENGLES_THIRDPERSONENGINE_H

#include "OpenGLESBase.h"

#include "ThirdPersonCamera.h"

BEGIN_NAMESPACE(OpenGLESEngine)

class ThirdPersonEngine : public OpenGLESBase, public ThirdPersonCamera {
public:
    ThirdPersonEngine() = default;

    virtual ~ThirdPersonEngine() = default;

    void updateCamera();
};

END_NAMESPACE(OpenGLESEngine)

#endif //LEARNOPENGLES_THIRDPERSONENGINE_H
