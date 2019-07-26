// snackbar.cpp
// Project 9.3 - Point-of-Sale System (snack bar)
// Jack Margeson
// 03/2019

// cout << "\033[2J\033[1;1H";

// compiler directives 
#include <iostream>
#include <iomanip>
using namespace std;

// function prototype 
// salesTax takes total and returns tax 
float salesTax(float total);
void printTotal(float &total);
void printMenu();

// main program
int main() {
  // declarations and init.
  char ans; // used for loop and questions
  float total, tax; // running total of cost, tax
  int amount; // how many of items?
  bool stillOrdering = true;
  // run-again loop 
  do {
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to the snack bar!" << endl;
    do { // looping menu
      printMenu();
      cout << "\n\nEnter a menu option: "; cin >> ans;
      switch (ans) { // selection handler
        case 'S': // sandwich (2.99)
          cout << "You have selected sandwich. How many?: "; cin >> amount;
          total = total + (2.99 * amount); break;
        case 'C': // chips (1.99)
          cout << "You have selected chips. How many?: "; cin >> amount;
          total = total + (1.99 * amount); break;
        case 'B': // brownie (0.99)
          cout << "You have selected brownie. How many?: "; cin >> amount;
          total = total + (0.99 * amount); break;
        case 'R': // regular drink (0.99)
          cout << "You have selected regular drink. How many?: "; cin >> amount;
          total = total + (0.99 * amount); break;
        case 'L': // large dring (1.99)
          cout << "You have selected regular drink. How many?: "; cin >> amount;
          total = total + (1.99 * amount); break;
        default:
          stillOrdering = false;
          break;
      }
      cout << "\033[2J\033[1;1H";
      printTotal(total);
    } while (stillOrdering);
    switch (ans) { // selection handler (quit sale or total sale)
      case 'X': // quit sale
        cout << "\033[2J\033[1;1H";
        cout << "Sale cancled.\nThank you for shopping at the snack stand."; break;
      case 'T': // total sale
        cout << "\033[2J\033[1;1H";
        cout << "Your total is $" << fixed << setprecision(2) << setfill('0') << setw(4) << total << ".\n";
        tax = salesTax(total); // get tax function
        cout << "Your tax is $" << fixed << setprecision(2) << setfill('0') << setw(4) << tax << ".\n";
        total = total + tax;
        cout << "Your final total is $" << fixed << setprecision(2) << setfill('0') << setw(4) << total << ".\n";
        cout << "Thank you for stopping by the snack bar!";
    }
    cout << "\nRun again? (y/n): "; cin >> ans; // run again prompt
  } while(ans == 'y' || ans == 'Y'); // run-again
  return 0;
}

// salesTax takes total as float and returns tax as float
float salesTax(float total){
  float tax;
  tax = total * .0575; // tax rate in Ohio
  return tax;
}

void printTotal(float &total) {
  cout << "Your total is currently $" << fixed << setprecision(2) << setfill('0') << setw(4) << total << ".\n";
}

void printMenu(){
  cout << "S - Sandwich\nC - Chips\nB - Brownie\nR - Regular Drink\nL - Large Drink\nX - Cancel sale and start over\nT - Total the sale";
}