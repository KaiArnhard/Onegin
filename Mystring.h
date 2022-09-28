#ifndef STRING_H
#define STRING_H

#include "TXlib.h"
#include <assert.h>

enum Solutions
{
    MORE = 1,
    LESS = 0,
    EQUAL = -1,
};

int Myputs(const char *str);

char *Mystrncpy (char *str, const char *str1, size_t length);
char *Mystrcpy  (char *str, const char *str1);

size_t Mystrlen(const unsigned char *str);
const char* Mystrchr(const char* str, int symbol);

char *Mystrcat  (char *str1, const char *str2);
char *Mystrncat (char *str, const char *str1, size_t sizestr);

char* Myfgets (char *str, int strsize, FILE *fp);
char* Mystrdup (char* str);

int Mystrcmp(const unsigned char *str, const unsigned char *str1, size_t strsize, size_t str1size);
bool compare(const unsigned char str);

void swap1 (unsigned char **str, unsigned char **str1);

#endif
