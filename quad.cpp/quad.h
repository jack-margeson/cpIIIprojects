#ifndef _QUAD_H
#define _QUAD_H
#include <point.h>
#include <lineseg.h>
#include <math.h>

class quad {
  public: 
    // constructors
    quad();
    quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4); 

    // member functions
    // sets
    void setL1(lineseg l1);
    void setL2(lineseg l2);
    void setL3(lineseg l3);
    void setL4(lineseg l4);
    // gets
    lineseg getL1();
    lineseg getL2();
    lineseg getL3();
    lineseg getL4();
    // finds
    std::string toString();
    bool isPara();
    bool isRect();
    bool isRhomb();
    bool isSquare();
  private:
    // data
    lineseg my_l1, my_l2, my_l3, my_l4;
};
// default constructor
quad::quad(){
  my_l1.setSP(point(0,0));
  my_l1.setEP(point(0,0));
  my_l2.setSP(point(0,0));
  my_l2.setEP(point(0,0));
  my_l3.setSP(point(0,0));
  my_l3.setEP(point(0,0));
  my_l4.setSP(point(0,0));
  my_l4.setEP(point(0,0));
}
// fill constructor
quad::quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4){
  my_l1.setSP(l1.getSP());
  my_l1.setEP(l1.getEP());
  my_l2.setSP(l2.getSP());
  my_l2.setEP(l2.getEP());
  my_l3.setSP(l3.getSP());
  my_l3.setEP(l3.getEP());
  my_l4.setSP(l4.getSP());
  my_l4.setEP(l4.getEP());
}
// setL1
void quad::setL1(lineseg l1){
  my_l1 = l1;
}
// setL2
void quad::setL2(lineseg l2){
  my_l2 = l2;
}
// setL3
void quad::setL3(lineseg l3){
  my_l3 = l3;
}
// setL4
void quad::setL4(lineseg l4){
  my_l4 = l4;
}
// getL1
lineseg quad::getL1(){
  return(my_l1);
}
// getL2
lineseg quad::getL2(){
  return(my_l2);
}
// getL3
lineseg quad::getL3(){
  return(my_l3);
}
// getL4
lineseg quad::getL4(){
  return(my_l4);
}
bool quad::isPara(){
  return(my_l1.findDistance()==my_l3.findDistance() && my_l2.findDistance()==my_l4.findDistance());
}
bool quad::isRect(){
  return(isPara() && (sqrt(pow(my_l1.findDistance(),2)+pow(my_l2.findDistance(),2))==sqrt(pow(my_l3.findDistance(),2)+pow(my_l4.findDistance(),2))));
}
bool quad::isRhomb(){
  return (isPara() && my_l1.findDistance() == my_l2.findDistance() && my_l3.findDistance()==my_l4.findDistance());
}
bool quad::isSquare(){
  return (isRhomb() && isRect());
}
// toString
std::string quad::toString(){
  return(my_l1.toString() + "\n" + my_l2.toString() + "\n" + my_l3.toString() + "\n" + my_l4.toString());
}
#endif