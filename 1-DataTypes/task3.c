#include <stdio.h>

unsigned long int strToULInt(char toConv[]) {
    return (unsigned long int)toConv;
}

int main()
{
    char orig[] = "Original text";
    printf("Original: %s\nUnsigned long int version: %lu\n", orig, strToULInt(orig));
    return 0;
}