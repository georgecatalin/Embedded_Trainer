#include <stdio.h>

size_t mystrlen(const char *mystring)
{
    size_t length = 0;

    if(mystring == NULL)
        return 0;

    const char *temp_char = mystring;

    while(*temp_char!='\0')
    {
        length++;
        temp_char++;
    }

    return length;
}

int main(void)
{
   size_t length = mystrlen("George");

   printf("the length of the string is %lu.\n", length);

    return 0;
}