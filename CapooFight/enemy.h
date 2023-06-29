#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>

class enemy
{
public:
    enemy(int a);
    void generate();
    void move();
    void att();
    QPixmap GetCapoosImage();
    void setPosition(double x,double y);
    double getx();
    double gety();
    QPixmap getimg();
    QRectF getRect();
    int gethp();
    int gettype();
    int getatt();
    int getspe();
    bool behurt(int a);
    bool eexist();
    int getmovetype();
    int getmovetowa();
    int getattackareasqu();
    void turnmovetowa();
    bool _beingatt();
    void resetbeingatt();
    void resethp(int a);
    QPixmap getleftimg();
    QPixmap getrightimg();
private:
    int type;
    int movetype;
    int movetowa;
    int hp;
    int attack;
    int spe;
    int attackarea;
    bool exist;
    bool beinghurt;
    QPixmap enemyimage[2];

    double c_x;
    double c_y;

    QRectF m_Rect;
};

#endif // ENEMY_H
