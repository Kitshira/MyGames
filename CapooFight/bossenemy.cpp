#include "bossenemy.h"
#include "configuresmanage.h"
BossEnemy::BossEnemy():enemy(1),bossweapon(2)
{

}
weapon BossEnemy::GetWeapon(){
    return bossweapon;
}
BossEnemy::~BossEnemy(){

}
