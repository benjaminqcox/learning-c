#include <stdio.h>

void sum(int a, int b, int c)
{
    printf("Sum of a, b, c = %d\n", a + b + c);
}

int main()
{
    sum(2, 3, 99);
    return 0;
}