#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtank.h"
#include "playerinfoui.h"
#include "Tank.h"

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
    PlayerInfoUI p(this->Tanks, this);
    this->hide();
    p.exec();
    this->show();
}
