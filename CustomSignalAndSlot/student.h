#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    //槽函数可直接写在public下，也可以写在全局区
    //返回值为void，需要声明与实现
    //可以有参，可以重载

    void treat();
    void treat(QString foodName);

signals:

};

#endif // STUDENT_H
