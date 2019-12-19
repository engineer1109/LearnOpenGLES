#ifndef QTOPENGLESWINDOW_H
#define QTOPENGLESWINDOW_H
#include <QMainWindow>
#include "qtopengleswindow_export.h"
class QTOPENGLESWINDOW_EXPORT QtOpenGLESWindow : public QMainWindow{
    Q_OBJECT
public:
    QtOpenGLESWindow(QWidget *parent = Q_NULLPTR);
    ~QtOpenGLESWindow();

    void setFlag(Qt::WindowFlags flags);
    uint32_t getWindowHandle();
    void setOpenGLESPtr(OpenGLESBase* opengles);
};
#endif
