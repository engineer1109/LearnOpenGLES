#include <QMouseEvent>
#include "qtopengleswindow.h"
QtOpenGLESWindow::QtOpenGLESWindow(QWidget *parent):QMainWindow (parent){
    this->setMouseTracking(true);
}

QtOpenGLESWindow::~QtOpenGLESWindow(){

}

void QtOpenGLESWindow::setFlag(Qt::WindowFlags flags){
    setWindowFlags(flags);
}

uint32_t QtOpenGLESWindow::getWindowHandle(){
    return uint32_t(winId());
}

void QtOpenGLESWindow::setOpenGLESPtr(OpenGLESBasicEngine* opengles){
    m_opengles=opengles;
}

void QtOpenGLESWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() & Qt::LeftButton){
        m_opengles->mouseButtons.left=true;
    }
    else if (event->button() & Qt::RightButton) {
        m_opengles->mouseButtons.right=true;
    }
    else if (event->button() & Qt::MidButton) {
        m_opengles->mouseButtons.middle=true;
    }
    m_opengles->handleMouseMove(event->pos().x(),event->pos().y());
}

void QtOpenGLESWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() & Qt::LeftButton){
        m_opengles->mouseButtons.left=false;
    }
    else if (event->button() & Qt::RightButton) {
        m_opengles->mouseButtons.right=false;
    }
    else if (event->button() & Qt::MidButton) {
        m_opengles->mouseButtons.middle=false;
    }
    m_opengles->handleMouseMove(event->pos().x(),event->pos().y());
}

void QtOpenGLESWindow::mouseMoveEvent(QMouseEvent *event){
    m_opengles->handleMouseMove(event->pos().x(),event->pos().y());
}

void QtOpenGLESWindow::showEvent(QShowEvent *event){
    m_opengles->setWindow(uint32_t(winId()));
    m_opengles->prepare();
    //m_opengles->renderAsyncThread();
    //m_opengles->renderLoop();
}

void QtOpenGLESWindow::closeEvent(QCloseEvent *event){

}
