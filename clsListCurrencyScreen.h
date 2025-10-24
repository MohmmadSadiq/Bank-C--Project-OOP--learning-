#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsListCurrencyScreen : protected clsScreen
{
    static void _PrintRecord(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << Currency.Country();
        cout << "| " << left << setw(7) << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate() << endl;
    }

public :
	static void ShowListCurrencyScreen()
	{
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Tital = "\tCurrences List Screen";
        string Subtital = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Tital, Subtital);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;


        cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(7) << "Code";
        cout << "| " << left << setw(45) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
        {
           cout << setw(8) << left << "" << left << setw(35) << "\t\t\t\tTher is No Recorde in The system";
        }

        else{
            for (clsCurrency C : vCurrencies)
            {
                _PrintRecord(C);
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

    }
};

