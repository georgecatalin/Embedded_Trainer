#include "this.h"


int main(void)
{
  ComplexNumber *complex = new ComplexNumber(1978,2011);

  cout<<"An object was created dynamically on the heap at this memory address "<<complex<<endl;

  complex->print();
 
  complex->printThis();

    return 0;
}