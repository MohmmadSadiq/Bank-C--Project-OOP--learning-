#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter First Name: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Accont Balance: ";
        Client.AccountBalance = clsInputValidate::ReadDblNumber("Invalid Data \n");
    }


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

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::pAddNewClient))
        {
            return; // this wiil exit the function and it will not contenu
        }
        _DrawScreenHeader("\t  Add New Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                 cout << "\nAccount Added Successfully :-)\n";
                _PrintClient(NewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Account was not saved because it's Empty.";
                break;
            }
            case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            {
                cout << "\nError Account was not saved because it's already in Use.";
                break;
            }
        }
        
    }
};