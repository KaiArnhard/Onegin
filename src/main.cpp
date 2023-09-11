#include "../include/Mystring.h"
#include "../include/io.h"
#include "../include/comparefunctions.h"

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
