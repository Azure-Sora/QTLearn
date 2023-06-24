#include "widget1.h"
#include <QPushButton>
#include "pushbutton1.h"

Widget1::Widget1(QWidget *parent)
    : QWidget(parent)//初始化列表
{
    //创建一个按钮
    QPushButton *button = new QPushButton;
    //button->show(); //show方法以顶层方式弹出控件，不用来显示窗口内控件
    button->setParent(this);//让button对象依赖在Widget1中
    button->setText("第一个按钮");

    //创建第二个按钮
    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    btn2->move(100,100);
    btn2->resize(100,100);

    //resize(600,400);

    setFixedSize(600,400);//设置固定窗口大小

    setWindowTitle("第一个窗口");

    PushButton1 *pb1 = new PushButton1();
    pb1->setParent(this);
    pb1->setText("关闭窗口");
    pb1->move(200,0);

    //点击按钮关闭窗口
    //参数：发送者 信号（函数的地址） 接受者 处理的槽函数
    connect(pb1,&PushButton1::clicked,this,&Widget1::close);
    //connect(pb1,&QPushButton::clicked,this,&QWidget::close);
}

Widget1::~Widget1()
{
}

