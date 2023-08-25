#include <stdio.h>

void printCounterVal()
{
    // This is initialised on compile and not again during runtime
    static unsigned int counter = 0; 
    counter++;
    printf("This function has been called value: %u times\n", counter);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        printCounterVal();
    }
    return 0;
}