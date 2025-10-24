#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsDate.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	/*static string _GetLoginTime()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		string Time = to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

		return Time;

	}*/

	/*static string _ConvertLoginRecoredToLine()
	{
		string Line = "";
		
		Line += clsDate::GetSystemDateTimeString() + "#//#";
		Line += CurrentUser.UserName + "#//#";
		Line += CurrentUser.Password + "#//#";
		Line += to_string(CurrentUser.Permissions);

		return Line;
	}

	static void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}*/

	static bool _Login()
	{
		bool LoginFaild = false;

		short Tries = 3;

		string Username, Password;

		do 
		{
			if (LoginFaild)
			{
				Tries--;
				cout << "\nInvalid Username and password\n";
				cout << "You have " << Tries << " Trial(s) to Login.\n\n";

				if (Tries == 0)
				{
					cout << "You are Locked agter 3 faild trails\n\n";
					return false;
				}
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			
			LoginFaild = CurrentUser.IsEmpty();
				

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
		
	}
};

