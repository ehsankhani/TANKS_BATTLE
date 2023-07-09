#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <QDir>

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    game = new Game(&w);
    Tank *tank = new Tank("panzer", 3, 3, 20, 1);
    Tank *tank2 = new Tank("Tiger", 4, 4, 15, 2);
    Tank *tank3 = new Tank("Abraham", 5, 2, 15, 3);
    game->Tanks.append(*tank);
    game->Tanks.append(*tank2);
    game->Tanks.append(*tank3);
    //0 -> Empty
    //1 -> wall
    //2 -> box
    //3 -> Forest
    //5 -> playerOne
    //6 -> playerTwo
    QDir dir(":/new/Maps/maps/");
    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QFile fileOpen(":/new/Maps/maps/" + file.fileName());
        if(fileOpen.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&fileOpen);
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
            game->Maps.append(*map);
        }
    }
    w.show();
    return a.exec();
}
