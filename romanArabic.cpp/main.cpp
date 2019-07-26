// romanArabic.cpp
// Roman to Arabic, Arabic to Roman
// Jack Margeson, bell 1, 02/2019

// inclusions and namespace
#include <iostream>
#include <iomanip>
using namespace std;

// cout << "\033[2J\033[1;1H";

int main(){
  // declarations and init.
  char ans;
  int i = 0;
  char roman[16];
  int arabic;
  int thousands, hundreds, tens, ones;

  // main do loop
  do {
    arabic = 0;
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to raar.cpp.\n1) Roman to Arabic\n2) Arabic to Roman\nPlease choose a menu option: ";
    cin >> ans;
    if (ans == '1') {
      cout << "\033[2J\033[1;1H";
      cout << "Roman to Arabic";
      cout << "\nEnter roman numerals (1-3999): ";
      cin.ignore();
      cin.getline(roman, 16);
      i = 0;
      do {
        if (roman[i] == 'M') {
          arabic = arabic + 1000;
        }
        if (roman[i] == 'D'){
          arabic = arabic + 500;
        }
        if (roman[i] == 'C') {
          if (roman[i+1] == 'M' or roman[i+1] == 'D') {
            arabic = arabic - 100;
          } else {
            arabic = arabic + 100;
          }
        }
        if (roman[i] == 'L'){
          arabic = arabic + 50;
        }
        if (roman[i] == 'X') {
          if (roman[i+1] == 'C' or roman[i+1] == 'L') {
            arabic = arabic - 10;
          } else {
            arabic = arabic + 10;
          }
        }
        if (roman[i] == 'V'){
          arabic = arabic + 5;
        }
        if (roman[i] == 'I') {
          if (roman[i+1] == 'X' or roman[i+1] == 'V') {
            arabic = arabic - 1;
          } else {
            arabic = arabic + 1;
          }
        }
        ++i;
      } while (roman[i] != '\0');
      cout << "\n" << arabic;
    } else if (ans == '2') {
      cout << "\033[2J\033[1;1H";
      cout << "Arabic to Roman";
      cout << "\nEnter a number (1-3999): ";
      cin >> arabic;
      if (arabic > 3999 or arabic < 1) {
        cout << "\nInvalid number.";
      } else {
        // break into places
        thousands = (arabic / 1000) % 10;
        hundreds = (arabic / 100) % 10;
        tens = (arabic / 10) % 10;
        ones = arabic % 10;
        i = 0;
        // thousands
        if (thousands == 1) {
          roman[i] = 'M';
          ++i;
        } else if (thousands == 2) {
          roman[i] = 'M';
          ++i;
          roman[i] = 'M';
          ++i;
        } else if (thousands == 3) {
          roman[i] = 'M';
          ++i;
          roman[i] = 'M';
          ++i;
          roman[i] = 'M';
          ++i;
        }
        // hundreds
        if (hundreds == 1) {
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 2) {
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 3) {
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 4) {
          roman[i] = 'C';
          ++i;
          roman[i] = 'D';
          ++i;
        } else if (hundreds == 5) {
          roman[i] = 'D';
          ++i;
        } else if (hundreds == 6) {
          roman[i] = 'D';
          ++i;
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 7) {
          roman[i] = 'D';
          ++i;
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 8) {
          roman[i] = 'D';
          ++i;
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
          roman[i] = 'C';
          ++i;
        } else if (hundreds == 9) {
          roman[i] = 'C';
          ++i;
          roman[i] = 'M';
          ++i;
        }
        // tens
        if (tens == 1) {
          roman[i] = 'X';
          ++i;
        } else if (tens == 2) {
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
        } else if (tens == 3) {
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
        } else if (tens == 4) {
          roman[i] = 'X';
          ++i;
          roman[i] = 'L';
          ++i;
        } else if (tens == 5) {
          roman[i] = 'L';
          ++i;
        } else if (tens == 6) {
          roman[i] = 'L';
          ++i;
          roman[i] = 'X';
          ++i;
        } else if (tens == 7) {
          roman[i] = 'L';
          ++i;
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
        } else if (tens == 8) {
          roman[i] = 'L';
          ++i;
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
          roman[i] = 'X';
          ++i;
        } else if (tens == 9) {
          roman[i] = 'X';
          ++i;
          roman[i] = 'C';
          ++i;
        }
        // ones
        if (ones == 1) {
          roman[i] = 'I';
          ++i;
        } else if (ones == 2) {
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
        } else if (ones == 3) {
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
        } else if (ones == 4) {
          roman[i] = 'I';
          ++i;
          roman[i] = 'V';
          ++i;
        } else if (ones == 5) {
          roman[i] = 'V';
          ++i;
        } else if (ones == 6) {
          roman[i] = 'V';
          ++i;
          roman[i] = 'I';
          ++i;
        } else if (ones == 7) {
          roman[i] = 'V';
          ++i;
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
        } else if (ones == 8) {
          roman[i] = 'V';
          ++i;
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
          roman[i] = 'I';
          ++i;
        } else if (ones == 9) {
          roman[i] = 'I';
          ++i;
          roman[i] = 'X';
          ++i;
        }
        cout << "\n" << roman;
      }
    } else {
      cout << "\nInvalid menu option.";
    }
    // run again?
    cout << "\nRun again? (y/n): ";
    cin >> ans;
  } while (ans == 'y' or ans == 'Y'); // run again handler
  cout << "\033[2J\033[1;1H";
}