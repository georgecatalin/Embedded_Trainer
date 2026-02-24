#include <stdio.h>

char *mystrcat(char *destination, const char *source)
{
    if(destination == NULL || source == NULL)   
        return destination;

    char *d = destination;

    while(*d!='\0')
    {
        d++;
    }
    

    while(*source!='\0')
    {
        *d = *source;
        d++;
        source++;
    }

    *d='\0';

    return (char *) destination;
}

int main(void)
{
    char *word1="George             ";
    char *word2="Calin";

    char *result = mystrcat(word1,word2);
    return 0;
}