#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->login,&QPushButton::clicked,[=](){
        if(ui->userName->text()=="abc" && ui->passWord->text()=="123456")
        {
            ui->whetherLogin->setText("登录成功");
        }
        else
        {
            ui->whetherLogin->setText("登录失败");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

