#include "wall.h"

Wall::Wall(int x, int y, QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/new/Images/OtherImage/wall.png"));
    setPos(x, y);
}
