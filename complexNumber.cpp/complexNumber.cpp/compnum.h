#ifndef _COMPNUM_H
#define _COMPNUM_H

// inclusions and namespace
#include <string>
#include <sstream>

// class definition 
class compnum {
public:
	// constructors
	compnum(); // default
	compnum(std::string c1); // fill
	compnum(compnum &c1); // copy
	// member functions
	// sets
	void setMyA(float a);
	void setMyB(float b);
	// gets
	float getMyA();
	float getMyB();
	// finds
	std::string subtractComplex(compnum c2);
	std::string toString();
	// operators 
	compnum operator + (compnum c2);
	compnum operator - (compnum c2);
	compnum operator * (compnum c2);
	// compnum operator / (compnum c2);
	// compnum operator ^ (compnum c2);
private:
	// data 
	float my_a;
	float my_b;
};

compnum::compnum() { // default constructor 
	my_a = 1;
	my_b = 1;
}
compnum::compnum(std::string c1) { // fill constructor
  // split string by addition delimiter
	std::string temp_a, temp_b;
	const std::string delim = "+";
	size_t pos = c1.find(delim);
	temp_b = c1.substr(pos + 1);
	temp_a = c1.substr(0, (temp_b.length()));
	// set my_a and my_b using stringstream
	std::stringstream(temp_a) >> my_a;
	std::stringstream(temp_b) >> my_b;
}
compnum::compnum(compnum &c1) { // copy constructor
	my_a = c1.getMyA();
	my_b = c1.getMyB();
}
void compnum::setMyA(float a) { // setMyA
	my_a = a;
}
void compnum::setMyB(float b) { // setMyB
	my_b = b;
}
float compnum::getMyA() { // getMyA
	return(my_a);
}
float compnum::getMyB() { // getMyB
	return(my_b);
}
// calculations  with operators 
compnum compnum::operator + (compnum c2) { // addition
	compnum answer;
	answer.setMyA(my_a + c2.getMyA());
	answer.setMyB(my_b + c2.getMyB());
	return answer;
}
compnum compnum::operator - (compnum c2) { // subtraction
	compnum answer;
	answer.setMyA(my_a - c2.getMyA());
	answer.setMyB(my_b - c2.getMyB());
	return answer;
}
compnum compnum::operator * (compnum c2) { // multiplication
	compnum answer;
	answer.setMyA((my_a * c2.getMyA()) - (my_b * c2.getMyB()));
	answer.setMyB((my_a * c2.getMyB()) + (my_b * c2.getMyA()));
	return answer;
}
/* compnum compnum::operator / (compnum c2) { // division

}
compnum compnum::operator ^ (compnum c2) { // exponent

} */
std::string compnum::toString() { // toString
	return(std::to_string(my_a) + "+" + std::to_string(my_b) + "i");
}
#endif 