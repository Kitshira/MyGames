#ifndef CONFIGURESMANAGE_H
#define CONFIGURESMANAGE_H

#define PATH_MAPIMAGE ":/img/ImagesForCapoo/GameBackGround.jpg"
#define MAPSIZE_X 1728
#define MAPSIZE_Y 1080
#define PATH_FIGHTERCAPOOIMAGE_LEFT1  ":/img/ImagesForCapoo/ModeFighter-left1.png"
#define PATH_FIGHTERCAPOOIMAGE_LEFT2  ":/img/ImagesForCapoo/ModeFighter-left2.png"
#define PATH_FIGHTERCAPOOIMAGE_LEFT3  ":/img/ImagesForCapoo/ModeFighter-left3.png"
#define PATH_FIGHTERCAPOOIMAGE_LEFT4  ":/img/ImagesForCapoo/ModeFighter-left4.png"
#define PATH_FIGHTERCAPOOIMAGE_RIGHT1 ":/img/ImagesForCapoo/ModeFighter-right1.png"
#define PATH_FIGHTERCAPOOIMAGE_RIGHT2 ":/img/ImagesForCapoo/ModeFighter-right2.png"
#define PATH_FIGHTERCAPOOIMAGE_RIGHT3 ":/img/ImagesForCapoo/ModeFighter-right3.png"
#define PATH_FIGHTERCAPOOIMAGE_RIGHT4 ":/img/ImagesForCapoo/ModeFighter-right4.png"
#define PATH_GUNNERCAPOOIMAGE_LEFT ":/img/ImagesForCapoo/ModeGunner-left.png"
#define PATH_GUNNERCAPOOIMAGE_RIGHT ":/img/ImagesForCapoo/ModeGunner-right.png"
#define PATH_PRIMARYENEMY ":/img/ImagesForCapoo/enemy1.png"
#define PATH_PRIMARYENEMY1 ":/img/ImagesForCapoo/enemy1-hitted.png"
#define PATH_MIDDLEENEMY ":/img/ImagesForCapoo/enemy2.png"
#define PATH_MIDDLEENEMY1 ":/img/ImagesForCapoo/enemy2-hitted.png"
#define PATH_GIFTENEMY ":/img/ImagesForCapoo/enemy3.png"
#define PATH_GIFTENEMY1 ":/img/ImagesForCapoo/enemy3.png"
#define PATH_BOSSLEFT ":/img/ImagesForCapoo/boss-left.png"
#define PATH_BOSSRIGHT ":/img/ImagesForCapoo/boss-right.png"
#define PATH_AOBSTACLE ":/img/ImagesForCapoo/obsroc.png"
#define PATH_BOBSTACLE ":/img/ImagesForCapoo/obsrock1.png"
#define CheckTime 55
#define BOSSATTACKIMAGE ":/img/ImagesForCapoo/BossAttack.png"
#define GUNNERATTACKIMAGE  ":/img/ImagesForCapoo/GunnerAttack.png"
#define PI 3.14159
#define PATH_CHEST ":/img/ImagesForCapoo/Chest.png"
#define PATH_SHOW ":/img/ImagesForCapoo/ShowLove.gif"

#include <QString>
#include <QSettings>
class Datas{
public:
    static int GoldRemain;
    static int TOTALDEFBuff;
    static int TOTALSPEBuff;

    static int TYPE;
    static double C_X;
    static double C_Y;
    static int ATKBuff;
    static int DEFBuff;
    static int SPEBuff;
    static int HP;
    static int LEVEL;
    static int EXP;

    explicit Datas(int a);

    void readConfig();

    void writeConfig();

    int getGameValue(const QString &key);

    void setGameValue(const QString &key,int value);

    void clearConfig();

private:
    QSettings * settings;
    QSettings * totalsetting;
};


#endif // CONFIGURESMANAGE_H
