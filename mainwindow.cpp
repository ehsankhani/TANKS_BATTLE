#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtank.h"
#include "playerinfoui.h"

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
