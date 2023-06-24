#include "pushbutton1.h"
#include <QDebug>
PushButton1::PushButton1(QWidget *parent)
    : QPushButton{parent}
{
    qDebug() << "构造";
}

PushButton1::~PushButton1()
{
    qDebug() << "析构";
}
