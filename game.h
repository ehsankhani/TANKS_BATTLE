#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "map.h"
#include "Tank.h"
#include "messageitem.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QList>

class Game:public QGraphicsView
{
private:
    Player *PlayerOne;
    Player *PlayerTwo;
    QWidget *Parent;
    MessageItem *ShildOne;
    MessageItem *ShildTwo;
    QGraphicsView *view;
public:
    QList<Map> Maps;
    QList<Tank> Tanks;
    int MapIndex;
    Game(QWidget *parent=0);
public slots:
    void Start(Player *playerOne, Player *playerTwo, int mapIndex, QWidget *parent=0);
    void KeySend(int keyInfo);
    void ReduceHealth(int power, bool firstPlayer);
};

#endif // GAME_H
