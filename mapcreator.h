#ifndef MAPCREATOR_H
#define MAPCREATOR_H
#include "map.h"
#include <QGraphicsView>

class MapCreator:public QGraphicsView
{
private:
    QGraphicsView *view;
public:
    Map *map;
    MapCreator(QWidget *parent = 0);
    void Start();
    void Save();
};

#endif // MAPCREATOR_H
