#include "customsignalandslot.h"

#include <QApplication>//包含应用程序类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//应用程序对象，有且仅有一个
    CustomSignalAndSlot w;//窗口对象
    w.show();
    return a.exec();//让应用程序进入消息循环，使代码阻塞到这一行
}
