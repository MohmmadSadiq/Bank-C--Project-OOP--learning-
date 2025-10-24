#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
	

	

	static void _PrintRecord(clsUser::stLoginRegister LoginRegister)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegister.DateTime;
		cout << "| " << left << setw(20) << LoginRegister.UserName;
		cout << "| " << left << setw(20) << LoginRegister.Password;
		cout << "| " << left << setw(20) << LoginRegister.Permission << endl;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::pLoginRegister))
		{
			return; // this wiil exit the function and it will not contenu
		}

		vector <clsUser::stLoginRegister> vLoginRegisters = clsUser::GetLoginRegisterList();
		string Tital = "\tLogin Register List Screen";
		string Subtital = "\t\t(" + to_string(vLoginRegisters.size()) + ")" + "Record(s)";

		_DrawScreenHeader(Tital, Subtital);
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisters.size() == 0)
		{
			cout << "\nTher is Not Login Registor\n";
		}
		else
		{
			for (clsUser::stLoginRegister Lo : vLoginRegisters)
			{
				_PrintRecord(Lo);
			}
			
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}
};

