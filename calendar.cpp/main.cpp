// calendar.cpp
// Outputs a visual repersentation of the months.
// Jack Margeson

// compiler directives
#include <iostream>
#include <iomanip>
using namespace std;

// declarations and init.
char ans;
int day, month, century, year; // used for calculating zellers
bool isLeapYear; // used for leap year
int numDay, intDay, initDay; // used for drawing calandar

// zeller's function
// returns 0-6 (week pos) of the given date
int zellersFormula(int day, int  month, int century, int year) {
  int f, gcf = 0, zellers;
  f = (day + (((13 * month) - 1) / 5) + year + (year / 4) + (century / 4)) - (2 * century);
  if (f < 0){ // if a negative f occurs
    do {
      gcf = gcf - 7;
    } while (gcf > f);
    zellers = abs(gcf % f);
  } else { // if f is not negative
    zellers = f % 7;
  }
  return zellers;
}

// isLeapYear function
// returns boolean true if leap year, false if regular
bool testLeapYear(int century, int year){
  int ly = (century * 100) + year;
  if (ly % 4 == 0) {
    if (ly % 100 == 0) {
      if (ly % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  }
  return false;
}

// printCal function
// prints calendar given month, first of month, day searched on month, and number of days in month.
void printCal(int month, int initDay, int day, int numDay) {
  int k = 0,l = 1;
  char charDay[7][2] = {{'S','U'},{'M','O'},{'T','U'},{'W','E'},{'T','H'},{'F','R'},{'S','A'}};
  string arrMonth[12] = {"January", "Febuary","March","April","May","June","July","August","September","October","November","December"};
  cout << "\n" << arrMonth[month - 1] << " " << day;
  cout << "\n ";
  for (int i = 0; i < 7; i++){
    cout << charDay[i][0] << charDay[i][1] << setfill(' ') << setw(4) << "";
  }
  for (int i = 0; i < 6; i++){
    cout << "\n" << setfill('_') << setw(40) << "" << endl;
    for (int j = 0; j < 7; j++){
      if (k >= ((initDay)) && (l <= (numDay))) {
        cout << "|" << right << setfill('0') << setw(2) << l << fixed << "|" << setfill(' ') << setw(2) << "";
        l++;
      } else {
        cout << "|" << right << setfill(' ') << setw(2) << "" << fixed << "|" << setfill(' ') << setw(2) << "";
      }
      k++;
    }
    cout << "\n" << setfill('-') << setw(40) << "";
  }
  // holidays
  cout << "\n---Holidays---" << endl;
  switch(month) {
    case 1: cout << "January 1st - New Years"; break;
    case 2: cout << "February 14th - Valentine's Day"; break;
    case 3: cout << "March 17th - Saint Patrick's Day"; break;
    case 4: cout << "April 15th - Tax Day"; break;
    case 5: cout << "May 5th - Cinco de Mayo" <<"\nMay 23rd - Jack's Birthday"; break;
    case 6: cout << "June 6th - D-Day"; break;
    case 7: cout << "July 4th - Independence Day"; break;
    case 8: cout << "August 15th - First Day of School" << "\nAugust 26th - Women's Equality Day"; break;
    case 9: cout << "September 2nd - Labour Day"; break;
    case 10: cout << "October 9th - Leif Erikson Day" << "\nOctober 31st - Halloween"; break;
    case 11: cout << "November 28th - Thanksgiving" << "\nNovember 29th - Black Friday"; break;
    case 12: cout << "December 25th - Christmas" << "\nDecember 31st - New Year's Eve"; break;
  }
}

// main program
int main() {
  // run again loop 
  do {
    cout << "Enter day: "; cin >> day;
    cout << "Enter month: "; cin >> month;
    cout << "Enter century: "; cin >> century;
    cout << "Enter year: "; cin >> year;
    isLeapYear = testLeapYear(century, year);
    switch (month){
      case 1:
        year--;
        initDay = zellersFormula(1, 11, century, year);
        numDay = 31;
        printCal(month, initDay, intDay, numDay);
        break;
      case 2:
        year--;
        initDay = zellersFormula(1, 12, century, year);
        if (isLeapYear == true){
          numDay = 29;
        } else {
          numDay = 28;
        }
        printCal(month, initDay, day, numDay);
        break;
      case 3:
        initDay = zellersFormula(1, 1, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
      case 4:
        initDay = zellersFormula(1, 2, century, year);
        numDay = 30;
        printCal(month, initDay, day, numDay);
        break;
      case 5:
        initDay = zellersFormula(1, 3, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
      case 6:
        initDay = zellersFormula(1, 4, century, year);
        numDay = 30;
        printCal(month, initDay, day, numDay);
        break;
      case 7:
        initDay = zellersFormula(1, 5, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
      case 8:
        initDay = zellersFormula(1, 6, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
      case 9:
        initDay = zellersFormula(1, 7, century, year);
        numDay = 30;
        printCal(month, initDay, day, numDay);
        break;
      case 10:
        initDay = zellersFormula(1, 8, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
      case 11:
        initDay = zellersFormula(1, 9, century, year);
        numDay = 30;
        printCal(month, initDay, day, numDay);
        break;
      case 12:
        initDay = zellersFormula(1, 10, century, year);
        numDay = 31;
        printCal(month, initDay, day, numDay);
        break;
    }
    // run again?
    cout << "\nRun again? (y/n): ";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y'); // run again loop handler
  // system("Pause");
  return 0;
}
