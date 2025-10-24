
//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsLoginScreen.h"




//void UpdateClient()
//{
//    string AccountNumber = "";
//    cout << "\nPlease Enter client Accoutn Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount number is not found,, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//
//    }
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//   // Client1.Print();
//
//    cout << "\n\nUpdate Client Info: ";
//    cout << "\n_______________________\n";
//
//    ReadClientInfo(Client1);
//
//    clsBankClient::enSaveResults SaveResult;
//
//    SaveResult = Client1.Save();
//
//    switch (SaveResult)
//    {
//    case clsBankClient::enSaveResults::svSucceeded:
//        cout << "\nAccount Updated Successfully :-) \n";
//    //    Client1.Print();
//        break;
//
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//        cout << "\nError account was not saved because it's Empty";
//        break;
//    }
//}
//
//
//void AddNewClient()
//{
    /*string AccountNumber = "";
    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError Account was not saved because it's Empty.";
        break;
    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError Account was not saved because it's already in Use.";
        break;
    }
    }
}*/
//
//void DeleteClient()
//{
//
//    string AccountNumber = "";
//    cout << "\nPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount Number Is Not Exists, Choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client = clsBankClient::Find(AccountNumber);
//    Client.Print();
//
//    cout << "\nAre you sure you want to delete this client y/n? ";
//
//    char Answer = 'n';
//    cin >> Answer;
//
//    if (Answer == 'y' || Answer == 'Y')
//    {
//        if (Client.Delete())
//        {
//            cout << "\nClient Deleted Successsfully :-)\n";
//            Client.Print();
//        }
//        else {
//            cout << "\nError Client Was not Deleted\n";
//        }
//    }
//
//}
//
//
//
//
//void PrintClientRecordBalancesLine(clsBankClient Client)
//{
//
//    cout << "| " << setw(15) << left << Client.AccountNumber();
//    cout << "| " << setw(20) << left << Client.FullName();
//    cout << "| " << setw(12) << left << Client.AccountBalance;
//
//}
//
//void ShowTotalBalances()
//{
//
//    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
//
//    int sum = 0;
//
//    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(20) << "Client Name";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    double TotalBalances = clsBankClient::GetTotalBalances();
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//    else
//
//        for (clsBankClient Client : vClients)
//        {
//            
//            PrintClientRecordBalancesLine(Client);
//            cout << endl;
//        }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//    cout << clsUtil::Tabs(3) << "Total Balances = " << TotalBalances << "\n";
//    cout << clsUtil::Tabs(3) << clsUtil::NumberToString(TotalBalances) << endl;
//
//
//}

int main()
{
    //clsMainScreen::ShowMainMenue();
    
    while (clsLoginScreen::ShowLoginScreen());

    
    return 0;
}