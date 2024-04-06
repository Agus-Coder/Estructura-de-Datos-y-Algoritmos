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

    while (c == '.' || c == ' ')
    {
        c = getchar();
    }

    while (c != '.')
    {
        c_anterior = c;
        letras++;
        c = getchar();

        while (c != ' ' && c != '.')
        {
            putchar(c_anterior);
            c_anterior = c;
            letras++;
            c = getchar();
        }

        if (c == ' ')
        {
            if (letras <= 1)
            {
                c_anterior = ' ';
                putchar(c_anterior);
                putchar(c);
            }else{
                putchar(c_anterior);
                putchar(c);
            }
            c = getchar();
        }
        letras = 0;
    }

    return 0;
}