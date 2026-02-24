#include <stdio.h>


int main(void)
{
    char *word = "Dacia";

    printf("The address where the first letter of the string \'%s\' is %p.\n",word, word);

    printf("The first letter of the string is %c.\n", *word);
    printf("The second letter of the string is %c.\n", *(word + 1));
    printf("The third letter of the string is %c.\n", *(word + 2));
    printf("The fourth letter of the string is %c.\n", *(word + 3));
    printf("The fifth letter of the string is %c.\n", *(word + 4));
    printf("The sixth letter of the string is %c.\n", *(word + 5));

    //modify the third letter
    //*(word + 2) = 'z'; // Segmentation fault (core dumped)
    printf("The third letter modified of the string is %c.\n", *(word + 2));

    return 0;
}