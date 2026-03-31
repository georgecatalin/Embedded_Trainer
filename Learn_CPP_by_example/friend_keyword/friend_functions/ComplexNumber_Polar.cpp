#include "CompleNumber_Polar.h"

ComplexNumber_Polar::ComplexNumber_Polar(double r, double theta) :
    modulus(r), argument(theta)
  {
    cout << "Inside the 2-argument constructor (Polar)" << endl;
  }



float ComplexNumber_Polar::getModulus() const { return modulus; }
void  ComplexNumber_Polar::setModulus(float r) { modulus = r;}

float ComplexNumber_Polar::getArgument() const { return argument; }
void  ComplexNumber_Polar::setArgument(float theta) { argument = theta;}

