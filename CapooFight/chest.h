#ifndef CHEST_H
#define CHEST_H

#include <QRect>
#include <QPixmap>
#include "configuresmanage.h"
class Chest
{
public:
    Chest(double a,double b);
    QRectF getRect();
    QPixmap getimg();
    double getx();
    double gety();
    int gettime();
    void addtime(int a);
    bool neveropend();
    void open();
private:
    QRectF m_Rect;
    QPixmap img;
    double c_x;
    double c_y;
    int time;
    bool noopend;
};

#endif // CHEST_H
