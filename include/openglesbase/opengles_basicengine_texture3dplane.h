#ifndef OPENGLES_BASICENGINE_TEXTURE3DPLANE_H
#define OPENGLES_BASICENGINE_TEXTURE3DPLANE_H

#include "opengles_basicengine_texture3dobject.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Texture3DPlane : public Texture3DObject {
public:
    Texture3DPlane() = default;
    ~Texture3DPlane();

    virtual void prepare();

public:
    struct Vertex {
        float pos[3];
        float uvw[3];
        float normal[3];
    };

protected:
    virtual void generateVertexs();
    virtual void prepareTextures();

protected:
    float m_a = 1.f;
    float m_b = 1.f;
};
END_NAMESPACE(OpenGLESTemplate)

#endif // OPENGLES_BASICENGINE_TEXTURE3DPLANE_H
