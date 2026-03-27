#include "no_malloc.h"


int main(void)
{
    //do not use malloc() and free() from C language because these do not call constructor and destructor, only allocate memory on the heap
    ComplexNumber *cptr = (ComplexNumber *) malloc(sizeof(ComplexNumber));
    cout<<"Malloc was called for cptr object "<<endl;
    cptr->print();
    free(cptr);

    //use new and delete instead to make a call to allocating, deallocating, constructors and destructors alike
    float *fptr = new float(3.14);
    cout<<"new was called for fptr object"<<endl;
    delete fptr;

    ComplexNumber *cptr_new = new ComplexNumber(1978,2011);
    cout<<"a new object was allocated memory for and member variables initialized through constructor"<<endl;
    cptr_new->print();
    delete cptr_new;
    

    return 0;
}