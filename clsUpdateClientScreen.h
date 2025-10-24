#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
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

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::pUpdateClients))
        {
            return; // this wiil exit the function and it will not contenu
        }

        _DrawScreenHeader("\tUpdate Client Screen");
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
        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info: ";
            cout << "\n_______________________\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;


            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount Updated Successfully :-) \n";
                //    Client1.Print();
                _PrintClient(Client1);

                break;

            case clsBankClient::enSaveResults::svFaildEmptyObject:
                cout << "\nError account was not saved because it's Empty";
                break;
            }
        }
    }
};

