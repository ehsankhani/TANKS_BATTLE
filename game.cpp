#include "game.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Game::Game(Player *playerOne, Player *playerTwo, QWidget *parent)
{
    this->PlayerOne = playerOne;
    this->PlayerTwo = playerTwo;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::black));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    view->show();
}
