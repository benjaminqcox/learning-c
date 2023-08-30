#include <stdio.h>


void func1()
{
    printf("Function 1\n");
}

void func2()
{
    printf("Function 2\n");
}

void func3()
{
    printf("Function 3\n");
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return b == 0 ? 0 : a / b;
}

int main()
{
    void (*voidFuncPointers[3])() = {func1, func2, func3};
    for (int i = 0; i < 3; i++)
    {
        voidFuncPointers[i]();
    }

    int a, b, result;
    a = 56;
    b = 12;
    int (*calculatorPointers[])(int, int) = {add, subtract, multiply, divide};
    for (int i = 0; i < sizeof(calculatorPointers)/sizeof(calculatorPointers[0]); i++)
    {
        result = calculatorPointers[i](a, b);
        printf("Result %d = %d\n", i, result);
    }

    return 0;
}