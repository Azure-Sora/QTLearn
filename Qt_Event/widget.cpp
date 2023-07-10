#include "widget.h"
#include "./ui_widget.h"
#include <QTimerEvent>
#include <QTimer>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });
    connect(ui->btn, &QPushButton::clicked, [=](){
        timer->stop();
    });


    //给label安装事件过滤器
    ui->label->installEventFilter(this);
    //重写过滤器

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==id1)
    {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    if(e->timerId()==id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }


}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "事件过滤器拦截";
            return true;
        }
    }
    return QWidget::eventFilter(watched,event);
}

