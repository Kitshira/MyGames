#ifndef BOSSENEMY_H
#define BOSSENEMY_H
#include <enemy.h>
#include <weapon.h>
class BossEnemy : public  enemy
{
public:
    BossEnemy();
    ~BossEnemy();
    weapon GetWeapon();
private:
    weapon bossweapon;
};

#endif // BOSSENEMY_H
