#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
	static void _PrintRecorde(clsBankClient::stTransferLog Translog)
	{
		cout << setw(8) << left << "" << "| " << left << setw(23) << Translog.DateTime;
		cout << "| " << left << setw(8) << Translog.SourceAccNumber;
		cout << "| " << left << setw(8) << Translog.DestinationAccNumber;
		cout << "| " << left << setw(8) << Translog.Amount;
		cout << "| " << left << setw(10) << Translog.SourceAccBalance;
		cout << "| " << left << setw(10) << Translog.DestinationAccBalance;
		cout << "| " << left << setw(8) << Translog.UserName << endl;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLog> vTransLog = clsBankClient::GetTransFerLogData();

		string Tital = "\tTransfer Log List Screen";
		string SubTital = "\t\t(" + to_string(vTransLog.size()) + ") Record(s)";

		_DrawScreenHeader(Tital, SubTital);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if ((vTransLog.size() == 0))
		{
			cout << "Ther is No Transfers recorded\n\n";
		}
		else
		{
			for (clsBankClient::stTransferLog T : vTransLog)
			{
				_PrintRecorde(T);
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

