#include <stdio.h>

void cargar(int number[10]);
void ordenar(int number[10]);
void mostrar_4_mayores(int number[10]);
void intercalar(int number[10], int intercalado[10]);
void mostrar_array(int arreglo[10]);

int main()
{
    int number[10];
    int intercalado[10];

    cargar(number);
    printf("Arreglo Inicial:\n");
    mostrar_array(number);

    ordenar(number);
    printf("Arreglo ordenado:\n");
    mostrar_array(number);

    printf("Los 4 mayores numeros cargados son:\n");
    mostrar_4_mayores(number);

    intercalar(number, intercalado);
    printf("Array intercalado:\n");
    mostrar_array(intercalado);

    return 0;
}

void cargar(int number[10])
{
    int i;
    int j;

    for (i = 0; i < 5; i++)
    {
        printf("Ingrese 5 numeros positivos\n");
        scanf("%d", &j);
        while (j <= 0)
        {
            printf("Ingrese 5 numeros positivos\n");
            scanf("%d", &j);
        }
        number[i] = j;
    }

    for (i = 5; i < 10; i++)
    {
        printf("Ingrese 5 numeros negativos\n");
        scanf("%d", &j);
        while (j >= 0)
        {
            printf("Ingrese 5 numeros negativos\n");
            scanf("%d", &j);
        }
        number[i] = j;
    }
    return;
}

void ordenar(int number[10])
{
    int i;
    int j;
    int aux_number;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (number[j] > number[i])
            {
                aux_number = number[i];
                number[i] = number[j];
                number[j] = aux_number;
            }
        }
    }
    return;
}

void mostrar_4_mayores(int number[10])
{
    int i = 0;
    for (i; i < 4; i++)
    {
        printf("%d, ", number[i]);
    }
    return;
}

void intercalar(int number[10], int intercalado[10])
{
    int i = 0;
    int j = 0;
    for (i; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            intercalado[i] = number[j];
        }
        else
        {
            intercalado[i] = number[j + 5];
            j++;
        }
    }
    return;
}

void mostrar_array(int arreglo[10])
{
    int i = 0;
    for (i; i < 10; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    return;
}