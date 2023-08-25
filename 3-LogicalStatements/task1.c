#include <stdio.h>

int main()
{
    int A = 0, B = 0;
    
    for (int i = 0; i < 20; i++)
    {
        A += 3;
        B += 7;
        if (i % 5 == 0)
        {
            printf("i: %d: A: %d, B: %d\n", i, A, B);
        }
        if (A % 2 == 1)
        {
            printf("i: %d: A is odd: %d\n", i, A);
        }
        if (B % 2 == 0)
        {
            printf("i: %d: B is even: %d\n", i, B);
        }
    }
    return 0;
}