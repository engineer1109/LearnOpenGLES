#ifndef LEARNOPENGLES_OPENGLESMESHOBJECT_H
#define LEARNOPENGLES_OPENGLESMESHOBJECT_H
#include "OpenGLESObject.h"
#include "shader_m.h"

BEGIN_NAMESPACE(OpenGLESTemplate)
class OpenGLESMeshObject : public OpenGLESObject {
public:
    OpenGLESMeshObject();
    virtual ~OpenGLESMeshObject();

    virtual void prepare();
    virtual void update();

    void setAssetManager(AAssetManager* asset) {m_asset=asset;}
    void setScreenPtr(uint32_t* pScreenWidth,uint32_t* pScreenHeight);
public:

protected:
    virtual void generateVertexs();
    virtual void prepareShaders();
    virtual void prepareUniforms();
    virtual void updateUniforms();
    virtual void draw();
protected:
    uint32_t m_vertexArray=0;
    uint32_t m_vertexBuffer=0;
    uint32_t m_indexCount = 0;
    uint32_t* m_pScreenWidth=nullptr;
    uint32_t* m_pScreenHeight=nullptr;
    Shader* m_shader=nullptr;
    AAssetManager *m_asset = nullptr;
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
#endif // LEARNOPENGLES_MESHOBJECT_H
