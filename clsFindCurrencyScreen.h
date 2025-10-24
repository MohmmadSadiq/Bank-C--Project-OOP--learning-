#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
	enum enFindCurrencyOption { ByCode  = 1, ByCountry = 2};
	static void _PrintRecord(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________\n";
		cout << "Country    : " << Currency.Country()	  << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static short _ReadFindOption()
	{
		cout << "Find By : [1] Code or [2] Country ? ";

		short Choise = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number 1 or 2?");

		return Choise;
	}

	static clsCurrency _FindByCurrencyCode()
	{
		cout << "\nPlease Enter CurrencyCode: ";
		string Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		while (Currency.IsEmpty())
		{
			cout << "\nThe Currency dose Not Exist, Please Enter CurrencyCode: ";
			Code = clsInputValidate::ReadString();

			Currency = clsCurrency::FindByCode(Code);
		}
		
		return Currency;
	}

	static clsCurrency _FindByCountryName()
	{
		cout << "\nPlease Enter Country Name: ";
		string Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(Code);

		while (Currency.IsEmpty())
		{
			cout << "\nThe Currency dose Not Exist, Please Enter Country Name: ";

			Code = clsInputValidate::ReadString();

			Currency = clsCurrency::FindByCountry(Code);
		}

		return Currency;
	}

	static clsCurrency _PerformFindCurrencyOption(enFindCurrencyOption CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case clsFindCurrencyScreen::ByCode:
			return _FindByCurrencyCode();
			break;
		case clsFindCurrencyScreen::ByCountry:
			return _FindByCountryName();
			break;
		default:
			break;
		}
	}

public :
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		clsCurrency Currency = _PerformFindCurrencyOption((enFindCurrencyOption)_ReadFindOption());

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintRecord(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found :-(\n";
		}
	}

};

