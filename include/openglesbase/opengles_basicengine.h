#ifndef OPENGLES_BASICENGINE_H
#define OPENGLES_BASICENGINE_H
#include "opengles_basicengine_filesystem.h"
#include "openglesbase.h"
class OPENGLESBASE_EXPORT OpenGLESBasicEngine: public OpenGLESBase{
public:
    OpenGLESBasicEngine();
    ~OpenGLESBasicEngine();

    void quitRender();

    void setWindow(uint32_t winId);
    void* getWindowPtr();
};


#endif // OPENGLES_BASICENGINE_H
