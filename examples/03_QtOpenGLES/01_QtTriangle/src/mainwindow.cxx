#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
