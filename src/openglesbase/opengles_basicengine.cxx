#include "opengles_basicengine.h"
OpenGLESBasicEngine::OpenGLESBasicEngine():OpenGLESBase (){

}

OpenGLESBasicEngine::~OpenGLESBasicEngine(){

}

void OpenGLESBasicEngine::quitRender(){
    this->m_quit=true;
}

#ifdef OPENGLES_USE_XCB
void OpenGLESBasicEngine::setWindow(uint32_t winId){
    this->window=winId;
    xcb_map_window(this->connection,this->window);
}

void* OpenGLESBasicEngine::getWindowPtr(){
    return (void*)(this->getWindowHandle());
}
#endif

#ifdef OPENGLES_USE_WIN32
void OpenGLESBasicEngine::setWindow(uint32_t winId){
    this->window=(HWND)winId;
    this->windowInstance = ::GetModuleHandle(NULL);
}

void* OpenGLESBasicEngine::getWindowPtr(){
    return (void*)(this->window);
}
#endif
