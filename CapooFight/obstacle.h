#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QPixmap>
class obstacle
{
public:
    obstacle();
    int getx();
    int gety();
    int gettype();
    QPixmap getimg();
    QRectF getrect();
private:
    QRectF obs;
    QPixmap obsimg1;
    QPixmap obsimg2;

    int type;
    int o_x;
    int o_y;
};

#endif // OBSTACLE_H
