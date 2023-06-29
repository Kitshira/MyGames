#ifndef MAP_H
#define MAP_H
#include <QPixmap>
#include "configuresmanage.h"
#define MAP_maxy 1080
#define MAP_maxx 1728
class Map
{
public:
    Map();
    QPixmap getmap();
private:
    QPixmap m_map;
};

#endif // MAP_H
