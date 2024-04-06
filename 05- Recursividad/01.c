#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int division(int num, int den);

int main()
{
    int resultado;

    resultado = division(15, 5);

    printf("15 dividido 5 es %d", resultado);

    return 0;
}

int division(int num, int den)
{

    if (num < den)
    {
        return 0;
    }
    else
    {
        return 1 + division(num - den, den);
    }
}