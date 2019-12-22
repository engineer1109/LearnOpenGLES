#ifndef TEXTURE2DCUBE_H
#define TEXTURE2DCUBE_H
#include "opengles_basicengine.h"
class Shader;
class Texture2dCube:public OpenGLESBasicEngine{
public:
    Texture2dCube();
    ~Texture2dCube();

    void prepare();
    void render();
    void OnUpdateUIOverlay(ImguiOverlay* overlay);
private:
    void generateVertexs();
    void prepareTextures();
    void prepareShaders();
    void prepareUniforms();
    void updateUniforms(bool update=false);
    void startAutoRotation();
private:
    uint32_t m_vertexArray=0;
    uint32_t m_vertexBuffer=0;
    uint32_t m_texture1=0;
    uint32_t m_texture2=0;
    Shader* m_shader=nullptr;
    struct UBO{
        glm::mat4 projection;
        glm::mat4 model;
    }m_uboVS;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
    bool m_autoRotation=false;
};
#endif
