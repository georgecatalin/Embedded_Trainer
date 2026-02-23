#include <stdio.h>

int extract_nth_bit(int number, int n)
{
    int extract_nth_bit = 1 << n;

    int result = number & extract_nth_bit;

    if (result == extract_nth_bit)
    {
        return 1;
    }

    return 0;

}

int set_nth_bit(int number, int n)
{
    int set_nth_bit = 1 << n;
    int result = number | set_nth_bit;

    return result;
}

int main(void)
{
    int returned_code = extract_nth_bit(2,1);

    printf("The bit at requested position is  is %-4d \n", returned_code);

    returned_code = set_nth_bit(2,1);
    printf("The bit set requested position is  is %-4d \n", returned_code);

    return 0;
}