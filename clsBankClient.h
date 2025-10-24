#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private: 
	enum enMode { EmptyMode = 0, UpdateMode  = 1, AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
    bool _MarkedForDelete ;


    struct stTransferLog;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string S1 = "";
        S1 += Client.FirstName + Seperator;
        S1 += Client.LastName + Seperator;
        S1 += Client.Email + Seperator;
        S1 += Client.Phone + Seperator;
        S1 += Client.AccountNumber() + Seperator;
        S1 += Client.PinCode + Seperator;
        S1 += to_string(Client.AccountBalance);

        return S1;
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> _veClients;
        fstream MyFile;
        
        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                _veClients.push_back(Client);
            }
            MyFile.close();
        }
        return _veClients;
    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> veClient)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        string DataLine;
        if (MyFile.is_open())
        {
            for (clsBankClient C : veClient)
            {
                if(C._MarkedForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
               
            }

            MyFile.close();
        }
        
    }

    void _Update()
    {
        vector <clsBankClient> _veClient;
        _veClient = _LoadClientsDataFromFile();
        for (clsBankClient& C : _veClient)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(_veClient);
    }

    void _AddNew()
    {
        
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
        

    }

    string _PrePareTransferLog(clsBankClient Client, double Amount, string Separetor = "#//#")
    {
        string Line = "";
        Line += clsDate::GetSystemDateTimeString() + Separetor;
        Line += AccountNumber() + Separetor;
        Line += Client.AccountNumber() + Separetor;
        Line += to_string(Amount) + Separetor;
        Line += to_string(AccountBalance) + Separetor;
        Line += to_string(Client.AccountBalance) + Separetor;
        Line += CurrentUser.UserName;

        return Line;
    }

    void _TransferLog(clsBankClient Client2, double Amount)
    {
        string stDataLine = _PrePareTransferLog(Client2, Amount);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static stTransferLog _ConvertTransferLogRecordLineTostruct(string Line, string Separetor = "#//#")
    {

        vector <string> vTransferLog = clsString::Split(Line, Separetor);

        stTransferLog TransferLog;

        TransferLog.DateTime = vTransferLog[0];
        TransferLog.SourceAccNumber = vTransferLog[1];
        TransferLog.DestinationAccNumber = vTransferLog[2];
        TransferLog.Amount = stoi(vTransferLog[3]);
        TransferLog.SourceAccBalance = stoi(vTransferLog[4]);
        TransferLog.DestinationAccBalance = stoi(vTransferLog[5]);
        TransferLog.UserName = vTransferLog[6];

        return TransferLog;
    }

    
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
        _MarkedForDelete = false;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

    struct stTransferLog
    {
        string DateTime;
        string SourceAccNumber;
        string DestinationAccNumber;
        double Amount;
        double SourceAccBalance;
        double DestinationAccBalance;
        string UserName;
    };

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {
        vector <clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);

            }
            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector <clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);

            }
            MyFile.close();
        }

        return _GetEmptyClientObject();
    }
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    enum enSaveResults {svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists = 2};
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
            
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
                
        }
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector <clsBankClient> _veClient;
        _veClient = _LoadClientsDataFromFile();
        for (clsBankClient& C : _veClient)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        
        
        _SaveCleintsDataToFile(_veClient);
        
        *this = _GetEmptyClientObject();
        
        return true;

        
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        double TotalBalances = 0;
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        for (clsBankClient& C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }
        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
       
    }

    bool Transfer(clsBankClient & Client2, double Amount)
    {
        if (Withdraw(Amount))
        {
            Client2.Deposit(Amount);
            _TransferLog(Client2, Amount);
            return true;
        }

        return false;
    }

    static vector <stTransferLog> GetTransFerLogData()
    {
        vector <stTransferLog> vTransferLog;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        
        string Line = "";
        stTransferLog TransLog;

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                TransLog = _ConvertTransferLogRecordLineTostruct(Line);
                vTransferLog.push_back(TransLog);
            }
            MyFile.close();
        }

        return vTransferLog;

    }
    
};

