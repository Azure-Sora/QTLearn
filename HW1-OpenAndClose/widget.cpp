#include "widget.h"
#include "widget2.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn1 = new QPushButton(this);
    btn1->move(200,200);
    btn1->resize(100,50);
    btn1->setText("Open");
    connect(btn1,&QPushButton::clicked,this,[=](){
        if(this->widget2==nullptr)
        {
            btn1->setText("Close");
            this->widget2 = new Widget2;
            this->widget2->show();
        }
        else
        {
            btn1->setText("Open");
            this->widget2->close();
            this->widget2 = nullptr;

        }
    });
    this->resize(500,500);
}

Widget::~Widget()
{
}

