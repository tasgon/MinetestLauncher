#include "profile.h"

Profile::Profile(QString n, QString v)
{
    name = n;
    version = v;
}

Profile Profile::fromJson(QJsonObject obj)
{
    return Profile(obj.value("name").toString(), obj.value("version").toString());
}

QDir Profile::getPath()
{
    return QDir(prefix.filePath(name));
}
