#include <stdio.h>

int main()
{
    printf("Ejercicio 01 - Indice de masa corporal\n");

    float altura, altura_2, peso, indice;

    printf("Ingrese su altura:\t");
    printf("\n");

    scanf("%f", &altura);

    altura_2 = altura * altura;

    printf("Ingrese su peso:\t");
    printf("\n");

    scanf("%f", &peso);

    indice = peso / altura_2;

    printf("Su IMC es de :\t %2.2f", indice);
    printf("\n");

    return 0;
}