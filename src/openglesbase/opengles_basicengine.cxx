#include "opengles_basicengine.h"
OpenGLESBasicEngine::OpenGLESBasicEngine():OpenGLESBase (){

}

OpenGLESBasicEngine::~OpenGLESBasicEngine(){

}

#ifdef OPENGLES_USE_XCB
void OpenGLESBasicEngine::setWindow(uint32_t winId){
    this->setWindowHandle(winId);
}

void* OpenGLESBasicEngine::getWindowPtr(){
    return (void*)(this->getWindowHandle());
}
#endif
