#ifndef STRING_H
#define STRING_H

#include "TXlib.h"
#include <ctype.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

struct FileNames
{
    char *FNameOrig = "hamlet.txt";
    char *FNameSort        = "hamletsort.txt";
    char *FNameSortFromEnd = "hamletsortfromend.txt";
    char *FNameOrigOut = "hamletorig.txt";
};

struct String
{
    char *ptrtostr = 0;
    int  lengthofstr = 0;
};
struct Lengths
{
    int NumberOfLines = 0;
    int LengthOfBuffer  = 0;
};

enum Solutions
{
    MORE = 1,
    LESS = -1,
    EQUAL = 0,
};

size_t Mystrlen(const char *str);

int Mystrcmp   (const void *PtrToLine1, const void *PtrToLine2);
int Mystrcmpend(const void *PtrToLine1, const void *PtrToLine2);
int isletter(const unsigned char *str);

void swap1 (char **str, char **str1);

#endif
