#include "initialmenu.h"
#include "configuresmanage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Datas* d=new Datas(3);
    d->readConfig();
    InitialMenu * w= new InitialMenu();
    w->show();
    return a.exec();
}
