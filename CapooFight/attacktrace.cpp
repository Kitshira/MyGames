#include "attacktrace.h"
#include "configuresmanage.h"
#include <QtMath>
#include <QDebug>
AttackTrace::AttackTrace(int nowx,int nowy,int att,int a,int x,int y)
{
    sin=y/qSqrt(x*x+y*y);
    cos=x/qSqrt(x*x+y*y);
    int rot=qAtan2(sin,cos)*180/PI+90;
    c_x=nowx;
    c_y=nowy;
    attac=att;
    speed=10;
    m_Rect.moveTo(c_x,c_y);
    if(a==0){
        QPixmap image(BOSSATTACKIMAGE);
        QTransform transform;
        transform.rotate(rot+180);
        Image=image.transformed(transform);
        type=0;
        m_Rect.setWidth(Image.width());
        m_Rect.setHeight(Image.height());
    }
    else{
        QPixmap image(GUNNERATTACKIMAGE);
        QTransform transform;
        transform.rotate(rot);
        Image=image.transformed(transform);
        type=1;
        m_Rect.setWidth(Image.width());
        m_Rect.setHeight(Image.height());
    }
}
QPixmap AttackTrace::GetImage(){
    return Image;
}
int AttackTrace::getatt(){
    return attac;
}
QRectF AttackTrace::GetRect(){
    return m_Rect;
}
int AttackTrace::gettype(){
    return type;
}
int AttackTrace::getx(){
    return c_x;
}
int AttackTrace::gety(){
    return c_y;
}
int AttackTrace::getspe(){
    return speed;
}
double AttackTrace::getcos(){
    return cos;
}
double AttackTrace::getsin(){
    return sin;
}
void AttackTrace::setPosition(double a,double b){
    c_x=a;
    c_y=b;
    m_Rect.moveTo(a,b);
    return;
}
