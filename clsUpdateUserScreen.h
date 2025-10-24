#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow User List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enMainMenuePermissions::pListClients;
        }


        cout << "\nAdd New User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pAddNewClient;
        }

        cout << "\nDelete User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pDeleteClient;
        }

        cout << "\nUpdate User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pUpdateClients;
        }

        cout << "\nFind User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pLoginRegister;
        }

        return Permissions;

    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermission  : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        string UserName = "";
        cout << "\nPlease Enter User User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found,, choose another one: ";
            UserName = clsInputValidate::ReadString();

        }
        clsUser User1 = clsUser::Find(UserName);
        // User1.Print();
        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info: ";
            cout << "\n_______________________\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;


            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
                cout << "\nUser Updated Successfully :-) \n";
                //    User1.Print();
                _PrintUser(User1);

                break;

            case clsUser::enSaveResults::svFaildEmptyObject:
                cout << "\nError User was not saved because it's Empty";
                break;
            }
        }
    }
};

