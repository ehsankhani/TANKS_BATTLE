#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtank.h"
#include "playerinfoui.h"
#include "newmapui.h"
#include "Tank.h"
//#include "map.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

extern Game *game;
void MainWindow::on_BtnNewTank_clicked()
{
    AddTank a(this);
    a.exec();
    if(a.result)
    {
        a.tank->WriteInFile();
        game->Tanks.append(*a.tank);
    }
}

void MainWindow::on_BtnPlay_clicked()
{
    PlayerInfoUI p(this);
    this->hide();
    p.exec();
    if(!p.StartGame)
        this->show();
}

void MainWindow::on_BtnExit_clicked()
{
    this->close();
}

void MainWindow::on_BtnNewMap_clicked()
{
    NewMapUI a(this);
    a.exec();
}
