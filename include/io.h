#ifndef IO_H
#define IO_H

#include "Mystring.h"

char   *InputBuffer(char *FileName, Lengths *Length);
void InputPtrToBuffer(String *PtrToLine, Lengths *Length, char *Buffer);

void Output(String *PtrToLine, Lengths Length, char *FileName);
void OutputOrigin(char *Buffer, Lengths Length, char *FileName);

#endif
