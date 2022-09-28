#include "Mystring.h"

enum SizeOfStr
{
SIZEONEGIN = 181000,
SIZEPTR = 5635,
};

struct Ptr
{
unsigned char Onegin [SIZEONEGIN] = {};
unsigned char *Oneginptr[SIZEPTR] = {};
size_t sizeofstrs[SIZEPTR] = {};
};

void   inputonegin  (Ptr *Onegin);
void inputOneginptr (Ptr *Onegin);

void outputOnegin (Ptr *Onegin);
void Mysort (Ptr *Onegin, int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1, size_t strsize, size_t str1size));

int main()
{
    Ptr Onegin;

    inputonegin    (&Onegin);
    inputOneginptr (&Onegin);
    Mysort (&Onegin, Mystrcmp);

    outputOnegin (&Onegin);

    return 0;
}

void Mysort (Ptr *Onegin, int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1, size_t strsize, size_t str1size))
{
    size_t fromstart  = -1;
    size_t fromend = SIZEPTR - 1;
    bool b = TRUE;

    while (b)
    {
        b = FALSE;
        fromstart++;
        for (size_t fromstart1 = fromstart; fromstart1 < fromend; fromstart1++)
        {
            if (Mystrcmp (Onegin->Oneginptr[fromstart1], Onegin->Oneginptr[fromstart1 + 1], \
            Onegin->sizeofstrs[fromstart1], Onegin->sizeofstrs[fromstart1 + 1]) == 1)
            {
                swap1(&(Onegin->Oneginptr[fromstart1]), &(Onegin->Oneginptr[fromstart1 + 1]));
                b = TRUE;
            }
        }
        if(!b)
            break;
        fromend--;
        for (size_t fromend1 = fromend; fromend1 > fromstart; fromend1--)
            if (Mystrcmp (Onegin->Oneginptr[fromend1], Onegin->Oneginptr[fromend1 - 1], \
            Onegin->sizeofstrs[fromend1], Onegin->sizeofstrs[fromend1 + 1]) == 0)
            {
                swap1(&(Onegin->Oneginptr[fromend1]), &(Onegin->Oneginptr[fromend1 - 1]));
                b = TRUE;
            }
    }

}

void inputonegin (Ptr *Onegin)
{

    const char* filename = "Gamlet.txt";
    FILE *fp = fopen (filename, "r");
    assert(fp != 0);

    fread (Onegin->Onegin, sizeof (char), SIZEONEGIN, fp);
}

void inputOneginptr (Ptr *Onegin)
{
    size_t counterptr = 0;
    Onegin->Oneginptr[counterptr] = Onegin->Onegin;
    counterptr++;

    for (size_t counter = 1; Onegin->Onegin[counter] != '\0'; counter++)
    {
        if ((Onegin->Onegin[counter] == '\n') && (Onegin->Onegin[counter + 1] != '\n'))
        {
            Onegin->Oneginptr [counterptr] = Onegin->Onegin + (counter + 1);
            counterptr++;
        }
    }
    for (size_t counter = 1; Onegin->Onegin[counter] != '\0'; counter++)
    {
        if ((Onegin->Onegin[counter] == '\n') && (Onegin->Onegin[counter + 1] != '\n'))
        {
            Onegin->Onegin[counter] = '\0';
        }
    }
    for (size_t counter = 0; counter < counterptr; counter++)
    {
     Onegin->sizeofstrs[counter] = Mystrlen(Onegin->Oneginptr[counter]);
    }
}

void outputOnegin (Ptr *Onegin)
{
    const char* filename = "Gamlet1.txt";
    FILE *fp1 = fopen (filename, "w");
    size_t counter = 0;

    while ((Onegin->Oneginptr [counter] != 0) && (counter < SIZEPTR))
    {
        fprintf (fp1, "%s\n", Onegin->Oneginptr[counter]);
        counter++;
    }
}
