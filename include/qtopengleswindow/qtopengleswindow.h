/*
* LearnOpenGLES Examples
*
* Copyright (C) by engineer1109 - https://github.com/engineer1109/LearnOpenGLES
*
* This code is licensed under GNU General Public License v3.0  (GPL-3.0) (https://opensource.org/licenses/GPL-3.0)
*/
#ifndef QTOPENGLESWINDOW_H
#define QTOPENGLESWINDOW_H
#include <QMainWindow>
#include "qtopenglesengine.h"
#include "qtopengleswindow_export.h"
class QTOPENGLESWINDOW_EXPORT QtOpenGLESWindow : public QMainWindow{
    Q_OBJECT
public:
    QtOpenGLESWindow(QWidget *parent = Q_NULLPTR);
    ~QtOpenGLESWindow();

    void setFlag(Qt::WindowFlags flags);
    uint32_t getWindowHandle();
    void setOpenGLESPtr(QtOpenGLESEngine* opengles);
public slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

    void resizeEvent(QResizeEvent *event);

    void renderLoop();
private:
    OpenGLESBasicEngine* m_opengles=nullptr;
};
#endif
