#include <stdio.h>
#include <string.h>

void reversedString(char* string)
{
    for (int i = strlen(string); i >= 0; i--)
    {
        printf("%c", string[i]);
    }
}

int main()
{
    char randomWord[] = "Reverse me";
    reversedString(randomWord);
}