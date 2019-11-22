#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "opengles_basicengine.h"
class Shader;
class Triangle:public OpenGLESBasicEngine{
public:
    Triangle();
    ~Triangle()=default;

    void prepare();
    void render();
    void OnUpdateUIOverlay(ImguiOverlay* overlay);

    //void keyPressed(uint32_t);
    //void mouseMoved(double x, double y, bool & handled);
private:
    void generateVertexs();
    void prepareShaders();
    void prepareUniforms();
    void updateUniforms(bool update=false);
    void startAutoRotation();
private:
    uint32_t m_vertexArray=NULL;
    Shader* m_shader=nullptr;
    struct UBO{
        glm::mat4 projection;
        glm::mat4 model;
    }m_uboVS;
    bool m_autoRotation=false;
};
#endif
