#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加资源到项目中
    ui->actionNew->setIcon(QIcon(":/icon/Image/1.jpg"));
    ui->actionOpen->setIcon(QIcon(":/icon/Image/2.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

