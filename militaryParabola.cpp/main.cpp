// militaryParabola.cpp
// Military - finds time difference between two given military times.
// Parabola - calulates roots of a parabola and the intersection of a line.
// Jack Margeson, Bell 6, 02/11/19
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// cout << "\033[2J\033[1;1H";

int main() {
  // declarations and init
  char ans;
  int menu;
  // declarations and init - millitary time
  int startTime;
  int endTime;
  int startHours;
  int endHours;
  int startMinutes;
  int endMinutes;
  int newTime;
  int newHours;
  int newMinutes;
  // declaraions and init - parabola
  int a;
  int b;
  int c;
  int X1;
  int X2;
  int Y1;
  int Y2;
  double firstRoot;
  double secondRoot;
  double squareRoot;
  double intSquareRoot;
  double imgSquareRoot;
  double img;
  int denom2a;
  // declarations and init - line
  float m;
  float yInt;
  float xintercept;
  float xintercept2;
  float yintercept;
  float yintercept2;

  do {
    cout << "\033[2J\033[1;1H";
    cout << "1) Military Time\n" << "2) Parabola\n" << "Please choose a program: ";
    cin >> menu;
    if (menu == 1) { // Military Time
      cout << "\033[2J\033[1;1H";
      cout << "Military Time";
      cout << "\nPlease enter Time #1 (start time): ";
      cin >> startTime;
      cout << "Please enter Time #2 (end time): ";
      cin >> endTime;
      if (startTime > 2400 or endTime > 2400) { // valid time handler
        cout << "\nYou have entered an invalid time. Please check that both time values are less than 2400.";
      } else {
        if (startTime == endTime) { // outputs if same time inputted
          cout << "The difference in time is either 0 hours 0 minutes, or 24 hours 0 minutes.";
        } else if (startTime > endTime) { // difference of same day of time
          startHours = startTime / 100;
          endHours = endTime / 100;
          startMinutes = startTime - startHours * 100;
          endMinutes = endTime - endHours * 100;
          if (startMinutes > endMinutes) { // hour to minute handler
            endHours--;
            endMinutes = endMinutes + 60;
          }
          newHours = startHours + endHours;
          newMinutes = endMinutes - startMinutes;
          cout << "The difference in time is " << newHours << " hour(s) and " << newMinutes << " minute(s)."; // output
        } else if (endTime > startTime) { // difference between two days of time
          startHours = startTime / 100;
          endHours = endTime / 100;
          startMinutes = startTime - startHours * 100;
          endMinutes = endTime - endHours * 100;
          if (startMinutes > endMinutes) { // hour to minute handler
            endHours--;
            endMinutes = endMinutes + 60;
          }
          newHours = endHours - startHours;
          newMinutes = endMinutes - startMinutes;
          cout << "The difference in time is " << newHours << " hour(s) and " << newMinutes << " minute(s)."; // output
        }
      }
    } else if (menu == 2) { // Parabola
      cout << "\033[2J\033[1;1H";
      cout << "Parabola";
      // input
      cout << "\nEnter a, b, and c: ";
      cin >> a >> b >> c;
      cout << "Enter X1 and Y1: ";
      cin >> X1 >> Y1;
      cout << "Enter X2 and Y2: ";
      cin >> X2 >> Y2;
      // cout << "\ntest - a: " << a << " b: " << b << " c: " << c << " x1 : " << X1 << " y1: " << Y1 << " x2: " << X2 << " y2: " << Y2;
      // square root and denom. calculatons
      squareRoot = sqrt((b * b) - (4 * a * c));
      imgSquareRoot = (b * b) - (4 * a * c);
      intSquareRoot = sqrt(((b - m) * (b - m)) - (4 * a * (c - yInt)));
      denom2a = 2 * a;
      if ((b * b) - (4 * a * c) < 0) { // imaginary handler
        img = -float(b)/(float(a) * 2);
        cout << "\nThere are imaginary roots.";
        cout << "\nImaginary Root #1: " << img << "+" << (sqrt(-imgSquareRoot)/denom2a) << "i";
        cout << "\nImaginary Root #2: " << img << "-" << (sqrt(-imgSquareRoot)/denom2a) << "i";
      } else {
        firstRoot = (-b + squareRoot)/denom2a;
        secondRoot = (-b - squareRoot)/denom2a;
        if (firstRoot == secondRoot) {
          cout << "\nThere is only 1 root." << "\nRoot: " << firstRoot;
        } else {
          cout << "\nRoot #1: " << firstRoot;
          cout << "\nRoot #2: " << secondRoot;
        }
      }
      // slope and y-intercepts
      m = (X2 - X1)/(Y2 - Y1);
      yInt = Y1 - (m * X1);
      // intercept
      xintercept = (-(b - m) + intSquareRoot)/denom2a;
      xintercept2 = (-(b - m) - intSquareRoot)/denom2a;
      yintercept = (m * xintercept) + b;
      yintercept2 = (m * xintercept2) + b;
      cout << "\n\nSlope: " << m;
      cout << "\nY-Intercept: " << yInt;
      cout << "\n\nIntesect #1: " << fixed << setprecision(2) << xintercept << ", " << yintercept;
      cout << "\nIntesect #2: " << fixed << setprecision(2) << xintercept2 << ", " << yintercept2;
    } else { // Invalid Program 
      cout << "\nYou have chosen an invalid program.";
    }
    // loop handler
    cout << "\nRun again? (y/n): ";
    cin >> ans;
  } while (ans == 'y' or ans == 'Y');
  cout << "\033[2J\033[1;1H";
  // system("Pause");
  return 0;
}