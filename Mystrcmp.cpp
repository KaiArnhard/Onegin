#include "Mystring.h"

int Mystrcmp (const unsigned char *str, const unsigned char *str1)
{
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;



    for (; str[counter] != '\0' && str1[counter] != '\0'; counter++)
    {
        if (str[counter1] < str1[counter2])
            return LESS;

        else if (str[counter1] > str1[counter2])
            return MORE;
    }
    if (str[counter] == '\0')
        return LESS;
    else if (str1[counter] == '\0')
        return MORE;

    return EQUAL;
}

void swap1 (unsigned char **str, unsigned char **str1)
{
    unsigned char *temp = *str1;
    *str1 = *str;
    *str = temp;
}

//Велосипед
int isletter(const unsigned char *str)
{
    const unsigned char str1[] = "'\",;:.[!?";
    int  counter = 0;

    for (int counter1 = 0; str1[counter1] != '\0'; counter1++)
    {
        if(str[counter] == str1[counter1])
            {
                counter++;
            }
    }
    return counter;
}

              //isalpha(char); ctype.h
