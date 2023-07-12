#include "newmapui.h"
#include "ui_newmapui.h"
#include "mapcreator.h"
#include <QMessageBox>

NewMapUI::NewMapUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMapUI)
{
    ui->setupUi(this);
}

NewMapUI::~NewMapUI()
{
    delete ui;
}

extern MapCreator *mapCreator;
void NewMapUI::on_BtnOk_clicked()
{
    QString mapName = ui->TxtName->text().trimmed();
    if(mapName == "")
    {
        QMessageBox::question(this, "Message", "Enter Map Name", QMessageBox::Ok);
        ui->TxtName->setFocus();
        return;
    }
    try
    {
        QString Height = ui->TxtHeight->text().trimmed();
        if(Height == "")
        {
            QMessageBox::question(this, "Message", "Enter Map Height", QMessageBox::Ok);
            ui->TxtHeight->setFocus();
            return;
        }
        int mapHeight = Height.toInt();
        QString Width = ui->TxtWidth->text().trimmed();
        if(Width == "")
        {
            QMessageBox::question(this, "Message", "Enter Map Width", QMessageBox::Ok);
            ui->TxtWidth->setFocus();
            return;
        }
        int mapWidth = Width.toInt();
        QList<QList<int>> mapInfo;
        for(int i = 0; i < mapHeight; i++)
        {
            QList<int> row;
            for(int j = 0; j < mapWidth; j++)
            {
                row.append(0);
            }
            mapInfo.append(row);
        }
        this->close();
        Map *map = new Map(mapName, mapInfo);
        mapCreator->map = map;
        mapCreator->Start();
    }
    catch(QString)
    {
        QMessageBox::question(this, "Message", "The information entered is invalid", QMessageBox::Ok);
    }
}
