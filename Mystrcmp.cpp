#include "Mystring.h"

int Mystrcmp (const unsigned char *str, const unsigned char *str1)
{
    size_t strsize  = Mystrlen(str);
    size_t str1size = Mystrlen(str1);
    size_t maximum = 0;

    if (strsize < str1size)
        maximum = strsize;
    else
        maximum = str1size;

    for (size_t counter = 0; counter < maximum; counter++)
    {
        if (str [counter] < str1 [counter])
            return LESS;

        else if (str[counter] > str1 [counter])
            return MORE;

    }
    return EQUAL;
}

void swap1 (unsigned char **str, unsigned char **str1)
{
    unsigned char *pt = *str1;
    *str1 = *str;
    *str = pt;
}

