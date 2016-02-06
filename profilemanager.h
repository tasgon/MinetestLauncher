#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "profile.h"
#include<vector>

using namespace std;

class ProfileManager
{
public:
    ProfileManager();
    bool addProfile(Profile);

private:
    vector<Profile> profiles;
};

#endif // PROFILEMANAGER_H
