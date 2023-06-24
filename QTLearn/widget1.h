#ifndef WIDGET1_H//防止重复包含
#define WIDGET1_H

#include <QWidget>//包含QWidget窗口类

class Widget1 : public QWidget//继承于QWidget类
{
    Q_OBJECT//Q_OBJECT宏，允许类中使用信号和槽

public:
    Widget1(QWidget *parent = nullptr);//构造函数的默认参数
    ~Widget1();
};
#endif // WIDGET1_H
