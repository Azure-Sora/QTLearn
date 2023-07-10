#include "widget.h"
#include "./ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //pixmap绘图设备
//    QPixmap pix(300,300);
//    QPainter painter(&pix);

//    //填充
//    pix.fill(Qt::white);

//    painter.setPen(QPen(QColor(Qt::green)));
//    painter.drawEllipse(QPoint(100,100),50,50);

//    pix.save("E:\\pix.png");

    //QImage绘图设备
    QImage img(300,300,QImage::Format_RGB32);
    QPainter painter2(&img);

    //填充
    img.fill(Qt::white);

    painter2.setPen(QPen(QColor(Qt::blue)));
    painter2.drawEllipse(QPoint(100,100),50,50);

    img.save("E:\\img.png");

    //QPicture绘图设备 用于记录和重现绘图指令
    QPicture pic;
    QPainter pt;
    pt.begin(&pic);

    pt.setPen(QPen(QColor(Qt::cyan)));
    pt.drawEllipse(QPoint(100,100),50,50);

    pt.end();

    pic.save("E:\\pic.mika");



}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //重现绘图指令

    QPainter pt2(this);
    QPicture pic2;
    pic2.load("E:\\pic.mika");
    pt2.drawPicture(0,0,pic2);
}

