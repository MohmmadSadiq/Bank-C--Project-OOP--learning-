#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsFindClientScreen :protected clsScreen
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

public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::pFindClient))
        {
            return; // this wiil exit the function and it will not contenu
        }
        _DrawScreenHeader("\tFind Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter client Accoutn Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found,, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        // Client1.Print();
        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);
    }
};

