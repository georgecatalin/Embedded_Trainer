#include "new_place.h"

int main(void)
{
   char buffer_area[sizeof(ComplexNumber)];
   void *memory_address = (void *) buffer_area;
   
   ComplexNumber *cptr = new(memory_address) ComplexNumber(47,14); //this allocates memory at the specified memory address and calls the constructor
   cout<<"object allocated dynamically "<<endl;
   cptr->print();

   //although the destructor can not be called with delete in this case, it has to be appealed specifically by the object
   cptr->~ComplexNumber();



    return 0;
}