#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen 
{
private:


    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public :

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::pDeleteClient))
        {
            return; // this wiil exit the function and it will not contenu
        }
        _DrawScreenHeader("\t  Delete Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Exists, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successsfully :-)\n";
                _PrintClient(Client);
            }
            else {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};

