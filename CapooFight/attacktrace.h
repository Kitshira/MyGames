#ifndef ATTACKTRACE_H
#define ATTACKTRACE_H

#include <QPixmap>
#include <QRect>

class AttackTrace
{
public:
    AttackTrace(int nowx,int nowy,int att,int type,int x,int y);
    QPixmap GetImage();
    QRectF GetRect();
    int gettype();
    int getatt();
    int getx();
    int gety();
    int getspe();
    double getcos();
    double getsin();
    void setPosition(double a,double b);
private:
    QPixmap Image;
    QRectF m_Rect;
    int attac;
    int speed;
    int type;
    double cos;
    double sin;
    int c_x;
    int c_y;
};

#endif // ATTACKTRACE_H
