#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "triangle.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_opengles->setFlag(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    //connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(render()));
    glRender();
}

MainWindow::~MainWindow()
{
    if(ui!=nullptr){
        delete ui;
        ui=nullptr;
    }
    if(m_triangle!=nullptr){
        delete m_triangle;
        m_triangle=nullptr;
    }
}

void MainWindow::showEvent(QShowEvent *event){

}

void MainWindow::closeEvent(QCloseEvent *event){
    ui->widget_opengles->close();
}

void MainWindow::glRender(){
    if(!m_triangle){
        m_triangle=new Triangle();
        m_triangle->width=400;
        m_triangle->height=400;
        m_triangle->settings.overlay=true;
        ui->widget_opengles->setOpenGLESPtr(m_triangle);
    }
}
