#include <stdio.h>

void hello()
{
    printf("Hello , function pointers.\n");
}

typedef void (* hello_ptr) ();

void call_function_pointer(hello_ptr some_pointer_function)
{
    some_pointer_function();
}


int main(void)
{
    call_function_pointer(hello);

    return 0;
}