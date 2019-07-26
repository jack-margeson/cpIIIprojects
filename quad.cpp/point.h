#ifndef _POINT_H
#define _POINT_H

class point {
  public:
    // constructors 
    point();
    point(float x, float y);

    // member functions
    // 'Sets' are usually void with parameters.
    void setX(float x);
    void setY(float y);
    // 'Gets' are usually the datatype with no parameter.
    float getX();
    float getY();
    // !! All member functions have access to all private data !!
    std::string toString();

  private:
    // data
    float my_x;
    float my_y;
};

// default constructor 
point::point() {
  my_x = 0;
  my_y = 0;
}
// fill constuctor
point::point(float x, float y) {
  my_x = x;
  my_y = y;
}
// set x
void point::setX(float x){
  my_x = x;
}
// set y
void point::setY(float y){
  my_y = y;
}
// get x
float point::getX(){
  return my_x;
}
// get y
float point::getY(){
  return my_y;
}
// toString
std::string point::toString() {
  return("(" + std::to_string(my_x) + "," + std::to_string(my_y) + ")");
}
#endif