#ifndef PLAYERINFOUI_H
#define PLAYERINFOUI_H

#include <QDialog>
#include "Tank.h"

namespace Ui {
class PlayerInfoUI;
}

class PlayerInfoUI : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInfoUI(QList<Tank> tanks, QWidget *parent = nullptr);
    ~PlayerInfoUI();
    QList<Tank> Tanks;
private slots:
    void on_CmbTankPlayerOne_currentIndexChanged(const QString &arg1);

    void on_CmbTankPlayerTwo_currentIndexChanged(const QString &arg1);

    void on_BtnPlay_clicked();

private:
    Ui::PlayerInfoUI *ui;
};

#endif // PLAYERINFOUI_H
