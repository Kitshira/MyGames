#include "chest.h"
#include "configuresmanage.h"
Chest::Chest(double a,double b)
{
   c_x=a;
   c_y=b;
   img.load(PATH_CHEST);
   m_Rect.setHeight(img.height());
   m_Rect.setWidth(img.width());
   m_Rect.moveTo(a,b);
   time=0;
   noopend=1;
}
double Chest::getx(){
    return c_x;
}
double Chest::gety(){
    return c_y;
}
QPixmap Chest::getimg(){
    return img;
}
QRectF Chest::getRect(){
    return m_Rect;
}
int Chest::gettime(){
    return time;
}
void Chest::addtime(int a){
    time+=a;
    return;
}
bool Chest::neveropend(){
    return noopend;
}
void   Chest::open(){
    noopend=0;
}
