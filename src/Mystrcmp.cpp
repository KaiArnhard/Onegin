#include "../include/Mystring.h"

int Mystrcmp (const void *PtrToLine1, const void *PtrToLine2)
{
    int counter = 0;
    String *line1 = (String*) PtrToLine1;
    String *line2 = (String*) PtrToLine2;

    for (; line1->ptrtostr[counter] != '\0' && line2->ptrtostr[counter] != '\0'; counter++)
    {
        if (line1->ptrtostr[counter] < line2->ptrtostr[counter])
            return LESS;

        else if (line1->ptrtostr[counter] > line2->ptrtostr[counter])
            return MORE;
    }
    if (line1->ptrtostr[counter] == '\0')
        return LESS;
    else if (line2->ptrtostr[counter] == '\0')
        return MORE;

    return EQUAL;
}

void swap1 (char **str,char **str1)
{
    char *temp = *str1;
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
