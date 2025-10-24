#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");
		cout << "\nPlease Enter Account Number to Transfer From: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			cout << "Please Enter Account Number to Transfer From: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nPlease Enter Account Number to Transfer to: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			cout << "Please Enter Account Number to Transfer to: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client2);

		double Amount = 0;

		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadDblNumberBetween(0, Client1.AccountBalance , "\nAmount Exceeds the available Balance, Enter Transfer Amount? ");


		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Transfer(Client2, Amount))
			{
				cout << "\nTransfer done Successfully.\n";
				
			}
			else
			{
				cout << "\nCannot Transfer, Insuffecient Balance!\n\n"
					<< "Amount to Transfer is: " << Amount << endl
					<< "Your Balance is: " << Client1.AccountBalance;
			}


		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
		_PrintClient(Client1);
		_PrintClient(Client2);

	}
	
};

