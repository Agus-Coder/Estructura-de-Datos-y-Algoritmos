#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ojo, esta guia incluye cadenas de caracteres y caracteres. No olvides las funciones de strcopy y strcmp.

int main()
{
    char c; // es la que lee y describe caracter a caracter
    int contador = 0;
    int letras = 0;
    printf("Ingrese una oracion: ");
    c = getchar();
    putchar(c);

    while (c == '.' || c == ' ')
    {
        c = getchar();
    }

    while (c != '.')
    {
        while (c != ' ' && c != '.')
        {
            letras++;
            c = getchar();
        }
        if (letras >= 3)
        {
            contador++;
        }
        letras = 0;
        if(c != '.'){
            c = getchar();
        }
    }

    printf("La cantidad de palabras con mas de 3 letras es: %d\n", contador);

    return 0;
}