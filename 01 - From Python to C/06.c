#include <stdio.h>

int main()
{
    int lote;
    int cantidad_pares = 0;
    int item;
    int contador = 0;
    float promedio_lote;
    int acumulador_lote = 0;
    printf("Ingrese un numero positivo para iniciar. Ingrese uno negativo para terminar\n");
    scanf("%d", &lote);

    while (lote > 0)
    {
        contador = 0;
        while (contador < lote)
        {
            printf("Ingrese un numero para este lote\n");
            scanf("%d", &item);
            acumulador_lote += item;
            if (item % 2 == 0)
            {
                cantidad_pares += 1;
            }
            contador += 1;
        }
        promedio_lote = acumulador_lote / lote;

        printf("El promedio de este lote es de: %.2f\n", promedio_lote);

        printf("Ingrese un numero positivo para iniciar. Ingrese uno negativo para terminar\n");
        scanf("%d", &lote);
    }
    return 0;
}