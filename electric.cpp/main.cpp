#include <iostream>
#include <math.h>
using namespace std;

int main() {
  const double cost = 0.0475;
  int kwh;
  float baserate;

  cout << "Enter the amount of kilowatt hours used: ";
  cin >> kwh;
  baserate = kwh * cost;
  baserate = ceilf(baserate * 100) / 100;
  cout << "Base Rate " << kwh << "kwh @ $" << cost << ": " << baserate << "\n";

  return 0;
}