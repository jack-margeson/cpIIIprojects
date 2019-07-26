/* lineseg.cpp
Quadrilateral class lab, to practice making classes.
Jack Margeson, 04/30/2019 */
// cout << "\033[2J\033[1;1H";

// inclusions and namespace
#include <iostream>
#include <point.h>
#include <lineseg.h>
#include <quad.h>
using namespace std;

// main program
int main(){
  // declaration and init 
  char ans; // used for looping

  do {
    cout << "\033[2J\033[1;1H";
    cout << "Point Testing\n-----" << endl;
    // setting and declaration
    point p1, p2(1,2);
    p1.setX(6);
    p1.setY(14);
    // output
    cout << p1.toString() << endl;
    cout << p2.toString() << endl;
    cout << p1.getY() << endl;
    cout << endl;
    cout << "Lineseg Testing\n-----" << endl;
    // setting and declaration
    lineseg l1, l2(p1,p2);
    l1.setSP(point(15,0));
    l1.setEP(point(0,10));
    // output
    cout << l1.toString() << endl;
    cout << l2.toString() << endl;
    cout << l1.findDistance() << endl;
    cout << l2.findSlope() << endl;
    cout << endl;
    cout << "Quad Testing\n-----" << endl;
    // setting and declaration
    quad q1(lineseg(point(0,0), point(0,5)), lineseg(point(0,5), point(10,5)), lineseg(point(10,5), point(10,0)), lineseg(point(10,0), point(0,0)));
    // output
    cout << q1.toString() << endl;
    if(q1.isPara()){cout<<"☑ Parallelogram"<< endl;}else{cout<<"☐ Parallelogram"<< endl;}
    if(q1.isRect()){cout<<"☑ Rectangle"<< endl;}else{cout<<"☐ Rectangle"<< endl;}
    if(q1.isRhomb()){cout<<"☑ Rhombus"<< endl;}else{cout<<"☐ Rhombus"<< endl;}
    if(q1.isSquare()){cout<<"☑ Square"<< endl;}else{cout<<"☐ Square"<< endl;}
    // user defined quad
    float x1, x2, x3, x4, y1, y2, y3, y4;
    cout << endl;
    cout << "Enter Point #1: "; cin >> x1 >> y1;
    cout << "Enter Point #2: "; cin >> x2 >> y2;
    cout << "Enter Point #3: "; cin >> x3 >> y3;
    cout << "Enter Point #4: "; cin >> x4 >> y4;
    quad q2(lineseg(point(x1,y1), point(x2,y2)), lineseg(point(x2,y2), point(x3,y3)), lineseg(point(x3,y3), point(x4,y4)), lineseg(point(x4,y4), point(x1,x2)));
    // output
    cout << q2.toString() << endl;
    if(q2.isPara()){cout<<"☑ Parallelogram"<< endl;}else{cout<<"☐ Parallelogram"<< endl;}
    if(q2.isRect()){cout<<"☑ Rectangle"<< endl;}else{cout<<"☐ Rectangle"<< endl;}
    if(q2.isRhomb()){cout<<"☑ Rhombus"<< endl;}else{cout<<"☐ Rhombus"<< endl;}
    if(q2.isSquare()){cout<<"☑ Square"<< endl;}else{cout<<"☐ Square"<< endl;}

    // loop statement
    cout << "Run again? (y/n): "; cin >> ans;
  } while(ans == 'Y' || ans == 'y');
}