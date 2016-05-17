#include "datamanager.h"

DataManager::DataManager(QString filename)
{
    file = new QFile(filename);
    qDebug(file->fileName().toStdString().c_str());
    if (file->exists() && file->size() > 0) {
        file->open(QIODevice::ReadOnly);
        jsonObject = QJsonDocument::fromJson(file->readAll()).object();
        file->close();
    }
    else {
        jsonObject = QJsonObject();
    }
}

void DataManager::loadProfiles() {
    if (jsonObject["instances"].isArray()) {
        QJsonArray profileArray = jsonObject["instances"].toArray();
        for (int i = 0; i < profileArray.size(); i++) {
            manager->addProfile(Profile::fromJson(profileArray.at(i)));
        }
    }
}

void DataManager::saveProfiles()
{
    QJsonArray profileArray = QJsonArray();
    for (Profile profile : manager->profiles) {
        profileArray.append(profile.toJson());
    }
    jsonObject["instances"] = profileArray;

    qDebug("Saved profiles");

    save();
}

void DataManager::save()
{
    file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    QJsonDocument document;
    document.setObject(jsonObject);
    file->write(document.toJson());
    file->close();

    qDebug("Saved");
}
