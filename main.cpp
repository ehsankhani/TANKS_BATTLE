#include "mainwindow.h"
#include "game.h"
#include "mapcreator.h"
#include <QApplication>
#include <QDir>

Game *game;
MapCreator *mapCreator;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    game = new Game(&w);
    mapCreator = new MapCreator();
    Tank *tank = new Tank("panzer", 3, 3, 20, 1);
    Tank *tank2 = new Tank("Tiger", 4, 4, 15, 2);
    Tank *tank3 = new Tank("Abraham", 5, 2, 15, 3);
    game->Tanks.append(*tank);
    game->Tanks.append(*tank2);
    game->Tanks.append(*tank3);
    QDir tankDir(QCoreApplication::applicationDirPath() + "/tanks/");
    for (const QFileInfo &file : tankDir.entryInfoList(QDir::Files))
    {
        QFile fileOpen(QCoreApplication::applicationDirPath() + "/tanks/" + file.fileName());
        if(fileOpen.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&fileOpen);
            in.setCodec("UTF-8");
            QString lines = in.readAll();
            QStringList line = lines.split("\n");
            Tank *newTank = new Tank(line[0], line[1].toInt(), line[2].toInt(), line[3].toInt(), line[4].toInt());
            game->Tanks.append(*newTank);
        }
    }
    //0 -> Empty
    //1 -> wall
    //2 -> box
    //3 -> Forest
    //5 -> playerOne
    //6 -> playerTwo
    QDir dir(":/new/Maps/maps/");
    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QFile my_file(":/new/Maps/maps/" + file.fileName());
        QDir my_app_dir(QCoreApplication::applicationDirPath() + "/maps/");
        if(!my_app_dir.exists())
            QDir().mkdir(my_app_dir.path());
        QString new_path = my_app_dir.absoluteFilePath(file.fileName());
        my_file.copy(new_path);
    }
    game->ReadMaps();
    w.show();
    return a.exec();
}
