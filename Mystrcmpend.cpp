#include "Mystring.h"

int Mystrcmpend (const unsigned char *str, const unsigned char *str1, int strsize, int str1size)
{
    int counter1 =  strsize - 1;
    int counter2 = str1size - 1;
    // TODO check for trash
    for (; (counter1 >= 0) && (counter2 >= 0); counter1--, counter2--)
    {
        //if (isalpha(str[counter]) && is
        if (str[counter1] < str1[counter2])
            return LESS;

        else if (str[counter1] > str1[counter2])
            return MORE;

    }
    return EQUAL;
}
