#ifndef OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
#define OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
#include "opengles_basicengine_texture.h"
#include "opengles_basicengine_object.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Texture2DObject : public Object{
public:
    Texture2DObject()=default;
    ~Texture2DObject()=default;
protected:
    virtual void prepareTextures(){}
protected:
    Texture2D m_textureA;
    Texture2D m_textureB;
};
END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
