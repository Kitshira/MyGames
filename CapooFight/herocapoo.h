#ifndef HEROCAPOO_H
#define HEROCAPOO_H

#include <QPixmap>
#include "weapon.h"
#include "enemy.h"
#include "attacktrace.h"
class HeroCapoo
{
public:
    HeroCapoo(int type,int c_x,int c_y,int cspebuff,int catkbuff,int cdefbuff,int level,int exp,int hp);  //生成主角

    bool attack(enemy* a); //攻击

    void setPosition(int x,int y);
    void setTowardsleft();
    void setTowardsright();

    QPixmap GetCapoosImage();

    double getx();
    double gety();

    QRectF getRect();

    int gethp();
    int getspe();
    int getspebuff();
    int getexp();
    int getatk();
    int getdef();
    weapon getweapon();
    int getlevel();

    void behurt(int a);

    void AddImage();
    void ResetImage();

    bool expup(int a);

    void DefEn();
    void AtkEn();
    void SpeEn();
private:

    QPixmap capooimage_Towardsleft[4];
    QPixmap capooimage_Towardsright[4];
    bool towardsleft;

    double c_x;
    double c_y;

    QRectF m_Rect;

    int hp;
    weapon m_weapon;
    int spe;
    int spebuff;

    int atkbuff;
    int exp;
    int level;
    int defbuff;

    int ImageCount;
};

#endif // HEROCAPOO_H
