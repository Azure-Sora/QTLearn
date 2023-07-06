#include "game.h"
#include "./ui_game.h"
#include <QMessageBox>
#include <QDialog>
#include "about.h"
#include <QRandomGenerator>
#include <QTime>
#include <QPixmap>

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    //实现菜单栏
    connect(ui->actionExit,&QAction::triggered,[=](){
        if(QMessageBox::question(this,"提示","要退出吗？") == QMessageBox::Yes)
        {
            this->close();
        }
    });
    connect(ui->actionAbout,&QAction::triggered,[=](){
        About a;
        a.exec();
    });

    initPics();

}

void Game::initPics()
{
    this->order << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9;
    QRandomGenerator r;
    for(int i = 0; i < 9 ; i++)
    {
        this->order.swapItemsAt(i,r.generate()%9);
    }
    this->nowAt = 1;
    renewPic();
}

void Game::renewPic()
{
    if(nextPic != nullptr)
    {
        delete nextPic;
    }
    nextPic = new QImage(":/Image/pictureLong/_0" + QString::number(nowAt) + ".jpg");
    ui->pic_next->setPixmap(QPixmap::fromImage(*nextPic));
}

Game::~Game()
{
    delete ui;
}

