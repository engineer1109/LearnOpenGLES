//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_OPENGLESRENDER_H
#define OPENGLESTEST_OPENGLESRENDER_H

#include "OpenGLESBase.h"

BEGIN_NAMESPACE(OpenGLESEngine)

class OpenGLESRender : public OpenGLESBase {
public:
    OpenGLESRender();
    ~OpenGLESRender();

    void prepare();
    void render();
};

END_NAMESPACE(OpenGLESEngine)

#endif //OPENGLESTEST_OPENGLESRENDER_H
