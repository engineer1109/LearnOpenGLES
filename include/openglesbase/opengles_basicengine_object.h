#ifndef OPENGLES_BASICENGINE_OBJECT_H
#define OPENGLES_BASICENGINE_OBJECT_H
#include "shader_m.h"
#include "opengles_basicengine_help.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Object{
public:
    Object();
    virtual ~Object();

    virtual void prepare();
    virtual void update();

    void setScreenPtr(uint32_t* pScreenWidth,uint32_t* pScreenHeight);
public:

protected:
    virtual void generateVertexs();
    virtual void prepareShaders();
    virtual void prepareUniforms();
    virtual void updateUniforms();
protected:
    uint32_t m_vertexArray=0;
    uint32_t m_vertexBuffer=0;
    uint32_t* m_pScreenWidth=nullptr;
    uint32_t* m_pScreenHeight=nullptr;
    Shader* m_shader=nullptr;
    struct UBO{
        glm::mat4 projection;
        glm::mat4 model;
        glm::vec4 viewPos;
        float lodBias=0.f;
    }m_uboVS;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
};

END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_OBJECT_H
