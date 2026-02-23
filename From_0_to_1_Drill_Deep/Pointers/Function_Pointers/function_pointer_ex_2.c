#include <stdio.h>

typedef int (*operation_t) (int, int);

int sum(int a,int b)
{
    return a+b;
}

int product(int a, int b)
{
    return a * b;
}

int whole_division(int a, int b)
{
    return a/b;
}

int remainder_division(int a, int b)
{
    return a%b;
}


int main(void)
{
   operation_t operation;

   operation = sum;
   printf("The first function pointer sum()-> %d\n",operation(1,2));

    operation = product;
    printf("The 2nd function pointer product()-> %d\n",operation(1,2));

    operation = whole_division;
    printf("The 3rd function pointer whole_division()-> %d\n",operation(1,2));

    operation = remainder_division;
    printf("The 3rd function pointer remainder_division()-> %d\n",operation(1,2));


    return 0;
}