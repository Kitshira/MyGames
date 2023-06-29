#ifndef WEAPON_H
#define WEAPON_H
#include <QTimer>

class weapon
{
public:
    weapon(int a);
    int getareasqr();
    int getatt();
    int getfrequen();
    int gettype();
private:
    int attarea;
    int att;
    int frequen;
    int type;
};

#endif // WEAPON_H
