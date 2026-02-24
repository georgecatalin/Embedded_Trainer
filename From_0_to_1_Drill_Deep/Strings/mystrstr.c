#include <stdio.h>
#include <stdlib.h>


char *mystrstr(const char *haystack, const char *needle)
{
    if( (haystack==NULL) || (needle==NULL))
        return NULL;

    while (*haystack!='\0')
    {
        if(*haystack == *needle)
        {
            const char *h = haystack;
            const char *n = needle;

            while(*n!='\0' && *h==*n)
            {
                h++;
                n++;
            }

            if(*n=='\0')
                return (char *) haystack;
        }


        haystack++;
    }
    
    return NULL;
}

int main(void)
{
    char *word ="C Programming is still a very useful skill to have ";
    char *result = mystrstr(word,"skill");

    printf("The memory address where the string was found is %p\n",result);
    printf("The string from where the needle was found is \'%s\'.\n", result);

    printf("The second character after the first character where it matched is %c.\n", *(result + 1)); //'k'



    return 0;
}