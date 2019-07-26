#ifndef _LINESEG_H
#define _LINESEG_H
#include <point.h>
#include <math.h>

class lineseg {
  public: 
    // constructors
    lineseg();
    lineseg(point sp, point ep); 

    // member functions
    // sets
    void setSP(point SP);
    void setEP(point EP);
    // gets
    point getSP();
    point getEP();
    // finds
    float findSlope();
    float findDistance();
    std::string toString();

  private:
    // data
    point my_sp; // start point
    point my_ep; // end point
};
// default constructor
lineseg::lineseg(){
  my_sp = point(0,0);
  my_ep = point(0,0);
}
// fill constructor
lineseg::lineseg(point sp, point ep){
  my_sp = sp;
  my_ep = ep;
}
// set start point 
void lineseg::setSP(point sp){
  my_sp = sp;
}
// set end point 
void lineseg::setEP(point ep){
  my_ep = ep;
}
// get start point 
point lineseg::getSP(){
  return my_sp;
}
// get end point 
point lineseg::getEP() {
  return my_ep;
}
// find slope
float lineseg::findSlope() {
  // (y1-y2)/(x1-x2)
  return ((my_ep.getY() - my_sp.getY()) / (my_ep.getX() - my_sp.getX()));
}
// find distance 
float lineseg::findDistance() {
  float i, j;
  i = my_sp.getX() - my_ep.getX();
  j = my_sp.getY() - my_ep.getY();
  return(sqrt(pow(i,2) + pow(j,2)));
}
// toString
std::string lineseg::toString() {
 return("(" + my_sp.toString() + "," + my_ep.toString() + ")");
}
#endif