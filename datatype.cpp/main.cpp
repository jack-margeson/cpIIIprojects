// DATATYPE.CPP
// Examples of variable declaration and
// initilization.

#include <iostream>
using namespace std;

int main(){
  // declare constants 
  const double SQUARE_ROOT_OF_TWO = 1.414214;
  const double e = 2.7182818;
  const int SPEED_OF_LIGHT = 299792458;
  const float SPEED_OF_SOUND = 340.292;

  // declare variables 
  int i; // declare i as integer
  long j; // j as a long integer
  unsigned long k; // k as an unsigned long integer
  float n; // n as a floating point number
  int o; // o as integer 
  int p; // p as integer 
  int q; // q as integer 
  int r; // r as integer 
  
  // initialize variables 
  i = 3; // init i to 3 
  j = -2048111; // init j to -2,048,111
  k = 4000000001; // init k to 4,000,000,001
  n = 1.887; // init n to 1.887
  o = 100; // init o to 100
  p = -1000; // init p to -1000
  q = -40000; // init q to -40,000
  r = 40000; // init r to 40,000

  // output constants and variables to the command line
  cout << SQUARE_ROOT_OF_TWO << "\n";
  cout << i << "\n";
  cout << j << "\n";
  cout << k << "\n";
  cout << n << "\n";
  cout << "\n";

  //output new constants and variables.
  cout << e << "\n";
  cout << SPEED_OF_LIGHT << "\n";
  cout << SPEED_OF_SOUND << "\n";
  cout << o << "\n";
  cout << p << "\n";
  cout << q << "\n";
  cout << r << "\n";
}
