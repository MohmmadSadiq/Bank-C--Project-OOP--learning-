#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintRecord(clsCurrency Currency)
	{
		
		cout << "\n___________________\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static clsCurrency _FindByCurrencyCode()
	{
		string Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		while (Currency.IsEmpty())
		{
			cout << "\nThe Currency dose Not Exist, Please Enter CurrencyCode: \n";
			Code = clsInputValidate::ReadString();

			Currency = clsCurrency::FindByCode(Code);
		}

		return Currency;
	}

	static void _PrintResults(double Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		double Result = Currency1.CalculatFromCurrecyToAnother(Amount, Currency2);
		if (Currency2.isDolar())
		{
			cout << "\nConvert From:";
			_PrintRecord(Currency1);

			cout << Amount << Currency1.CurrencyCode() << " = " << Result << " USD\n\n";
		}
		else if (Currency1.isDolar())
		{
			cout << "\nConvert To:";
			_PrintRecord(Currency2);
			cout << "\n";
			cout << Amount << " " + Currency1.CurrencyCode() << " = " << Result << " USD\n\n";
		}
		else
		{
			cout << "\nConvert From:";
			_PrintRecord(Currency1);
			cout << "\n";
			cout << Amount << " " + Currency1.CurrencyCode() << " = " << Currency1.CalculatToDolar(Amount) << " USD\n\n";

			cout << "\nConvert To:";
			_PrintRecord(Currency2);
			cout << "\n";
			cout << Amount << " " + Currency1.CurrencyCode() << " = " << Result << " " + Currency2.CurrencyCode() + "\n\n";
		}
	}

public :

	static void ShowCurrencyCalculator()
	{

		_DrawScreenHeader("\tCurrency Calculator Screen");

		string Code = "";

		double Amount;

		cout << "\nPlease Enter Currency1 Code: \n";

		clsCurrency Currency1 = _FindByCurrencyCode();

		cout << "\nPlease Enter Currency2 Code: \n";

		clsCurrency Currency2 = _FindByCurrencyCode();

		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadDblNumber();

		_PrintResults(Amount, Currency1, Currency2);

		cout << "Do you want ot perform another calculation? y/n ? ";
		char Chois;
		cin >> Chois;

		if (toupper(Chois) == 'Y')
		{
			system("cls");

		ShowCurrencyCalculator();
		}

	}

};

