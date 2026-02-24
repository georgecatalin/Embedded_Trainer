#include <stdio.h>
#include <stdlib.h>

void function1(int *int_ptr)
{
    *int_ptr = 1954;
    printf("The value of *ptr in function1 is %d.\n",*int_ptr);
}


void function2(int *int_ptr)
{
    int_ptr = (int *) malloc(sizeof(int));
    *int_ptr = 1953;

    printf("The value of *ptr in function1 is %d.\n",*int_ptr);
}

int main(void)
{
    int year = 1978;
    int *ptr_year = &year;

    int *ptr_year_2 = &year;

    function1(ptr_year);
    printf("The value of %d the pointer after modification in function.\n", year);   //1954

    function2(ptr_year_2);
    printf("The value of %d the pointer after modification in function.\n", year);   //1954

    return 0;
}