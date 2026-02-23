#include <stdio.h>

void print_bits_of_integer(int number)
{
    unsigned int check_bit = 1 << (sizeof(int) * 8 -1);

    while(check_bit != 0)
    {
        int result = number & check_bit;

        if(result == check_bit)
        {
            printf("%2d",1);
        }
        else
        {
            printf("%2d",0);
        }

        check_bit = check_bit >> 1;
    }

}


int main(void)
{
    print_bits_of_integer(129);


    return 0;
}