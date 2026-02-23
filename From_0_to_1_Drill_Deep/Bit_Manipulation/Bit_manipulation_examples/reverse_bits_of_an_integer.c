#include <stdio.h>

int reverse_bits_in_integer_ver_1(unsigned int number)
{
    unsigned int reversed_number = 0;
    int bits = sizeof(int) * 8;

    for(int i=0;i<bits;i++)
    {
        reversed_number = (reversed_number << 1) | (number & 1);
        number >>= 1;
    }

    return reversed_number;
}

int reverse_bits_in_integer_ver_2(unsigned int number)
{
    int reversed_number = 0;
    unsigned int counter = sizeof(int) * 8 - 1;

    while(number != 0)
    {
       int last_bit = number & 1;
       reversed_number = reversed_number | last_bit;
       reversed_number = reversed_number << 1;
       number >>= 1;
       counter --;
    }

    reversed_number = reversed_number << counter;

    return reversed_number;

}


int main(void)
{
    int my_number = 0;

    printf("Enter the integer whose bits you wish to reverse=");
    scanf("%d", &my_number);

    int reversed_number_1 = reverse_bits_in_integer_ver_1(my_number);
    int reversed_number_2 = reverse_bits_in_integer_ver_2(my_number);

    printf("The reversed number was obtained using: \n \t\tfunction version 1 = \t %d; \n \t\tfunction version 2 = \t %d \n", 
        reversed_number_1, reversed_number_2);

    return 0;
}