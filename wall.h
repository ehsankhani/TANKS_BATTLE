#ifndef WALL_H
#define WALL_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Wall:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wall(int x, int y, QGraphicsItem *parent=0);
};

#endif // WALL_H
