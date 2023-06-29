#include "weapon.h"
#include "configuresmanage.h"
weapon::weapon(int a)
{
    switch (a) {
       case 0:
        attarea=110;
        att=25;
        frequen=1000;
        type=0;
        break;
       case 1:
        attarea=350;
        att=3;
        frequen=300;
        type=1;
        break;
       case 2:
        attarea=350;
        att=20;
        frequen=1000;
        type=1;
       break;
       default:
        attarea=110;
        att=25;
        frequen=1000;
        type=0;
    }
}

int weapon::getareasqr(){
    return attarea*attarea;
}
int weapon::getatt(){
    return att;
}
int weapon::gettype(){
    return type;
}
int weapon::getfrequen(){
    return frequen;
}
