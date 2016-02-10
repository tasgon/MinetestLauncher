#include "profilemanager.h"

ProfileManager::ProfileManager()
{

}

bool ProfileManager::addProfile(Profile profile)
{
    for (Profile p : profiles)
        if (p.getName() == profile.getName())
            return false;

    profiles.push_back(profile);
    return true;
}

bool ProfileManager::deleteByName(QString name)
{
    for (int i = 0; i < profiles.size(); i++)
        if (profiles[i].getName() == name)
        {
            profiles.erase(profiles.begin() + i);
            return true;
        }
    return false;
}

void ProfileManager::refreshList(QComboBox *box)
{
    box->clear();
    for (Profile profile : profiles) {
        box->addItem(profile.getName());
    }
}
