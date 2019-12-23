#ifndef QTOPENGLESENGINE_H
#define QTOPENGLESENGINE_H
#include <QCoreApplication>
#include "opengles_basicengine.h"
#include "qtopengleswindow_export.h"
class QtOpenGLESEngine : public OpenGLESBasicEngine{
public:
    QtOpenGLESEngine();
    ~QtOpenGLESEngine();

    virtual void renderPlugin();
};
#endif // QTOPENGLESENGINE_H
