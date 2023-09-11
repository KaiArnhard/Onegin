#include "../include/Mystring.h"
#include "../include/io.h"

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
