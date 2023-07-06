#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->bt_tabWidget, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->bt_ScrollArea, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->bt_ToolBox, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    ui->comboBox->addItems(QStringList() << "华为" << "小米" << "苹果");

}

Widget::~Widget()
{
    delete ui;
}

