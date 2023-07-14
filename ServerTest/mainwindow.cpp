#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new QTcpServer(this);
    client = new QTcpSocket(this);
    connect(ui->btnStartServer,&QPushButton::clicked,this,[=](){
        int port = ui->portEdit->text().toInt();
        server->listen(QHostAddress::Any,port);
    });
    connect(server,&QTcpServer::newConnection,this,[=](){
        client = server->nextPendingConnection();
    });
    connect(ui->btnSend,&QPushButton::clicked,this,[=](){
        client->write("fly");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Space)
    {
        client->write("fly");
    }
}
