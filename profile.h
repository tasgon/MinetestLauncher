#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QDir>
#include <QJsonObject>

using namespace std;

class Profile
{
public:
    Profile(QString, QString);
    static Profile fromJson(QJsonObject);
    QDir getPath();

    QString getName() { return name; }
    QString getVersion() { return version; }

private:
    QDir prefix = QDir(QDir::home().filePath(".minetest"));
    QString name, version;
};

#endif // PROFILE_H
