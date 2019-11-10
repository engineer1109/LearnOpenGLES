#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "openglesbase.h"
class Triangle:public OpenGLESBase{
public:
    Triangle()=default;
    ~Triangle()=default;

    void render();
};
#endif
