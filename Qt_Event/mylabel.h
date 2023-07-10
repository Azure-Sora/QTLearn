#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void enterEvent(QEnterEvent *event) override;
    //离开事件
    void leaveEvent(QEvent *event) override;

    //重写鼠标事件
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

    virtual void mouseMoveEvent(QMouseEvent *ev) override;

    bool event(QEvent *e) override;


signals:

};

#endif // MYLABEL_H
