#include "boxitem.h"

BoxItem::BoxItem(int x, int y, QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/new/Images/OtherImage/box.png"));
    setPos(x, y);
}
