#ifndef FOREST_H
#define FOREST_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Forest:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Forest(int x, int y, QGraphicsItem *parent=0);
};

#endif // FOREST_H
