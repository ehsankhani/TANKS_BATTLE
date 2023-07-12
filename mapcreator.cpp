#include "mapcreator.h"
#include "mapcreatoritem.h"
#include "game.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>

MapCreator::MapCreator(QWidget *parent)
{
}

void MapCreator::Start()
{
    QGraphicsScene *scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->setBackgroundBrush(QBrush(Qt::white));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(this->map->GetBoard()[0].length() * 50 + 5, this->map->GetBoard().length() * 50 + 50);
    scene->setSceneRect(0, 0, this->map->GetBoard()[0].length() * 50 + 5, this->map->GetBoard().length() * 50 + 50);
    view->show();
    for(int i = 0; i < this->map->GetBoard().length(); i++)
    {
        for(int j = 0; j < this->map->GetBoard()[i].length(); j++)
        {
            MapCreatorItem *item = new MapCreatorItem(j * 50, i * 50, false);
            item->LocationI = i;
            item->LocationJ = j;
            item->setFlag(QGraphicsItem::ItemIsFocusable);
            item->setFocus();
            scene->addItem(item);
        }
    }
    MapCreatorItem *item = new MapCreatorItem(0, this->map->GetBoard().length() * 50, true);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();
    scene->addItem(item);
}

extern Game *game;
void MapCreator::Save()
{
    QString path = QCoreApplication::applicationDirPath() + "/maps/" + this->map->GetName() + ".txt";
    QFile *file = new QFile(path);
    int counter = 1;
    while(file->exists())
    {
        path = QCoreApplication::applicationDirPath() + "/maps/" + this->map->GetName() + "(" + QString::number(counter) + ").txt";
        file = new QFile(path);
        counter++;
    }
    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        for(int i = 0; i < map->GetBoard().length(); i++)
        {
            QTextStream out(file);
            for(int j = 0; j < map->GetBoard()[i].length(); j++)
            {
                QString q = QString::number(map->GetBoard()[i][j]);
                if((j + 1) != map->GetBoard()[i].length())
                    q += " ";
                q = q.toUtf8();
                out<<q;
            }
            if((i + 1) != map->GetBoard().length())
                out<<"\n";
        }
    }
    file->flush();
    file->close();
    game->ReadMaps();
    QMessageBox::question(this, "Message", "Map Saved...", QMessageBox::Ok);
    view->close();
}
