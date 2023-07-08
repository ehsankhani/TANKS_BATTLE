#include "mainwindow.h"
#include "game.h"
#include <QApplication>

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    MainWindow w;
    w.game = game;
    w.show();
    return a.exec();
}
