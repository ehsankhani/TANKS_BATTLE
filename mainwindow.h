#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tank.h"
#include "map.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_BtnNewTank_clicked();

    void on_BtnPlay_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
