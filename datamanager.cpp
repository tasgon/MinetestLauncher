#include "datamanager.h"

DataManager::DataManager(QFile file)
{
    if (file.exists() && file.size() > 0) {
        file.open(QIODevice::ReadOnly);
        jsonDocument = QJsonDocument::fromJson(file.readAll());
        if (jsonDocument != nullptr) {
            jsonObject = jsonDocument.object();
            if (jsonObject["instances"].isArray()) {
                profileArray = jsonObject["instances"].toArray();
                for (int i = 0; i < profileArray.size(); i++) {
                    profiles.push_back(Profile::fromJson(profileArray.at(i)));
                }
            }
        }
        else {
            jsonDocument = QJsonDocument();
            jsonObject = defaultObject;
            profileArray = defaultObject["instances"];
        }
        file.close();
    }
}
