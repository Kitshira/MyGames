#include "obstacle.h"
#include "configuresmanage.h"
obstacle::obstacle()
{
    obsimg1.load(PATH_AOBSTACLE);
    obsimg2.load(PATH_BOBSTACLE);

    o_x = -50 + qrand()%1560;
    if(o_x>506&&o_x<1013){
        o_x=o_x+506;
    }
    o_y = 360 + qrand()%650;
    if(o_y>250&&o_y<500){
        o_y=o_y+200;
    }

    type=qrand()%2;

    obs.setWidth(getimg().width()-10);
    obs.setHeight(getimg().height()-5);
    obs.moveTo(o_x+5,o_y+2);
}
int obstacle:: getx(){
    return o_x;
}

int obstacle:: gety(){
    return o_y;
}

QPixmap obstacle::getimg(){
    if(type==0){
        return obsimg1;
    }
    else{
        return obsimg2;
    }
}

QRectF obstacle::getrect(){
    return obs;
}
