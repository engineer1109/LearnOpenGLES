#ifndef OPENGLES_BASICENGINE_H
#define OPENGLES_BASICENGINE_H
#include "openglesbase.h"
#include "openglesbase_def.h"
class OPENGLESBASE_EXPORT OpenGLESBasicEngine: public OpenGLESBase{
public:
    OpenGLESBasicEngine();
    ~OpenGLESBasicEngine();

    void setWindow(uint32_t winId);
    void* getWindowPtr();
};


#endif // OPENGLES_BASICENGINE_H
