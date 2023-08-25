#include <stdio.h>

void printPhrase(char p[])
{
    printf("%s\n", p);
}

int main()
{
    char phrase[] = "This is the phrase I would like to print!";
    printPhrase(phrase);
    return 0;
}