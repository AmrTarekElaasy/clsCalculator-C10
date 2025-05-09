// clsCalculator C10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class clsCalculator
{
private:
    struct _stOperationHistory
    {
        string OperationInString="";
        double ProcessOutput=0;

    };
    vector <_stOperationHistory> _OperationHistoryVec;
    double _Number=0;
    
    enum enOperation{enAdd,enSub,enMul,enDiv};

    string DoubleToString(double num, short precision = 9)
    {
        
        ostringstream stream;
        stream << fixed << setprecision(precision) << num;
        string s = stream.str();
        while (s[s.length() - 1] == '0')
        {
            s.pop_back();
            
        }
        if (s[s.length() - 1] == '.')
        {
            s.pop_back();
        }
        return s;
    }
    void SaveHistory(enOperation operation,double OldNum,double Num2,double EndNum)
    {
        string LastOperation = DoubleToString(OldNum);
        switch (operation)
        {
        case clsCalculator::enAdd:
            LastOperation += " + ";
            break;
        case clsCalculator::enSub:
            LastOperation += " - ";
            break;
        case clsCalculator::enMul:
            LastOperation += " * ";
            break;
        case clsCalculator::enDiv:
            LastOperation += " / ";
            break;
            
        }
        
        
            LastOperation += DoubleToString(Num2) + " = " + DoubleToString(EndNum);
            _stOperationHistory OperationHistory;
            OperationHistory.OperationInString = LastOperation;
            OperationHistory.ProcessOutput = EndNum;
        _OperationHistory.push_back(OperationHistory);
    }

public:
    
    void Clean()
    {
        _Number = 0;
        _OperationHistory.clear();
    }
    void Add(double Num2)
    {
        double OldNumber = _Number;
        _Number += Num2;
        SaveHistory(enOperation::enAdd, OldNumber, Num2, _Number);
    }
    void Sub(double Num2)
    {
        double OldNumber = _Number;
        _Number -= Num2;
        SaveHistory(enOperation::enSub, OldNumber, Num2, _Number);
    }
     void Mul(double Num2)
    {
        double OldNumber = _Number;
        _Number *= Num2;
        SaveHistory(enOperation::enMul, OldNumber, Num2, _Number);
    }
     void Div(double Num2)
    {
         if (Num2 == 0)
             Num2 = 1;

        double OldNumber = _Number;
        _Number /= Num2;
        SaveHistory(enOperation::enDiv, OldNumber, Num2, _Number);
    }
     string LastOperation()
     {
         if(_OperationHistory.size()>0)
         return _OperationHistory[_OperationHistory.size() - 1].OperationInString;
     }
    void PrintLastOperation()
     {
        cout << LastOperation() << endl;
     }
    string AllOperation()
    {
        
        string Operations = "";
        for (short i = 0; i < _OperationHistory.size(); i++)
        {
            Operations += _OperationHistory[i].OperationInString + "\n";

        }
        if (Operations.size() > 0)
        {
            Operations.pop_back();
        }
        return Operations;
    }
    void PrintAllOperation()
    {

        cout << AllOperation() << endl;
    }
    double CurrentNumber()
    {
        return _Number;
    }
    void CancelLastOperation()
    {
        if (_OperationHistory.size() > 1)
        {
            _OperationHistory.pop_back();
            _Number = _OperationHistory.back().ProcessOutput;
        }
        else
        {
            Clean();
        }
        
    }
};

int main()
{
  
/*
   //Test
   clsCalculator calc;
   calc.Clean();
   
   calc.Add(9.965);
   calc.Mul(10);
   calc.Sub(10.59);
   calc.Div(10.4649);
   
   calc.Mul(6595.4545);
   calc.Div(0.4545);
   calc.Div(49.964);
   calc.CancelLastOperation();
   calc.PrintAllOperation();
   calc.CancelLastOperation();
   calc.CancelLastOperation();
   calc.CancelLastOperation();
   calc.CancelLastOperation();
   calc.CancelLastOperation();
   calc.CancelLastOperation();
   calc.PrintAllOperation();
   cout << calc.CurrentNumber()<<"\n\n";
   calc.Clean();
   calc.PrintAllOperation();
   cout << calc.CurrentNumber() << endl;
   */

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
