#ifndef PLAYERINFOUI_H
#define PLAYERINFOUI_H

#include <QDialog>
#include "Tank.h"
#include "map.h"
#include <QWidget>
#include "game.h"

namespace Ui {
class PlayerInfoUI;
}

class PlayerInfoUI : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInfoUI(QWidget *parent = nullptr);
    ~PlayerInfoUI();
    QWidget *Parent;
    bool StartGame = false;
private slots:
    void on_BtnPlay_clicked();

    void on_CmbTankPlayerOne_currentTextChanged(const QString &arg1);

    void on_CmbTankPlayerTwo_currentTextChanged(const QString &arg1);

private:
    Ui::PlayerInfoUI *ui;
};

#endif // PLAYERINFOUI_H
