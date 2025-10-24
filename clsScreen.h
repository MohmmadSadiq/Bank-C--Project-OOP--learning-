#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t " << "User: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\t " << "Date: " << clsDate::GetDateString(clsDate()) << "\n";
    }

    static bool CheckAccessRights(clsUser::enMainMenuePermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            
            _DrawScreenHeader("Access Denied! Contact your Admin");
            
            return false;

        }
        else
        {
            return true;
        }
    }
};

