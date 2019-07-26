// randomASCII.cpp
// Outputs X random ASCII characters based on 
// 5 randomly generated numbers.
// Jack Margeson
// 02/04/2019

// include headers and libraries
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
  // declarations
  int random; // declare random
  int choice; // used for inputting choice
  string ans;

  do {
    cout << "Enter number of characters you would like to generate: ";
    cin >> choice;
    srand (time(NULL));
    for(int i=0;i<choice;i++){
      random = rand()%25+65;
      cout << "Number: " << random << "   Random Character: " << char(random) << "\n";
    }
    cout << "Run again? (y/n): ";
    cin >> ans;
  } while(ans == "y" or ans == "Y");
  // system("Pause");
  return 0;
}