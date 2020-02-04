#ifndef OPENGLES_BASICENGINE_TEXTURE3DOBJECT_H
#define OPENGLES_BASICENGINE_TEXTURE3DOBJECT_H
#include "opengles_basicengine_object.h"
#include "opengles_basicengine_texture.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Texture3DObject : public Object {
public:
    Texture3DObject() = default;
    ~Texture3DObject() = default;

protected:
    virtual void prepareTextures() {}

protected:
    Texture3D m_texture;
};
END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_TEXTURE3DOBJECT_H
