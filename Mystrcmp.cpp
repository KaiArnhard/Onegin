#include "Mystring.h"

int Mystrcmp (const unsigned char *str, const unsigned char *str1, size_t strsize, size_t str1size)
{
    size_t maximum = 0;

    if (strsize < str1size)
        maximum = strsize;
    else
        maximum = str1size;
    size_t counter1 = 0;
    size_t counter2 = 0;

    for (size_t counter = 0; counter < maximum; counter++)
    {
        counter1 = counter2 = counter;
        if (!compare(str[counter]))
        {
            counter1 = counter + 1;
        }
        if (!compare(str1[counter]))
        {
            counter2 = counter + 1;
        }

        if (str[counter1] < str1[counter2])
            return LESS;

        else if (str[counter1] > str1[counter2])
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

bool compare(const unsigned char str)
{
const unsigned char str2[] = "\n'\",;:. [";

for (int counter = 0; str2[counter] != '\0'; counter++)
    {
        if(str == str2[counter])
            return FALSE;
    }
return TRUE;
}

