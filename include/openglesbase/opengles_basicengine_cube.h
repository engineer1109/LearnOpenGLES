#ifndef OPENGLES_BASICENGINE_CUBE_H
#define OPENGLES_BASICENGINE_CUBE_H
#include "opengles_basicengine_texture2dobject.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class OpenGLCube:public Texture2DObject{
public:
    OpenGLCube()=default;
    virtual ~OpenGLCube();

    virtual void prepare();
protected:
    virtual void generateVertexs();
    virtual void prepareTextures();

protected:
    float m_a=1.f;
    float m_b=1.f;
    float m_c=1.f;
};
END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_CUBE_H
