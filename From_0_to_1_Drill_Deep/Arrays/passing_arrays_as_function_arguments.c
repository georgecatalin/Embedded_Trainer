#include <stdio.h>

void print_array(int numbers[], int size_array)
{
    numbers[0] = 1977; //modifies the first element of the array in the callee function
    int other_array[] = {14, 47, 74, 75};

    numbers = other_array; // does not modify the array in the callee function

    for (int i = 0; i < 4; i++)
    {
        printf("\t%d\n", numbers[i]);
    }
}

int main(void)
{
    int numbers[] = {1953, 1954, 1978, 2011};

    print_array(numbers, 4);

    printf("\n\n%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    printf("%d\n", numbers[3]);

    return 0;
}