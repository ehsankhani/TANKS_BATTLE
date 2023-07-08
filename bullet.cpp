#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "bullet.h"
#include "boxitem.h"
#include "wall.h"
#include "player.h"

Bullet::Bullet(int direction, int power, bool firstPlayer)
{
    this->Direction = direction;
    this->Power = power;
    this->FirstPlayer = firstPlayer;
    if(direction == 1)
        setPixmap(QPixmap(":/new/Images/FireImages/Fire_UP.png"));
    else if(direction == 2)
        setPixmap(QPixmap(":/new/Images/FireImages/Fire_Left.png"));
    else if(direction == 3)
        setPixmap(QPixmap(":/new/Images/FireImages/Fire_Right.png"));
    else
        setPixmap(QPixmap(":/new/Images/FireImages/Fire_Down.png"));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(10);
}

extern Game *game;
void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) ==typeid (Player))
        {
            game->ReduceHealth(this->Power, this->FirstPlayer);
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Bullet) || typeid(*(colliding_items[i])) == typeid(BoxItem))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if(this->Direction == 1)
    {
        setPos(x(), y()-5);
        if(pos().y() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(this->Direction == 2)
    {
        setPos(x()-5, y());
        if(pos().x() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(this->Direction == 3)
    {
        setPos(x()+5, y());
        if(pos().x() > scene()->width())
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else
    {
        setPos(x(), y()+5);
        if(pos().y() > scene()->height())
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
