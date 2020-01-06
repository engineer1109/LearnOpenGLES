#ifndef PHONGLIGHTING_H
#define PHONGLIGHTING_H
#include "opengles_basicengine.h"
class Cube;
class PhongLighting : public OpenGLESBasicEngine{
public:
    PhongLighting();
    ~PhongLighting();

    void prepare();
    void render();

protected:
    void prepareObjects();
private:
    Cube* m_cube=nullptr;
};
#endif
