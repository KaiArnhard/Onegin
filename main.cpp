#include "Mystring.h"

char   *InputBuffer(char *FileName, Lengths *Length);
void InputPtrToBuffer(String *PtrToLine, Lengths *Length, char *Buffer);

void Output(String *PtrToLine, Lengths Length, char *FileName);
void OutputOrigin(char *Buffer, Lengths Length, char *FileName);

void Mysort (String *PtrToLine, Lengths Length, int (*Mystrcmp)(const void *PtrToLine, const void *PtrToLine1));

int main()
{
    Lengths Length;
    FileNames filename;
    char *Buffer = InputBuffer(filename.FNameOrig, &Length);

    String PtrToLine[Length.NumberOfLines];
    InputPtrToBuffer (PtrToLine, &Length, Buffer);

    Mysort (PtrToLine, Length, Mystrcmp);
    Output (PtrToLine, Length, filename.FNameSort);
    Mysort (PtrToLine, Length, Mystrcmpend);
    Output (PtrToLine, Length, filename.FNameSortFromEnd);

    OutputOrigin(Buffer, Length, filename.FNameOrigOut);

    return 0;
}

void Mysort (String *PtrToLine, Lengths Length, int (*Mystrcmp)(const void *PtrToLine, const void *PtrToLine1))
{
    int fromstart  = -1;
    int fromend = Length.NumberOfLines - 1;
    bool b = TRUE;

    while (b)
    {
        b = FALSE;
        fromstart++;
        for (int fromstart1 = fromstart; fromstart1 < fromend; fromstart1++)
        {
            if (Mystrcmp((PtrToLine + fromstart1), (PtrToLine + fromstart1 + 1)) == MORE)
            {
                swap1(&((PtrToLine + fromstart1)->ptrtostr), &((PtrToLine + fromstart1 + 1)->ptrtostr));
                b = TRUE;
            }
        }
        if(!b)
            break;
        fromend--;
        for (int fromend1 = fromend; fromend1 > fromstart; fromend1--)
            if (Mystrcmp((PtrToLine + fromend1), (PtrToLine + fromend1 - 1)) == LESS)
            {
                swap1(&((PtrToLine + fromend1)->ptrtostr), &((PtrToLine + fromend1 - 1)->ptrtostr));
                b = TRUE;
            }
    }

}

char *InputBuffer (char *FileName, Lengths *Length)
{

    struct stat statistic = {};
    stat(FileName, &statistic);

    Length->LengthOfBuffer = statistic.st_size;
    char *Buffer = (char*) calloc(Length->LengthOfBuffer, sizeof(char));

    FILE *fp = fopen (FileName, "r");
    assert(fp != 0);
    assert(fread(Buffer, sizeof(char), statistic.st_size, fp) != 0);
    fclose(fp);

    Length->NumberOfLines++;
    for (int counter = 0; (counter + 1) < Length->LengthOfBuffer; counter++)
    {
        if (Buffer[counter] == '\n')
        {
            Buffer[counter] = '\0';
            Length->NumberOfLines++;
        }
    }
    return Buffer;
}

void InputPtrToBuffer (String *PtrToLine, Lengths *Length, char *Buffer)
{
    int counter  = 0;
    int counter1 = 0;

    while(!isalpha(Buffer[counter]))
            counter++;
    (PtrToLine + counter1)->ptrtostr = Buffer + counter;
    counter++;

    for (; counter < Length->LengthOfBuffer && counter1 < Length->NumberOfLines; counter++)
    {
        if (Buffer[counter - 1] == '\0')
        {
            while(!isalpha(Buffer[counter]))
            {
                counter++;
            }
            (PtrToLine + counter1)->ptrtostr = Buffer + counter;
            (PtrToLine + counter1)->lengthofstr = Mystrlen((PtrToLine + counter1)->ptrtostr);
            counter1++;
        }
    }
    Length->NumberOfLines = counter1;
}

void OutputOrigin(char *Buffer, Lengths Length, char *FileName)
{
    FILE *fp = fopen (FileName, "w");

    for (int counter = 0; counter < Length.LengthOfBuffer; counter++)
    {
        if (Buffer[counter] == '\0')
        {
            Buffer[counter] = '\n';
        }
    }
    fwrite(Buffer, sizeof(char), Length.LengthOfBuffer, fp);

    free(Buffer);
}

void Output(String *PtrToLine, Lengths Length, char *FileName)
{
    FILE *fp = fopen (FileName, "w");

    for (int counter = 0; counter < Length.NumberOfLines; counter++)
    {
        fprintf(fp, "%s\n", PtrToLine[counter].ptrtostr);
    }
}
