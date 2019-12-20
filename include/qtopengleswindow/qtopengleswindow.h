#ifndef QTOPENGLESWINDOW_H
#define QTOPENGLESWINDOW_H
#include <QMainWindow>
#include "opengles_basicengine.h"
#include "qtopengleswindow_export.h"
class QTOPENGLESWINDOW_EXPORT QtOpenGLESWindow : public QMainWindow{
    Q_OBJECT
public:
    QtOpenGLESWindow(QWidget *parent = Q_NULLPTR);
    ~QtOpenGLESWindow();

    void setFlag(Qt::WindowFlags flags);
    uint32_t getWindowHandle();
    void setOpenGLESPtr(OpenGLESBasicEngine* opengles);
public slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    OpenGLESBasicEngine* m_opengles=nullptr;
};
#endif
