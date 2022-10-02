#ifndef COMPAREFUNCTIONS_H
#define COMPAREFUNCTIONS_H

int Mystrcmp   (const void *PtrToLine1, const void *PtrToLine2);
int Mystrcmpend(const void *PtrToLine1, const void *PtrToLine2);

void Mysort(void *PtrToLine, Lengths Length, int (*Mystrcmp)(const void *PtrToLine1, const void *PtrToLine2));
void swap1 (String *PtrToLine1, String *PtrToLine2);

#endif
