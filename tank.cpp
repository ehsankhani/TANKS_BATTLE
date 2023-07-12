#include "Tank.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDir>

Tank::Tank(QString name, int speed, int power, int shild, int color)
{
    this->Name = name;
    this->Speed = speed;
    this->Power = power;
    this->Shild = shild;
    this->Color = color;
}

QString Tank::GetName()
{
    return this->Name;
}

int Tank::GetSpeed()
{
    return this->Speed;
}

int Tank::GetPower()
{
    return this->Power;
}

int Tank::GetShild()
{
    return this->Shild;
}

int Tank::GetColor()
{
    return this->Color;
}

void Tank::WriteInFile()
{
    QDir my_app_dir(QCoreApplication::applicationDirPath() + "/tanks/");
    if(!my_app_dir.exists())
        QDir().mkdir(my_app_dir.path());
    QString path = QCoreApplication::applicationDirPath() + "/tanks/" + this->Name + ".txt";
    QFile *file = new QFile(path);
    if (file->open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(file);
        out<<this->Name;
        out<<"\n";
        out<<this->Speed;
        out<<"\n";
        out<<this->Power;
        out<<"\n";
        out<<this->Shild;
        out<<"\n";
        out<<this->Color;
    }
    file->flush();
    file->close();
}
