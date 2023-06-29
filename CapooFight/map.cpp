#include "map.h"
#include "configuresmanage.h"
Map::Map()
{
    m_map.load(PATH_MAPIMAGE);
}

QPixmap Map:: getmap(){
    return m_map;
}
