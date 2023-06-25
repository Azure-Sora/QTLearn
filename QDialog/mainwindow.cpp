#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建，弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=](){
        //对话框分类
        //模态对话框：出现后不可以操作其他窗口
        //非模态对话框：出现后可以操作其他窗口

        //模态对话框创建
//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();

        //非模态对话框创建
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose,true);

        //消息对话框
        //错误对话框
//        QMessageBox::critical(this,"critical","错误");
        //信息对话框
//        QMessageBox::information(this,"information","信息");
        //提问对话框
//        if(QMessageBox::Save == QMessageBox::question(this,"question","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug() << "保存";
//        }
//        else
//        {
//            qDebug() << "取消";
//        }
        //警告对话框
//        QMessageBox::warning(this,"warning","警告");

        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << color.red();

        //文件对话框
//        QString filePath = QFileDialog::getOpenFileName(this,"打开文件","E:\\","(*.txt)");
//        qDebug() << filePath;
        //参数：parent 标题 默认打开路径 过滤的文件格式
        //返回值：文件路径

        //字体对话框
//        bool flag;
//        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));

        //输入对话框
        int num = QInputDialog::getInt(this,"输入int","label");
        qDebug() << num;

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

