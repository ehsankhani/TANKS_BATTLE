#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtank.h"
#include "playerinfoui.h"
#include "Tank.h"
#include "map.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tank *tank = new Tank("پانزر", 3, 3, 20, 1);
    Tank *tank2 = new Tank("تایگر", 4, 4, 15, 2);
    Tank *tank3 = new Tank("آبراهام", 5, 2, 15, 3);
    this->Tanks.append(*tank);
    this->Tanks.append(*tank2);
    this->Tanks.append(*tank3);
    //0 -> Empty
    //1 -> wall
    //2 -> box
    //3 -> Forest
    //5 -> playerOne
    //6 -> playerTwo
    QList<QList<int>> board(
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 5, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 0, 0, 2, 0, 0, 0, 1, 0, 1},
     {1, 0, 0, 1, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 2, 1, 0, 0, 0, 1},
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     {1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     {1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 2, 2, 0, 1, 1, 0, 0, 1},
     {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
     {1, 0, 0, 2, 1, 1, 0, 0, 1, 0, 0, 1, 2, 1, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 2, 0, 1},
     {1, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 1, 2, 2, 2, 0, 0, 2, 2, 0, 0, 1},
     {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1},
     {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 6, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}});
    Map *map = new Map("خانه", board);
    this->Maps.append(*map);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BtnNewTank_clicked()
{
    AddTank a(this);
    a.Tanks = this->Tanks;
    a.exec();
    if(a.result)
    {
        this->Tanks.append(*a.tank);
    }
}

void MainWindow::on_BtnPlay_clicked()
{
    PlayerInfoUI p(this->Tanks, this->Maps, this);
    this->hide();
    p.exec();
    this->show();
}
