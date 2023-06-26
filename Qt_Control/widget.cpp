#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮
    ui->radioButton_man->setChecked(true);

    //选中女后打印信息
    connect(ui->radioButton_woman,&QRadioButton::clicked,[=](){
        qDebug() << "选中女";
    });

    //多选按钮
    connect(ui->checkBox_service,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用ListWidget写诗
//    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);

    //treeWidget使用
    //设置表头
    ui->treeWidget->setHeaderLabels(QStringList() << "角色" << "简介");
    QTreeWidgetItem *swordItem = new QTreeWidgetItem(QStringList() << "单手剑");
    QTreeWidgetItem *magicItem = new QTreeWidgetItem(QStringList() << "法器");
    QTreeWidgetItem *bowItem = new QTreeWidgetItem(QStringList() << "弓");
    //顶层节点
    ui->treeWidget->addTopLevelItem(swordItem);
    ui->treeWidget->addTopLevelItem(magicItem);
    ui->treeWidget->addTopLevelItem(bowItem);
    //子节点
    QTreeWidgetItem *keqing = new QTreeWidgetItem(QStringList() << "刻晴" << "雷元素");
    swordItem->addChild(keqing);


    //tableWidget
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "名字" << "学院" << "战术位置");
    //设置行数
    ui->tableWidget->setRowCount(3);
    //设置正文
    QStringList names;
    names << "未花" << "响" << "日奈";
    QStringList schools;
    schools << "崔妮蒂" << "千禧年" << "歌赫娜";
    QStringList positions;
    positions << "STRICKER" << "SUPPORT" << "STRICKER";
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(names[i]));
    }
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(schools[i]));
    }
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(positions[i]));
    }

}

Widget::~Widget()
{
    delete ui;
}

