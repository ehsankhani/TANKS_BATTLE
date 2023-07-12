#ifndef MAPCREATORITEM_H
#define MAPCREATORITEM_H
#include <QGraphicsPixmapItem>
#include <QObject>

class MapCreatorItem:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int LocationI, LocationJ;
    bool IsSaveButton;
    int Type;
    MapCreatorItem(int x, int y, bool isSaveButton, QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAPCREATORITEM_H
