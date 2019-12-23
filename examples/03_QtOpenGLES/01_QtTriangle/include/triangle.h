#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "qtopenglesengine.h"
class Shader;
class Triangle:public QtOpenGLESEngine{
public:
    Triangle();
    ~Triangle();

    void prepare();
    void render();
    void OnUpdateUIOverlay(ImguiOverlay* overlay);

    void windowResize();

    //void keyPressed(uint32_t);
    //void mouseMoved(double x, double y, bool & handled);
private:
    void generateVertexs();
    void prepareShaders();
    void prepareUniforms();
    void updateUniforms(bool update=false);
    void startAutoRotation();
private:
    uint32_t m_vertexArray=0;
    uint32_t m_vertexBuffer=0;
    Shader* m_shader=nullptr;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
    struct UBO{
        glm::mat4 projection;
        glm::mat4 model;
    }m_uboVS;
    bool m_autoRotation=false;
};
#endif
