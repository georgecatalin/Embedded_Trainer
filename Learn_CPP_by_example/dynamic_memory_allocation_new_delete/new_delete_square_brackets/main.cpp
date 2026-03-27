#include "new.h"

int main(void)
{
    //allocate space for the array and initialize each element of the array through its no argument constructor
   ComplexNumber *ComplexNumber_ptr = new ComplexNumber[20];

   for(int i = 0;i<20;i++)
   {
        cout<<"Details about the dynamically allocated object "<<i<<endl;
        ComplexNumber_ptr[i].print();
   }

    //call the destructoctor for each element of the array and in the end, deallocate the whole memory for the array
    delete[] ComplexNumber_ptr;

    return 0;
}