#include <stdio.h>

int count_1_bits_in_integer(int number)
{
    int counter = 0;

    while(number != 0)
    {
        number = number & (number - 1);
        counter ++;
    }


    return counter;
}

int main(void)
{
    int number_of_bits = count_1_bits_in_integer(1978);

    printf("The number of bits with 1 in the 1978 is %5d.\n",number_of_bits);

    return 0;
}