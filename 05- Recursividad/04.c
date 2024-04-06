#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int productoria_digitos(int num[], int elementos, int posicion);

int main()
{
    int elementos = 5;
    int resultado;
    // printf("ingrese la cantidad de elementos del array\n");
    // scanf("%d", &elementos);
    int array[] = {10, 2, 3, 5, 5};

    resultado = productoria_digitos(array, elementos, 0);

    printf("La productoria de digitos es: %d", resultado);

    return 0;
}

int productoria_digitos(int num[50], int elementos, int posicion)
{
    if (posicion < elementos)
    {
        return num[posicion] * productoria_digitos(num, elementos, posicion + 1);
    }
    else
    {
        return 1;
    }
}