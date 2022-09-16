#include "Mystring.h"

enum SizeOfStr
{
SIZEONEGIN = 181000,
SIZEPTR = 10000,
};

void   inputonegin  (unsigned char *Onegin);
void inputOneginptr (unsigned char *Onegin, unsigned char *Oneginptr[]);

void outputOnegin (unsigned char *Oneginptr[]);
void Mysort (unsigned char *Oneginptr[]);

int main()
{
    unsigned char Onegin [SIZEONEGIN] = {0};
    unsigned char* Oneginptr [SIZEPTR]  = {0};

    inputonegin    (Onegin);
    inputOneginptr (Onegin, Oneginptr);
    Mysort (Oneginptr);

    outputOnegin (Oneginptr);

    return 0;
}

void Mysort(unsigned char *Oneginptr[])
{
    size_t fromstart  = 0;
    size_t fromend    = SIZEPTR;
    unsigned char *pt = 0;

    while (fromstart != SIZEPTR && fromend != 0)
    {
        if (Mystrcmp ((char*) Oneginptr [fromstart], (char*) Oneginptr [fromend]) > 0)
        {
            pt = Oneginptr [fromend];
            Oneginptr [fromend] = Oneginptr [fromstart];
            Oneginptr [fromstart] = pt;
        }
        else if (Mystrcmp ((char*) Oneginptr [fromstart], (char*) Oneginptr [fromend]) == 0)
        {
            pt = Oneginptr [fromstart];
            Oneginptr [fromstart] = Oneginptr [fromend];
            Oneginptr [fromend] = pt;
        }
        fromstart ++;
        fromend --;
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
    int counter1 = 0;
    Oneginptr [counter1] = Onegin;
    counter1 ++;
    for (size_t counter = 1; counter <= SIZEONEGIN; counter++)
    {
        if ((Onegin [counter] == '\n') && (Onegin [counter + 1] != '\n'))
        {
            Oneginptr [counter1] = Onegin + (counter + 1);
            counter1 ++;
            Onegin [counter] = '\0';
        }
        else if (Onegin [counter] == '\n')
        Onegin [counter] = ' ';
    }
}

void outputOnegin (unsigned char *Oneginptr[])
{
    const char* filename = "Gamlet1.txt";
    FILE *fp1 = fopen (filename, "w");
    size_t counter = 0;

    while ((Oneginptr [counter] != 0) && (counter <= 10000))
    {
        fprintf (fp1, "%s\n", Oneginptr [counter]);
        counter++;
    }
}
