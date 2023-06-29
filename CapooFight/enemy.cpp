#include "enemy.h"
#include "configuresmanage.h"
#include <QDebug>
#include <QtMath>
enemy::enemy(int p)
{
   if(p!=1){
    exist=1;
    beinghurt=false;
    int a=qrand()%100;
    if(a%7==0){
        type=3;
    }
    else if(a%4==0){
        type=2;
    }
    else{
        type=1;
    }
    switch(type){
     case 1:
        enemyimage[0].load(PATH_PRIMARYENEMY);
        enemyimage[1].load(PATH_PRIMARYENEMY1);
        m_Rect.setWidth(enemyimage[0].width()+90);
        m_Rect.setHeight(enemyimage[0].height()+90);
        hp = 25;
        attack = 15;
        spe = 2;
        attackarea=80;
        break;
     case 2:
        enemyimage[0].load(PATH_MIDDLEENEMY);
        enemyimage[1].load(PATH_MIDDLEENEMY1);
        m_Rect.setWidth(enemyimage[0].width()+90);
        m_Rect.setHeight(enemyimage[0].height()+90);
        hp = 45;
        attack = 20;
        spe = 2;
        attackarea=60;
        break;
     case 3:
        enemyimage[0].load(PATH_GIFTENEMY);
        m_Rect.setWidth(enemyimage[0].width()+90);
        m_Rect.setHeight(enemyimage[0].height()+90);
        hp = 1;
        attack = 0;
        spe = 3;
        attackarea=0;
        break;
     default:
        enemyimage[0].load(PATH_GIFTENEMY);
        m_Rect.setWidth(enemyimage[0].width()+30);
        m_Rect.setHeight(enemyimage[0].height()+30);
        hp = 1;
        attack = 0;
        spe = 3;
        attackarea=0;
        break;
    }
    if(a%2==0){
        c_x=qrand()%MAPSIZE_X;
        movetype=0;
        if(a%4==0){
            c_y=200;
            movetowa=1;
        }
        else{
            c_y=MAPSIZE_Y-100;
            movetowa=-1;
        }
    }
    else if(a%3==0){
        c_y=200+qrand()%800;
        movetype=1;
        if(a%6==0){
              c_x=10;
              movetowa=1;
        }
        else{
              c_x=1600;
              movetowa=-1;
        }
    }
    else{
        c_x=qrand()%MAPSIZE_X;
        c_y=200+qrand()%800;
        movetype=2;
    }
    m_Rect.moveTo(c_x,c_y);
   }
   else if(p==1){
       type = -1;
       movetype=2;
       movetowa=-1;
       hp = 200;
       attack=0;
       attackarea=0;
       spe = 1;
       enemyimage[0].load(PATH_BOSSLEFT);
       enemyimage[1].load(PATH_BOSSRIGHT);
       m_Rect.setWidth(enemyimage[0].width()+90);
       m_Rect.setHeight(enemyimage[0].height()+90);
       exist=1;
       beinghurt=false;
       int a=qrand();
       if(a%2==0){
           c_x=qrand()%MAPSIZE_X;
           if(a%4==0){
               c_y=200;
           }
           else{
               c_y=MAPSIZE_Y-100;
           }
       }
       else if(a%3==0){
           c_y=200+qrand()%800;
           if(a%6==0){
                 c_x=10;
           }
           else{
                 c_x=1600;
           }
       }
       else{
           c_x=qrand()%MAPSIZE_X;
           c_y=200+qrand()%800;
       }
       m_Rect.moveTo(c_x,c_y);
      }
}

void enemy::setPosition(double x, double y){
    c_x = x;
    c_y = y;
    m_Rect.moveTo(x,y);
    return;
}

double enemy::getx(){
    return c_x;
}

double enemy::gety(){
    return c_y;
}

bool enemy::_beingatt(){
    return beinghurt;
}
void enemy::resetbeingatt(){
    beinghurt=false;
}

QPixmap enemy::getimg(){
        if(beinghurt){
           return enemyimage[1];
        }
        else{
           return enemyimage[0];
        }
}

QRectF enemy::getRect(){
    return m_Rect;
}

int enemy::gettype(){
    return type;
}
int enemy::gethp(){
    return hp;
}
int enemy::getatt(){
    return attack;
}
int enemy::getspe(){
    return spe;
}
bool enemy::eexist(){
    return exist;
}
int enemy::getmovetype(){
    return movetype;
}
int enemy::getmovetowa(){
    return movetowa;
}
int enemy::getattackareasqu(){
    return attackarea*attackarea;
}
void enemy::turnmovetowa(){
    movetowa*=-1;
    return;
}
void enemy::resethp(int a){
    hp=a;
}
bool enemy::behurt(int a){
    this->hp-=a;
    if(hp<=0){
        exist=0;
    }
    beinghurt=!beinghurt;
    return beinghurt;
}
QPixmap enemy::getleftimg(){
      return enemyimage[0];
}
QPixmap enemy::getrightimg(){
      return enemyimage[1];
}
