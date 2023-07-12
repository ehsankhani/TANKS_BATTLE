#include "game.h"
#include "player.h"
#include "wall.h"
#include "boxitem.h"
#include "forest.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include "winnerinfo.h"
#include "mainwindow.h"
#include <QMediaPlayer>
#include <QApplication>
#include <QDir>

Game::Game(QWidget *parent)
{
    this->Parent = parent;
}

void Game::Start(Player *playerOne, Player *playerTwo, int mapIndex, QWidget *parent)
{
    this->PlayerOne = playerOne;
    this->PlayerTwo = playerTwo;
    this->MapIndex = mapIndex;
    this->Parent = parent;
    QGraphicsScene *scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::white));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(this->Maps[MapIndex].GetBoard()[0].length() * 50 + 5, this->Maps[MapIndex].GetBoard().length() * 50 + 35);
    scene->setSceneRect(0, 0, this->Maps[MapIndex].GetBoard()[0].length() * 50 + 5, this->Maps[MapIndex].GetBoard().length() * 50 + 35);
    view->show();
    this->ShildOne = new MessageItem(this->PlayerOne->GetName() + " : " + QString::number(this->PlayerOne->GetHealth()), this->PlayerOne->tank->GetColor());
    this->ShildTwo = new MessageItem(this->PlayerTwo->GetName() + " : " + QString::number(this->PlayerTwo->GetHealth()), this->PlayerTwo->tank->GetColor());
    this->ShildTwo->setPos(view->x() - 50, 0);
    scene->addItem(ShildOne);
    scene->addItem(ShildTwo);
    for(int i = 0; i < Maps[MapIndex].GetBoard().length(); i++)
    {
        for(int j = 0; j < Maps[MapIndex].GetBoard()[i].length(); j++)
        {
            if(Maps[MapIndex].GetBoard()[i][j] == 1)
            {
                Wall *wall = new Wall(j * 50, i * 50 + 30);
                scene->addItem(wall);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 2)
            {
                BoxItem *box = new BoxItem(j * 50, i * 50 + 30);
                scene->addItem(box);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 3)
            {
                Forest *forest = new Forest(j * 50, i * 50 + 30);
                scene->addItem(forest);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 5)
            {
                scene->addItem(playerOne);
                playerOne->setFlag(QGraphicsItem::ItemIsFocusable);
                playerOne->setFocus();
                playerOne->setPos(j * 50, i * 50 + 30);
            }
            else if(Maps[MapIndex].GetBoard()[i][j] == 6)
            {
                scene->addItem(PlayerTwo);
                PlayerTwo->setPos(j * 50, i * 50 + 30);
            }
        }
    }
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/Musics/Musics/bgsound.mp3"));
    music->play();
}

void Game::KeySend(int keyInfo)
{
    int currentXPlayerOne = -1, currentYPlayerOne = -1;
    int currentXPlayerTwo = -1, currentYPlayerTwo = -1;
    for(int i = 0; i < this->Maps[MapIndex].GetBoard().length(); i++)
    {
        for(int j = 0; j < this->Maps[MapIndex].GetBoard()[i].length(); j++)
        {
            if(this->Maps[MapIndex].GetBoard()[i][j] == 5)
            {
                currentXPlayerOne = j;
                currentYPlayerOne = i;
            }
            else if(this->Maps[MapIndex].GetBoard()[i][j] == 6)
            {
                currentXPlayerTwo = j;
                currentYPlayerTwo = i;
            }
        }
    }
    if(currentXPlayerOne == -1 || currentXPlayerTwo == -1)
        return;
    if(keyInfo == Qt::Key_Up)
    {
        if(!PlayerOne->dirFlag)
            return;
        if(currentYPlayerOne == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerOne - 1][currentXPlayerOne] != 0)
        {
            PlayerOne->Direction = 1;
            PlayerOne->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne - 1, currentXPlayerOne, 5);
        PlayerOne->ChangeDirection(1);
    }
    else if(keyInfo == Qt::Key_Left)
    {
        if(!PlayerOne->dirFlag)
            return;
        if(currentXPlayerOne == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerOne][currentXPlayerOne - 1] != 0)
        {
            PlayerOne->Direction = 2;
            PlayerOne->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne - 1, 5);
        PlayerOne->ChangeDirection(2);
    }
    else if(keyInfo == Qt::Key_Right)
    {
        if(!PlayerOne->dirFlag)
            return;
        if(currentXPlayerOne + 1 >= this->Maps[MapIndex].GetBoard()[currentYPlayerOne].length() || this->Maps[MapIndex].GetBoard()[currentYPlayerOne][currentXPlayerOne + 1] != 0)
        {
            PlayerOne->Direction = 3;
            PlayerOne->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne + 1, 5);
        PlayerOne->ChangeDirection(3);
    }
    else if(keyInfo == Qt::Key_Down)
    {
        if(!PlayerOne->dirFlag)
            return;
        if(currentYPlayerOne + 1 >= this->Maps[MapIndex].GetBoard().length() || this->Maps[MapIndex].GetBoard()[currentYPlayerOne + 1][currentXPlayerOne] != 0)
        {
            PlayerOne->Direction = 4;
            PlayerOne->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerOne, currentXPlayerOne, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerOne + 1, currentXPlayerOne, 5);
        PlayerOne->ChangeDirection(4);
    }
    else if(keyInfo == Qt::Key_K)
    {
        if(!PlayerOne->flag)
            return;
        PlayerOne->Fire();
    }
    else if(keyInfo == Qt::Key_W)
    {
        if(!PlayerTwo->dirFlag)
            return;
        if(currentYPlayerTwo == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo - 1][currentXPlayerTwo] != 0)
        {
            PlayerTwo->Direction = 1;
            PlayerTwo->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo - 1, currentXPlayerTwo, 6);
        PlayerTwo->ChangeDirection(1);
    }
    else if(keyInfo == Qt::Key_A)
    {
        if(!PlayerTwo->dirFlag)
            return;
        if(currentXPlayerTwo == 0 || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo][currentXPlayerTwo - 1] != 0)
        {
            PlayerTwo->Direction = 2;
            PlayerTwo->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo - 1, 6);
        PlayerTwo->ChangeDirection(2);
    }
    else if(keyInfo == Qt::Key_D)
    {
        if(!PlayerTwo->dirFlag)
            return;
        if(currentXPlayerTwo + 1 >= this->Maps[MapIndex].GetBoard()[currentYPlayerTwo].length() || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo][currentXPlayerTwo + 1] != 0)
        {
            PlayerTwo->Direction = 3;
            PlayerTwo->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo + 1, 6);
        PlayerTwo->ChangeDirection(3);
    }
    else if(keyInfo == Qt::Key_S)
    {
        if(!PlayerTwo->dirFlag)
            return;
        if(currentYPlayerTwo + 1 >= this->Maps[MapIndex].GetBoard().length() || this->Maps[MapIndex].GetBoard()[currentYPlayerTwo + 1][currentXPlayerTwo] != 0)
        {
            PlayerTwo->Direction = 4;
            PlayerTwo->SetImage();
            return;
        }
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo, currentXPlayerTwo, 0);
        this->Maps[MapIndex].SetBoard(currentYPlayerTwo + 1, currentXPlayerTwo, 6);
        PlayerTwo->ChangeDirection(4);
    }
    else if(keyInfo == Qt::Key_C)
    {
        if(!PlayerTwo->flag)
            return;
        PlayerTwo->Fire();
    }
}

void Game::ReduceHealth(int power, bool firstPlayer)
{
    if(firstPlayer)
    {
        PlayerTwo->BeingShot(power);
        ShildTwo->SetMessage(this->PlayerTwo->GetName() + " : " + QString::number(this->PlayerTwo->GetHealth()));
        if(PlayerTwo->GetHealth() <= 0)
        {
            view->close();
            this->ReadMaps();
            WinnerInfo winner(PlayerOne->GetName(), PlayerOne->tank->GetName(), PlayerTwo->tank->GetShild(), PlayerOne->GetHealth());
            winner.exec();
            this->Parent->show();
        }
    }
    else
    {
        PlayerOne->BeingShot(power);
        ShildOne->SetMessage(this->PlayerOne->GetName() + " : " + QString::number(this->PlayerOne->GetHealth()));
        if(PlayerOne->GetHealth() <= 0)
        {
            view->close();
            this->ReadMaps();
            WinnerInfo winner(PlayerTwo->GetName(), PlayerTwo->tank->GetName(), PlayerOne->tank->GetShild(), PlayerTwo->GetHealth());
            winner.exec();
            this->Parent->show();
        }
    }
}

void Game::ReadMaps()
{
    this->Maps.clear();
    QDir myDir(QCoreApplication::applicationDirPath() + "/maps/");
    for (const QFileInfo &file : myDir.entryInfoList(QDir::Files))
    {
        QFile fileOpen(QCoreApplication::applicationDirPath() + "/maps/" + file.fileName());
        if(fileOpen.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&fileOpen);
            in.setCodec("UTF-8");
            QString lines = in.readAll();
            QStringList line = lines.split("\n");
            QList<QList<int>> board;

            for(int j = 0; j < line.length(); j++)
            {
                QStringList fields = line[j].split(" ");
                QList<int> row;
                for(int i = 0; i < fields.length(); i++)
                {
                    row.append(fields[i].toInt());
                }
                board.append(row);
            }
            if(board.length() == 0)
                continue;
            int x = -1, y = -1;
            do
            {
                x = rand() % (board[0].length() - 1);
                y = rand() % (board.length() - 1);
            }while(board[y][x] != 0);

            board[y][x] = 5;
            x = -1;
            y = -1;
            do
            {
                x = rand() % (board[0].length() - 1);
                y = rand() % (board.length() - 1);
            }while(board[y][x] != 0);
            board[y][x] = 6;

            Map *map = new Map(file.fileName(), board);
            this->Maps.append(*map);
        }
    }
}
