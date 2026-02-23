#include <stdio.h>

void hello()
{
    printf("Hello , function pointers.\n");
}

void call_hello(void (*hello_ptr) ())
{
    hello_ptr(); //function goes here
}



int main(void)
{
    call_hello(hello);


    return 0;
}