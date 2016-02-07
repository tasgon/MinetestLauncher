#include "profilemanager.h"

ProfileManager::ProfileManager()
{

}

bool ProfileManager::addProfile(Profile profile)
{
    profiles.push_back(profile);
}

void ProfileManager::refreshList(QComboBox *box)
{
    box->clear();
    for (Profile profile : profiles) {
        box->addItem(profile.getName());
    }
}
