#include "game.h"
#include "player.h"
#include "wall.h"
#include "boxitem.h"
#include "forest.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Game::Game(Player *playerOne, Player *playerTwo, Map *board, QWidget *parent)
{
    this->PlayerOne = playerOne;
    this->PlayerTwo = playerTwo;
    this->Board = board;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::white));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(this->Board->GetBoard()[0].length() * 50, this->Board->GetBoard().length() * 50);
    scene->setSceneRect(0, 0, this->Board->GetBoard()[0].length() * 50, this->Board->GetBoard().length() * 50);
    view->show();
    for(int i = 0; i < board->GetBoard().length(); i++)
    {
        for(int j = 0; j < board->GetBoard()[i].length(); j++)
        {
            if(board->GetBoard()[i][j] == 1)
            {
                Wall *wall = new Wall(j * 50, i * 50);
                scene->addItem(wall);
            }
            else if(board->GetBoard()[i][j] == 2)
            {
                BoxItem *box = new BoxItem(j * 50, i * 50);
                scene->addItem(box);
            }
            else if(board->GetBoard()[i][j] == 3)
            {
                Forest *forest = new Forest(j * 50, i * 50);
                scene->addItem(forest);
            }
        }
    }
}
