#include "Mystring.h"

// TODO calculate number of chars and lines

// TODO rename
// TODO array of structs
struct PtrsToBuffer
{
    char *ptrtostr = 0;
    int  sizeofstr = 0;
};

struct Sizes
{
    int NumberOfLines = 0;
    int SizeOfBuffer  = 0;
};

void   InputBuffer  (char **Buffer, char *FileName, Sizes *Size1);
void InputPtrToBuffer (PtrsToBuffer *PtrToLine, Sizes *Size1, char *Buffer);

void Output(PtrsToBuffer *PtrToLine, Sizes *Size1);
//void Mysort (Ptr *Onegin, int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1, int strsize, int str1size));

int main()
{
    char *Buffer = 0;
    Sizes Size1;
    FILE *fp = fopen("Gamlet1.txt", "w");

    InputBuffer(&Buffer, "Gamlet.txt", &Size1);

    PtrsToBuffer PtrToLine[Size1.NumberOfLines];
    InputPtrToBuffer (PtrToLine, &Size1, Buffer);

    //Mysort (&Onegin, Mystrcmp);
    //Mysort (&Onegin, Mystrcmpend);
    //Output (PtrToLine, &Size1);
    fwrite(Buffer,sizeof(char), Size1.SizeOfBuffer, fp);
    free(Buffer);

    return 0;
}

// TODO check sort
/*void Mysort (Ptr *Onegin, int (*Mystrcmp)(const unsigned char *str, const unsigned char *str1, int strsize, int str1size))
{
    int fromstart  = -1;
    int fromend = Onegin->realsize - 1;
    bool b = TRUE;

    while (b)
    {
        b = FALSE;
        fromstart++;
        for (int fromstart1 = fromstart; fromstart1 < fromend; fromstart1++)
        {
            if (Mystrcmp(Onegin->Oneginptr[fromstart1], Onegin->Oneginptr[fromstart1 + 1], \
            Onegin->sizeofstrs[fromstart1], Onegin->sizeofstrs[fromstart1 + 1]) == MORE)
            {
                swap1(&(Onegin->Oneginptr[fromstart1]), &(Onegin->Oneginptr[fromstart1 + 1]));
                b = TRUE;
            }
        }
        if(!b)
            break;
        fromend--;
        for (int fromend1 = fromend; fromend1 > fromstart; fromend1--)
            if (Mystrcmp(Onegin->Oneginptr[fromend1], Onegin->Oneginptr[fromend1 - 1], \
            Onegin->sizeofstrs[fromend1], Onegin->sizeofstrs[fromend1 + 1]) == LESS)
            {
                swap1(&(Onegin->Oneginptr[fromend1]), &(Onegin->Oneginptr[fromend1 - 1]));
                b = TRUE;
            }
    }

}*/

void InputBuffer (char **Buffer, char *FileName, Sizes *Size1)
{

    struct stat statistic = {};
    stat(FileName, &statistic);

    Size1->SizeOfBuffer = statistic.st_size;
    *Buffer = (char*) calloc(Size1->SizeOfBuffer, sizeof(char));

    FILE *fp = fopen (FileName, "r");
    assert(fp != 0);
    assert(fread(*Buffer, sizeof(char), statistic.st_size, fp) != Size1->SizeOfBuffer);

    Size1->NumberOfLines++;
    /*for (int counter = 0; (counter + 1) < Size1->SizeOfBuffer; counter++)
    {
        txDump(*Buffer + counter);
        if (*Buffer[counter] == '\n' && *Buffer[counter + 1] != '\n' && *Buffer[counter + 1] != '\r' && *Buffer[counter + 1] != ' ')
        {
            *Buffer[counter] = '\0';
            Size1->NumberOfLines++;
        }
    } */

}

void InputPtrToBuffer (PtrsToBuffer *PtrToLine, Sizes *Size1, char *Buffer)
{
    int counter = 0;
    int counter1 = 0;

    while(!isalpha(Buffer[counter]))
            counter++;
    (PtrToLine + counter1)->ptrtostr = Buffer + counter;
    counter++;

    for (; counter < Size1->SizeOfBuffer && counter1 < Size1->NumberOfLines; counter++)
    {
        if (Buffer[counter - 1] == '\0')
        {
            while(!isalpha(Buffer[counter]))
                counter++;
            (PtrToLine + counter1)->ptrtostr = Buffer + counter;
        }
    }
}                                           //todo filename input

void Output (PtrsToBuffer *PtrToLine, Sizes *Size1)
{
    const char* filename = "Gamlet1.txt";
    FILE *fp1 = fopen (filename, "w");

    for(int counter = 0; (PtrToLine[counter].ptrtostr != 0) && (counter < Size1->NumberOfLines); counter++)
    {
        fprintf (fp1, "%s", PtrToLine[counter].ptrtostr);
    }
}
