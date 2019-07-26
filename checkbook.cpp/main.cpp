/* checkbook.cpp
Maintains a checkbook register and reports a summary of
the current months transactions.
Jack Margeson, 03/2019 */

// compiler directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// structure
struct trans{
  char tc; // transation code
  float ta; // transaction amount
  float bal; // balance
};

// function protoypes 
float getStartBal(); // get start balance
void getTransaction(trans arrTrans[], int &transCount, float &balance, trans &transaction, bool &isChecking, int &plusDep, int &minDep, float &plusVal, float &minVal); // get transaction on loop
void printSummary(trans arrTrans[], int &transCount, int &plusDep, int &minDep, float &plusVal, float &minVal, float &sBal); // print fin sum
bool checkPass(string passwd); // checks password (weak)

// main program 
int main(){
  // declarations and init 
  char ans; // looping
  trans transaction; // transaction.tc and transaction.ta
  trans arrTrans[100];
  float balance = 0, sBal = 0;
  int transCount = 0;
  bool isChecking = true, isPasswd = false;
  int plusDep = 0, minDep = 0;
  float plusVal = 0, minVal = 0;
  string passwd;

  do { // run again?
    cout << "Enter password: "; cin >> passwd;
    isPasswd = checkPass(passwd);
    if (isPasswd){
      cout << "Password accepted." << endl;
      cout << "Welcome to CPBank.";
      balance = getStartBal();
      sBal = balance;
      do {
        getTransaction(arrTrans, transCount, balance, transaction, isChecking, plusDep, minDep, plusVal, minVal);
      } while (isChecking);
      printSummary(arrTrans, transCount, plusDep, minDep, plusVal, minVal, sBal);
    } else {
      cout << "Password denied.";
    }
    cout << "\nRun again? (y/n): "; cin >> ans;
    isChecking = true;
  } while (ans == 'y' || ans == 'Y');
  return 0;
}

float getStartBal(){
  float bal;
  cout << "\nStarting Balance: "; cin >> bal;
  return bal;
}

void getTransaction(trans arrTrans[], int &transCount, float &balance, trans &transaction, bool &isChecking, int &plusDep, int &minDep, float &plusVal, float &minVal){
  char tempc;
  float tempa;
  cout << "Transaction (" << transCount << "): "; cin >> tempc;
  if (tempc == 'E') { // end transaction
    isChecking = false;
  } else {
    cout << "Amount: "; cin >> tempa;
    switch(tempc){
      case 'C': // check
        if (tempa < balance) {
          transaction.tc = tempc;
          transaction.ta = tempa;
          minVal = minVal + tempa;
          balance = balance - tempa;
          transaction.bal = balance;
          minDep++;
        } else {
          transaction.tc = 'I'; 
          transaction.ta = 10.00;
          balance = balance - 10.00;
          transaction.bal = balance;
        }
        break;
      case 'D': // deposit
        transaction.tc = 'D';
        transaction.ta = tempa;
        plusVal = plusVal + tempa;
        balance = balance + tempa;
        transaction.bal = balance;
        plusDep++;
        break;
      default: // illegal transaction code
        transaction.tc = 'X';
        transaction.ta = 0.00;
        transaction.bal = balance;
        break;
    }
    arrTrans[transCount] = transaction;
    transCount++;
  }
}

void printSummary(trans arrTrans[], int &transCount, int &plusDep, int &minDep, float &plusVal, float &minVal, float &sBal){
  trans tt;
  cout << "\n";
  cout << setfill(' ') << setw(27) << left << "Transaction" << setw(13) << "Amount" << "Balance" << endl;
  for (int i = 0; i < transCount; i++){
    tt = arrTrans[i];
    switch(tt.tc){
      case 'C':
        cout << left << setw(27) << setfill(' ') << "Check";
        break;
      case 'D':
        cout << left << setw(27) << setfill(' ') << "Deposit";
        break;
      case 'I':
        cout << left << setw(27) << setfill(' ') << "Insuffecent Funds";
        break;
      case 'X':
        cout << left << setw(27) << setfill(' ') << "Illegal Transaction Code";
        break;
    }
    cout << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << tt.ta;
    cout << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(4) << setprecision(2) << right << tt.bal << endl;
  }
  cout << left << setw(27) << setfill(' ') << "Service Charge";
  cout << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << "5.00";
  cout << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(4) << setprecision(2) << right << (tt.bal - 5) << endl;
  cout << setfill('=') << setw(40) << "" << endl;
  cout << "Account Summary" << endl;
  cout << setfill(' ') << setw(34) << left << "" << setw(24) << "Amount" << endl;
  cout << left << setw(27) << setfill(' ') << "Beginning Balance" << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << sBal << endl;
  cout << left << setw(27) << setfill(' ') << "Plus Deposits" << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << plusVal << "(" << plusDep << ")" << endl;
  cout << left << setw(27) << setfill(' ') << "Minus Deposits" << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << minVal << "(" << (minDep +2) << ")" << endl;
  cout << left << setw(27) << setfill(' ') << "Ending Balance" << setfill(' ') << setw(6) << "" << "$" << fixed << setfill('.') << setw(6) << setprecision(2) << right << (tt.bal - 5) << endl;
  cout << setfill('=') << setw(40) << "";
}

bool checkPass(string passwd){
  if (passwd == "bankadmin"){
    return true;
  } else {
    return false;
  }
}