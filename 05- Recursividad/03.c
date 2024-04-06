#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int suma_digitos(int num);

int main()
{
    int resultado;

    resultado = suma_digitos(1234567);

    printf("La suma de digitos es: %d", resultado);

    return 0;
}

int suma_digitos(int num)
{
    int rest;
    int total;
    if (num != 0)
    {
        rest = num % 10;
        total = num / 10;
        return rest + suma_digitos(total);
    }
    else
    {
        return 0;
    }
}