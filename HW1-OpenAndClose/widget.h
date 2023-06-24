#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widget2.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Widget2 *widget2 = nullptr;
};
#endif // WIDGET_H
