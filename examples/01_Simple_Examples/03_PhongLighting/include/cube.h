#ifndef CUBE_H
#define CUBE_H
#include "opengles_basicengine_cube.h"
class Cube : public OpenGLESTemplate::OpenGLCube{
public:
    Cube();
    ~Cube();

    void prepare();
    void update();

    void prepareTextures();
    void prepareShaders();
    void prepareUniforms();
    void updateUniforms();

public:
    struct{
        glm::vec3* pRotation = nullptr;
        glm::vec3* pCameraPos = nullptr;
        float* pZoom=nullptr;
    }m_camera;
};
#endif // CUBE_H
