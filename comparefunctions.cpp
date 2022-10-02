#include "Mystring.h"
#include "comparefunctions.h"

int Mystrcmpend(const void *PtrToLine1, const void *PtrToLine2)
{
    String *line1 = (String*) PtrToLine1;
    String *line2 = (String*) PtrToLine2;

    int counter1 = line1->lengthofstr - 1;
    int counter2 = line2->lengthofstr - 1;

    for (; counter1 > -1 && counter2 > -1; counter1--, counter2--)
    {
            while(!isalpha(line1->ptrtostr[counter1]))
                counter1--;
            while(!isalpha(line2->ptrtostr[counter2]))
                counter2--;

            if (line1->ptrtostr[counter1] < line2->ptrtostr[counter2])
                return LESS;

            else if (line1->ptrtostr[counter1] > line2->ptrtostr[counter2])
                return MORE;
    }

    if(line1->lengthofstr < line2->lengthofstr)
        return LESS;

    else
        return MORE;

    return EQUAL;
}

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

void swap1 (String *PtrToLine1, String *PtrToLine2)
{
    char *temp = PtrToLine2->ptrtostr;
    int templength = PtrToLine2->lengthofstr;

    PtrToLine2->ptrtostr = PtrToLine1->ptrtostr;
    PtrToLine1->ptrtostr = temp;

    PtrToLine2->lengthofstr = PtrToLine1->lengthofstr;
    PtrToLine1->lengthofstr = templength;
}

void Mysort (void *PtrToLine, Lengths Length, int (*Mystrcmp)(const void *PtrToLine1, const void *PtrToLine2))
{
    int fromstart  = -1;
    int fromend = Length.NumberOfLines - 1;
    bool b = TRUE;
    String *line = (String *) PtrToLine;

    while (b)
    {
        fromstart++;
        b = FALSE;

        for (int fromstart1 = fromstart; fromstart1 < fromend; fromstart1++)
        {
            if (Mystrcmp((line + fromstart1), (line + fromstart1 + 1)) == MORE)
            {
                swap1(line + fromstart1, line + fromstart1 + 1);
                b = TRUE;
            }
        }
        if(!b)
            break;
        fromend--;
        for (int fromend1 = fromend; fromend1 > fromstart; fromend1--)
            if (Mystrcmp((line + fromend1), (line + fromend1 - 1)) == LESS)
            {
                swap1(line + fromend1, line + fromend1 - 1);
                b = TRUE;
            }
    }

}

size_t Mystrlen(const char *str)
{
    size_t counter = 0;

    for (; str[counter] != '\0'; counter++)
    { }

    return counter;
}
