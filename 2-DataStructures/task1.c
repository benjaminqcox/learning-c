#include <stdio.h>

int main()
{
    char cArr[15] = {'I', ' ', 'a', 'm', ' ', 'a' ,' ', 's', 't', 'r', 'i', 'n', 'g', '!', '\0'};
    printf("length: %lu\n", sizeof(cArr));
    printf("Char array printed as a string: %s\n", cArr);
}