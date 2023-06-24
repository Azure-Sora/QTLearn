#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);

    //菜单栏创建 最多只能有一个
    QMenuBar *menuBar = new QMenuBar(this);
    //将菜单栏放入窗口
    setMenuBar(menuBar);
    //创建菜单
    QMenu *fileMenu = menuBar->addMenu("文件");
    QMenu *editMenu = menuBar->addMenu("编辑");
    //创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator(); //添加分隔线
    QAction *openAction = fileMenu->addAction("打开");


    //工具栏 可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //禁止浮动
    toolBar->setFloatable(false);
    //设置移动总开关
//    toolBar->setMovable(false);
    //在工具栏中添加内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //添加一些控件
    QPushButton *btn1 = new QPushButton(this);
    toolBar->addWidget(btn1);


    //状态栏 最多有一个
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    //标签控件
    QLabel *label1 = new QLabel("信息1",this);
    statusBar->addWidget(label1);
    QLabel *label2 = new QLabel("右侧信息",this);
    statusBar->addPermanentWidget(label2);//永久的即为在右侧


    //铆接部件（浮动窗口） 可以有多个
    QDockWidget *dock = new QDockWidget("铆接部件",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    //设置允许的停靠区域
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);


    //中心部件 仅一个
    //例：记事本
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

