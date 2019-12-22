#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "triangle.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setFlag(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(render()));
    glRender();
}

MainWindow::~MainWindow()
{
    if(ui!=nullptr){
        delete ui;
        ui=nullptr;
    }
}

void MainWindow::showEvent(QShowEvent *event){

}

void MainWindow::closeEvent(QCloseEvent *event){

}

void MainWindow::glRender(){
    if(!m_triangle){
        m_triangle=new Triangle();
        m_triangle->width=400;
        m_triangle->height=400;
        m_triangle->settings.overlay=false;
        //m_triangle->initWindow();
        //m_triangle->prepare();
        //m_triangle->renderAsyncThread();
        ui->widget->setOpenGLESPtr(m_triangle);
    }
}

void MainWindow::render(){
    m_triangle->renderLoop();
}
