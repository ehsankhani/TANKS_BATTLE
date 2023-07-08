#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "map.h"
#include "messageitem.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game:public QGraphicsView
{
private:
    Player *PlayerOne;
    Player *PlayerTwo;
    Map *Board;
    QWidget *Parent;
    MessageItem *ShildOne;
    MessageItem *ShildTwo;
public:
    QGraphicsScene *scene;
    Game(QWidget *parent=0);
    void Start(Player *playerOne, Player *playerTwo, Map *board, QWidget *parent=0);
    void KeySend(int keyInfo);
};

#endif // GAME_H
