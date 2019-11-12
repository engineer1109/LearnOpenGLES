#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "opengles_basicengine.h"
class Shader;
class Triangle:public OpenGLESBasicEngine{
public:
    Triangle()=default;
    ~Triangle()=default;

    void prepare();
    void render();

    //void keyPressed(uint32_t);
    //void mouseMoved(double x, double y, bool & handled);
private:
    uint m_vertexArray=NULL;
    Shader* m_shader=nullptr;
};
#endif
