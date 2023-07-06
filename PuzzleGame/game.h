#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT


public:
    Game(QWidget *parent = nullptr);
    void initPics();
    void renewPic();
    ~Game();

private:
    Ui::Game *ui;
    QList<int> order;
    int nowAt;
    QImage *nextPic;
};
#endif // GAME_H
