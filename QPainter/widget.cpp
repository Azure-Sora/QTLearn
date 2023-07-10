#include "widget.h"
#include "./ui_widget.h"
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(500,500);

    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer,&QTimer::timeout,[=](){
        posx += 1;
        if(posx > this->width())
        {
            posx=20;
        }
        update();
    });

    connect(ui->btn,&QPushButton::clicked,[=](){
        posx += 20;
        if(posx > this->width())
        {
            posx=20;
        }
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

//系统会自动调用该函数
void Widget::paintEvent(QPaintEvent *event)
{
    //实例化画家对象 this指定绘图的设备
    QPainter painter(this);

    //设置画笔
//    QPen pen(QColor(255,0,0));
//    pen.setWidth(3);
//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);

    //设置画刷-填充色
//    QBrush brush(QColor(Qt::cyan));
//    brush.setStyle(Qt::DiagCrossPattern);
//    painter.setBrush(brush);

    //画线
//    painter.drawLine(QPoint(0,0), QPoint(100,100));
    //画圆 Ellipse椭圆
//    painter.drawEllipse(QPoint(100,100),50,50);
    //画矩形
//    painter.drawRect(QRect(100,100,50,50));
    //画文字
//    painter.drawText(QRect(150,150,100,50),"啊哈哈");


    //高级设置
    //画圆
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿 会影响效率
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    //画矩形
//    painter.drawRect(QRect(10,150,50,50));
//    //移动画家的坐标系
//    painter.translate(100,0);
//    //保存状态
//    painter.save();
//    painter.drawRect(QRect(10,150,50,50));
//    painter.translate(100,0);
//    painter.restore();
//    painter.drawRect(QRect(10,150,50,50));

    //利用画家画图片
    painter.drawPixmap(posx,20,200,200,QPixmap(":/Image/1.jpg"));
}

