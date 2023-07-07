#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtank.h"

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
    a.exec();
}
