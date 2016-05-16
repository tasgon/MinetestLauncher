#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class DataManager
{
public:
    DataManager(QFile);

    QJsonObject defaultObject
    {
        {"instances", QJsonArray()}
    };

private:
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    QJsonArray profileArray;
};

#endif // DATAMANAGER_H
