#include "../include/Mystring.h"

int Mystrcmpend (const void *PtrToLine1, const void *PtrToLine2)
{
    String *line1 = (String*) PtrToLine1;
    String *line2 = (String*) PtrToLine2;

    int counter1 = line1->lengthofstr - 1;
    int counter2 = line2->lengthofstr - 1;

    for (; counter1 >= 0 && counter2 >= 0; counter1--, counter2--)
    {
            while(!isalpha(line1->ptrtostr[counter1]))
                counter1--;
            while(!isalpha(line1->ptrtostr[counter2]))
                counter2--;

            if (line1->ptrtostr[counter1] < line2->ptrtostr[counter1])
                return LESS;

            else if (line1->ptrtostr[counter1] > line2->ptrtostr[counter1])
                return MORE;
    }
    if(line1->lengthofstr < line2->lengthofstr)
        return LESS;
    else
        return MORE;

    return EQUAL;
}
