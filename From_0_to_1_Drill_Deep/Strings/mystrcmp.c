#include <stdio.h>
#include <assert.h>

int mystrcmp(const char *string1, const char *string2)
{
    if (string1 == NULL && string2 == NULL)
        return 0;

    if(string1 == NULL  && string2 != NULL)
        return 0-*string2;

    if(string1!=NULL && string2 == NULL)
        return *string1;

    const char *ch1 = string1;
    const char *ch2 = string2;

    while(*ch1 !='\0' && *ch2!='\0')
    {
        if(*ch1 != *ch2)
        {
            return ch1 - ch2;
        }

        ch1++;
        ch2++;

    }
    
    if(*ch1=='\0' && *ch2!='\0')
        return 0 - *ch2;

    if(*ch1!='\0' && *ch2=='\0')
        return *ch1;

    return 0;

}


int main(void)
{
   char *word1 ="George";
   char *word2 ="George";
   char *word3 ="Mara";

   assert(mystrcmp(word1,word2) == 0);
   assert(mystrcmp(word1,word3) <0);


    return 0;
}