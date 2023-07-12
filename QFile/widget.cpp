#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QStringDecoder>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //选择文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString filename = QFileDialog::getOpenFileName(this,"打开文件","C:\\");

        ui->lineEdit->setText(filename);

        //读取内容
        //QFile默认支持UTF-8
        QFile file(filename);
        //设置打开方式
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();

        //将数据放入框中
        ui->textEdit->setText(array);




    });
}

Widget::~Widget()
{
    delete ui;
}

