#ifndef OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
#define OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
#include "opengles_basicengine_object.h"
BEGIN_NAMESPACE(OpenGLESTemplate)
class Texture2DObject : public Object{
public:
    Texture2DObject()=default;
    ~Texture2DObject()=default;
protected:
    void prepareTextures(){}
};
END_NAMESPACE(OpenGLESTemplate)
#endif // OPENGLES_BASICENGINE_TEXTURE2DOBJECT_H
