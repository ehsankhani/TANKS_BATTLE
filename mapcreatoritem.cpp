#include "mapcreatoritem.h"
#include "mapcreator.h"

MapCreatorItem::MapCreatorItem(int x, int y, bool isSaveButton, QGraphicsItem *parent)
{
    this->Type = 0;
    this->IsSaveButton = isSaveButton;
    if(!IsSaveButton)
        setPixmap(QPixmap(":/new/Images/OtherImage/Blank.png"));
    else
        setPixmap(QPixmap(":/new/Images/OtherImage/save.png"));
    setPos(x, y);
}

extern MapCreator *mapCreator;
void MapCreatorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!IsSaveButton)
    {
        if(Type == 0)
        {
            Type = 1;
            setPixmap(QPixmap(":/new/Images/OtherImage/wall.png"));
        }
        else if(Type == 1)
        {
            Type = 2;
            setPixmap(QPixmap(":/new/Images/OtherImage/box.png"));
        }
        else if(Type == 2)
        {
            Type = 3;
            setPixmap(QPixmap(":/new/Images/OtherImage/Forest.png"));
        }
        else if(Type == 3)
        {
            Type = 0;
            setPixmap(QPixmap(":/new/Images/OtherImage/Blank.png"));
        }
        mapCreator->map->SetBoard(LocationI, LocationJ, Type);
    }
    else
    {
        mapCreator->Save();
    }
}
