#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
	static void _PrintRecord(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
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

public :
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		clsCurrency Currency = _FindByCurrencyCode();

		char chios;

		_PrintRecord(Currency);

		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

		cin >> chios;

		float Rate = 0;

		if (toupper(chios) == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n___________________\n";
			cout << "\nEnter New Rate: ";
			Rate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(Rate);

			cout << "\nCurrency Rate Updated Successfully :-) \n";
			_PrintRecord(Currency);
		}
		else
		{
			cout << "\nThe Operation is Cansled\n";
		}

		

	}
};

