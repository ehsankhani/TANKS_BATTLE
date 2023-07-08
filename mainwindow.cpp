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
        game->Tanks.append(*a.tank);
    }
}

void MainWindow::on_BtnPlay_clicked()
{
    PlayerInfoUI p(this);
    this->hide();
    p.exec();
}
