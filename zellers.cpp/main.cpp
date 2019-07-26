// zellers.cpp
// Calculates Zeller's formula.
// Jack Margeson

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  char ans;
  int month, day, year, cyear;
  int f, output, gcf;
  int d4, c4, m13;

  do {
    cout << "Welcome to zeller.cpp.\nPlease enter the following info.\n";
    cout << "1) March\n2) April\n3) May\n4) June\n5) July\n6) August\n7) September\n8) October\n9) November\n10) December\n11) January\n12) February\nEnter the month: ";
    cin >> month;
    cout << "Enter the day of the date: ";
    cin >> day;
    cout << "Enter the century (first 2 digits of the year): ";
    cin >> cyear;
    cout << "Enter the last 2 digits of the year: ";
    cin >> year;
    // zellers handler 
    if (month == 11 or month == 12) {
      year--;
    }
    // f = k + [(13*m-1)/5] + D + [D/4] + [C/4] - 2*C
    // where k is day
    // m is month
    // d is last 2 digits of year
    // and c is the first 2 digits of year
    m13 = ((13 * month) - 1) / 5;
    d4 = year / 4;
    c4 = cyear / 4;
    f = (day + m13 + year + d4 + c4) - (2 * cyear);
    if (f < 0){ // if a negative f occurs
      do {
        gcf = gcf - 7;
      } while (gcf > f);
      output = abs(gcf % f);
    } else { // if f is not negative
      output = f % 7;
    }
    // 0 - sunday, 1 - monday... 6 - saturday.
    if (month == 11) {
      year++;
      month = -1;
    } else if (month == 12) {
      year++;
      month = 0;
    }
    month = month + 2;
    cout << endl;
    if (output == 0){
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Sunday.";
    } else if (output == 1) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Monday.";
    } else if (output == 2) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Tuesday.";
    } else if (output == 3) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Wednesday.";
    } else if (output == 4) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Thursday.";
    } else if (output == 5) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Friday.";
    } else if (output == 6) {
      cout << month << "/" << day << "/" << cyear << setfill('0') << setw(2) << year << " will be a Saturday.";
    }
    cout << "\nWould you like to run again? (y/n): ";
    cin >> ans;
  } while(ans == 'y' or ans == 'Y');
  return 0;
}