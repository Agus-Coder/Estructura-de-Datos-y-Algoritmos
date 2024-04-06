#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ojo, esta guia incluye cadenas de caracteres y caracteres. No olvides las funciones de strcopy y strcmp.

int main()
{
    char c; // es la que lee y describe caracter a caracter
    char c_anterior;
    int contador = 0;
    int letras = 0;
    printf("Ingrese una oracion: ");
    c = getchar();
    putchar(c);

    // while (c == '.' || c == ' ')
    // {
    //     c = getchar();
    // }

    while (c != '.')
    {
        while (c != ' ')
        {
            letras++;
            c_anterior = c;
            c = getchar();
        }
        if (letras >= 2 && c_anterior == 's')
        {
            contador++;
        }
    }

    return 0;
}