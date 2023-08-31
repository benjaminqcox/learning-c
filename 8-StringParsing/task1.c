#include <stdio.h>
#include <string.h>

void reversedString(char* string)
{
    // Loop from the end to the start of the string 1 by 1
    // Print each character (single line)
    for (int i = strlen(string); i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    // Print new line (output formatting)
    printf("\n");
}

int main()
{
    // String variable to reverse
    char randomWord[] = "Reverse me";
    // Pass string variable in and see it in reverse
    reversedString(randomWord);
}