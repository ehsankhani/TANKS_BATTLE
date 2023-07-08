#ifndef BOXITEM_H
#define BOXITEM_H
#include <QGraphicsPixmapItem>
#include <QObject>

class BoxItem:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BoxItem(int x, int y, QGraphicsItem *parent=0);
};

#endif // BOXITEM_H
