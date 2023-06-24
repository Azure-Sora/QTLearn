#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->teacher = new Teacher(this);
    this->stu = new Student(this);

    QPushButton *btn = new QPushButton("下课",this);
    this->resize(600,400);

//    connect(teacher,&Teacher::hungry,stu,&Student::treat);
    //指针指向地址，函数指针指向函数地址
    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(teacher,teacherSignal,stu,studentSlot);
//    classIsOver();

    //无参
    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void(Student::*studentSlot2)(void) = &Student::treat;
    connect(teacher,teacherSignal2,stu,studentSlot2);

    //信号连接信号
//    connect(btn,&QPushButton::clicked,teacher,teacherSignal2);

    //断开信号
//    disconnect(btn,&QPushButton::clicked,teacher,teacherSignal2);

    //一个信号可以连接多个槽函数
//    connect(btn,&QPushButton::clicked,this,&QWidget::close);
    //多个信号可以连接同一个槽函数

    //Qt4语法
    connect(btn, SIGNAL(clicked()), teacher, SIGNAL(hungry()));
    //优点：语法简单；缺点：类型不做检测

    //lambda
//    [=](){btn->setText("aaaa");}();
    QPushButton *btn2 = new QPushButton("关闭",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this, [=](){
        this->close();
        emit teacher->hungry("鱼香肉丝");
    } );
}

void Widget::classIsOver()
{
    //触发信号
//    emit teacher->hungry();
    emit teacher->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}


