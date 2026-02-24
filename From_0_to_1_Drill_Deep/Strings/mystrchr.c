#include <stdio.h>


char * mystrchr(const char *string, int c)
{
    if(string == NULL)
        return NULL;

    while (*string != '\0')
    {
        if(*string == c)
        {
            return (char *) string;
        }

        string++;
    }
    
    return NULL;
}


int main(void)
{
    char *ptrtoposn=mystrchr("George", 'r');
    printf("the memory address where the character %c is found =%p\n",'r',ptrtoposn);

    printf("The string starting from the position where the character was found is %s.\n", ptrtoposn);
    printf("The next letter after the position where found %c.\n", *(ptrtoposn+1));


    return 0;
}