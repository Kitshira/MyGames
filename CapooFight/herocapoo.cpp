#include "herocapoo.h"
#include "configuresmanage.h"
#include <QDebug>
HeroCapoo::HeroCapoo(int type,int cc_x,int cc_y,int cspebuff,int catkbuff,int cdefbuff,int nnlevel,int nnexp,int hpremain):m_weapon(type)
{
    if(type==0){
     capooimage_Towardsleft[0].load(PATH_FIGHTERCAPOOIMAGE_LEFT1);
     capooimage_Towardsleft[1].load(PATH_FIGHTERCAPOOIMAGE_LEFT2);
     capooimage_Towardsleft[2].load(PATH_FIGHTERCAPOOIMAGE_LEFT3);
     capooimage_Towardsleft[3].load(PATH_FIGHTERCAPOOIMAGE_LEFT4);
     capooimage_Towardsright[0].load(PATH_FIGHTERCAPOOIMAGE_RIGHT1);
     capooimage_Towardsright[1].load(PATH_FIGHTERCAPOOIMAGE_RIGHT2);
     capooimage_Towardsright[2].load(PATH_FIGHTERCAPOOIMAGE_RIGHT3);
     capooimage_Towardsright[3].load(PATH_FIGHTERCAPOOIMAGE_RIGHT4);
    }
    else{
     capooimage_Towardsleft[0].load(PATH_GUNNERCAPOOIMAGE_LEFT);
     capooimage_Towardsleft[1].load(PATH_GUNNERCAPOOIMAGE_LEFT);
     capooimage_Towardsleft[2].load(PATH_GUNNERCAPOOIMAGE_LEFT);
     capooimage_Towardsleft[3].load(PATH_GUNNERCAPOOIMAGE_LEFT);
     capooimage_Towardsright[0].load(PATH_GUNNERCAPOOIMAGE_RIGHT);
     capooimage_Towardsright[1].load(PATH_GUNNERCAPOOIMAGE_RIGHT);
     capooimage_Towardsright[2].load(PATH_GUNNERCAPOOIMAGE_RIGHT);
     capooimage_Towardsright[3].load(PATH_GUNNERCAPOOIMAGE_RIGHT);
    }
    c_x=cc_x;
    c_y=cc_y;

    m_Rect.setWidth(capooimage_Towardsleft[0].width()-30);
    m_Rect.setHeight(capooimage_Towardsleft[0].height()-20);
    m_Rect.moveTo(c_x + 15,c_y + 10);

    towardsleft = 1;

    ImageCount=0;

    hp=hpremain;
    spe=4;
    spebuff=cspebuff;
    atkbuff=catkbuff;
    defbuff=cdefbuff;

    exp=nnexp;
    level=nnlevel;
}


void HeroCapoo::setTowardsleft(){
    towardsleft = 1;
}

void HeroCapoo::setTowardsright(){
    towardsleft = 0;
}

void HeroCapoo::setPosition(int x,int y){
    int a;
    if(x<-50){
        a=-50;
    }
    else if(x>MAPSIZE_X-200){
        a=MAPSIZE_X-200;
    }
    else{
        a=x;
    }
    int b;
    if(y<180){
        b=180;
    }
    else if(y>MAPSIZE_Y-100){
        b=MAPSIZE_Y-100;
    }
    else{
        b=y;
    }
    c_x=a;
    c_y=b;
    m_Rect.moveTo(a+30,b+20);
    return;
}

QPixmap HeroCapoo::GetCapoosImage(){
    if(towardsleft==1){
       return capooimage_Towardsleft[ImageCount];
    }
    else{
       return capooimage_Towardsright[ImageCount];
    }
}
void HeroCapoo::AddImage(){
     ImageCount=(ImageCount+1)%4;
     return;
}
void HeroCapoo::ResetImage(){
     ImageCount=0;
     return;
}
double HeroCapoo::getx(){
    return c_x;
}
double HeroCapoo::gety(){
    return c_y;
}

QRectF HeroCapoo::getRect(){
    return m_Rect;
}

int HeroCapoo::getatk(){
    return atkbuff;
}
int HeroCapoo::getdef(){
    return defbuff;
}
int HeroCapoo::getlevel(){
    return level;
}
int HeroCapoo::gethp(){
    return hp;
}
weapon HeroCapoo::getweapon(){
    return m_weapon;
}
int HeroCapoo::getspe(){
    Datas * a = new Datas(0);
    int totalspebuff = a->TOTALSPEBuff;
    return spe+spebuff+totalspebuff;
}
int HeroCapoo::getspebuff(){
    return spebuff;
}
int HeroCapoo::getexp(){
    return exp;
}
bool HeroCapoo::expup(int a){
    switch(a){
       case -1:
        exp+=40;
        break;
       case 1:
        exp+=8;
        break;
       case 2:
        exp+=12;
        break;
       case 3:
        exp+=12;
        break;
    }
    if(exp>=100){
        level++;
        exp=exp%100;
        return 1;
    }
    return 0;
}
bool HeroCapoo::attack(enemy* a){
    Datas * totalbuff =new Datas(0);
    if(m_weapon.gettype()==0){
      a->behurt(m_weapon.getatt()+atkbuff+totalbuff->ATKBuff);    //behurt是扣血函数，参数为int型   m_weapon是weapon类的对象，getatt()用来获得攻击力
        return 1;
    }
    else{
        return 0;
    }
}
void HeroCapoo::behurt(int a){
    Datas * buff = new Datas (0);
    hp-=a-defbuff-buff->DEFBuff>0?a-defbuff-buff->DEFBuff:0;
    return;
}
void HeroCapoo::DefEn(){
    defbuff+=3;
    Datas * buff=new Datas(0);
    buff->setGameValue("DEFBuff",defbuff);
    return;
}
void HeroCapoo::AtkEn(){
    atkbuff+=5;
    Datas * buff=new Datas(0);
    buff->setGameValue("ATKBuff",atkbuff);
    return;
}
void HeroCapoo::SpeEn(){
    spebuff+=3;
    Datas * buff=new Datas(0);
    buff->setGameValue("SPEBuff",spebuff);
    return;
}
