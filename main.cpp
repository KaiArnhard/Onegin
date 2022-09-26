#include "Mystring.h"

enum SizeOfStr
{
SIZEONEGIN = 181000,
SIZEPTR = 5635,
};

struct Ptr
{
 unsigned char *Oneginptr[SIZEPTR] = {};
 int sizeofstrs[SIZEPTR] = {};
};

void   inputonegin  (unsigned char *Onegin);
void inputOneginptr (unsigned char *Onegin, unsigned char *Oneginptr[]);

void outputOnegin (unsigned char *Oneginptr[]);
void Mysort (unsigned char *Oneginptr[], int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1));

int main()
{
    unsigned char Onegin [SIZEONEGIN] = {0};
    unsigned char* Oneginptr [SIZEPTR]  = {0};

    inputonegin    (Onegin);
    inputOneginptr (Onegin, Oneginptr);
    Mysort (Oneginptr, Mystrcmp);

    outputOnegin (Oneginptr);

    return 0;
}

void Mysort (unsigned char *Oneginptr[], int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1))
{
    size_t fromstart  = 0;
    size_t fromend = SIZEPTR - 1;
    bool b = TRUE;

    while (b)
    {
        b = FALSE;
        fromstart++;
        for (size_t fromstart1 = fromstart; fromstart1 < fromend; fromstart1++)
        {
            if (Mystrcmp (Oneginptr [fromstart1], Oneginptr [fromstart1 + 1]) == 1)
            {
                swap1(&(Oneginptr[fromstart1]), &(Oneginptr[fromstart1 + 1]));
                b = TRUE;
            }
        }
        if(!b)
            break;
        fromend--;
        for (size_t fromend1 = fromend; fromend1 > fromstart; fromend1--)
            if (Mystrcmp (Oneginptr[fromend1], Oneginptr[fromend1 - 1]) == 0)
            {
                swap1(&(Oneginptr[fromend1]), &(Oneginptr[fromend1 - 1]));
                b = TRUE;
            }
    }

}

void inputonegin (unsigned char *Onegin)
{

    const char* filename = "Gamlet.txt";
    FILE *fp = fopen (filename, "r");
    assert(fp != 0);

    fread (Onegin, sizeof (char), SIZEONEGIN, fp);
}

void inputOneginptr (unsigned char *Onegin, unsigned char *Oneginptr[])
{
    int counterptr = 0;
    Oneginptr [counterptr] = Onegin;
    counterptr++;

    for (size_t counter = 1; Onegin[counter] != '\0'; counter++)
    {
        if ((Onegin [counter] == '\n') && (Onegin[counter + 1] != '\n'))
        {
            Oneginptr [counterptr] = Onegin + (counter + 1);
            counterptr++;
            Onegin[counter] = '\0';
        }
    }
}

void outputOnegin (unsigned char *Oneginptr[])
{
    const char* filename = "Gamlet1.txt";
    FILE *fp1 = fopen (filename, "w");
    size_t counter = 0;

    while ((Oneginptr [counter] != 0) && (counter < SIZEPTR))
    {
        fprintf (fp1, "%s\n", Oneginptr [counter]);
        counter++;
    }
}
