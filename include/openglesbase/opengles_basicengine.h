/*
* LearnOpenGLES Examples
*
* Copyright (C) by engineer1109 - https://github.com/engineer1109/LearnOpenGLES
*
* This code is licensed under GNU General Public License v3.0  (GPL-3.0) (https://opensource.org/licenses/GPL-3.0)
*/
#ifndef OPENGLES_BASICENGINE_H
#define OPENGLES_BASICENGINE_H
#include "opengles_basicengine_filesystem.h"
#include "openglesbase.h"
class OPENGLESBASE_EXPORT OpenGLESBasicEngine: public OpenGLESBase{
public:
    OpenGLESBasicEngine();
    virtual ~OpenGLESBasicEngine();

    void quitRender();

    void setWindow(uint32_t winId);
    void* getWindowPtr();
};


#endif // OPENGLES_BASICENGINE_H
