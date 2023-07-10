#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    //设置鼠标追踪状态，默认false
    //true状态下mouseMoveEvent不需要按下按键就能触发
//    setMouseTracking(true);
}

void myLabel::enterEvent(QEnterEvent *event)
{
//    qDebug() << "鼠标进入";
}

void myLabel::leaveEvent(QEvent *event)
{
//    qDebug() << "鼠标离开";
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    if( ev->button() == Qt::LeftButton )
    {
        qDebug() << "按下";
        qDebug() << "x = " << ev->position().x() << " y = " << ev->position().y();
        qDebug() << "glox = " << ev->globalPosition().x() << " gloy = " << ev->globalPosition().y();
    }
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << "释放";
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if( ev->buttons() == Qt::LeftButton )
    {
        qDebug() << "移动";
        qDebug() << "x = " << ev->position().x() << " y = " << ev->position().y();
        qDebug() << "glox = " << ev->globalPosition().x() << " gloy = " << ev->globalPosition().y();
    }
}

bool myLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *tmp = static_cast<QMouseEvent *>(e);
        qDebug() << "拦截事件" << " x:" <<tmp->position().x();
        return true;
    }
    return QLabel::event(e);
}
