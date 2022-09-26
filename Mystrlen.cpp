#include "Mystring.h"

size_t Mystrlen(const unsigned char *str)
{
    size_t counter = 0;

    for (; str[counter] != '\0'; counter++)
    { }

    return counter;
 }


