#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsUpdateCurrencyRateScreen.h"

using namespace std;

class clsCurrencyMenuScreen : protected clsScreen
{

	enum enCurrencyMenuOptions 
		{ eListCurrencies = 1, eFindCurrency = 2, 
		  eUpdateRate = 3, eCurrencyCalc = 4, eShowMainMenue = 5};
	static short _ReadCurrencyExchangeMenueOption()
	{
		
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] ? ";
		short Number = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");

		return Number;
	}

	static void _ShowListCurreciesScreen()
	{
		// cout << "The Screen will be hear. \n";
		clsListCurrencyScreen::ShowListCurrencyScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		// cout << "The Screen will be hear. \n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		// cout << "The Screen will be hear. \n";

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalcScreen()
	{
		//cout << "The Screen will be hear. \n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
	}



	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}


	static void _PerformCurrencyExchangeMenueOption(enCurrencyMenuOptions CurrencyMenuOptions)
	{
		switch (CurrencyMenuOptions)
		{
		case clsCurrencyMenuScreen::eListCurrencies:
			system("cls");
			_ShowListCurreciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMenuScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMenuScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMenuScreen::eCurrencyCalc:
			system("cls");
			_ShowCurrencyCalcScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMenuScreen::eShowMainMenue:
			break;
		
		}
	}
public :
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("    Currancy Exchange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "[3] Update Rate.\n";
		cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeMenueOption(enCurrencyMenuOptions(_ReadCurrencyExchangeMenueOption()));
	}

};

