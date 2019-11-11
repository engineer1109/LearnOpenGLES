#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "opengles_basicengine.h"
class Triangle:public OpenGLESBasicEngine{
public:
    Triangle()=default;
    ~Triangle()=default;

    void render();

    void keyPressed(uint32_t);
    void mouseMoved(double x, double y, bool & handled);
};
#endif
