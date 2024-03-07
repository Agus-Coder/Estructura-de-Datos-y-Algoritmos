#include <stdio.h>

int main()
{
    int anio;
    int ventas_totales;
    int ventas;
    int venta_max = 0;
    int anio_max;

    printf("Ingrese el anio de venta, ingrese 0 para cancelar: \n");
    scanf("%d", &anio);

    while (anio != 0)
    {
        printf("Ingrese La cantidad de autos vendidos: \n");
        scanf("%d", &ventas);

        if (ventas > venta_max)
        {
            venta_max = ventas;
            anio_max = anio;
        }

        ventas_totales += ventas;

        ventas = 0;

        printf("Ingrese el anio de venta, ingrese 0 para cancelar: \n");
        scanf("%d", &anio);
    }

    printf("La cantidad de ventas totales es %d y el maximo de ventas logrado es de %d en el anio %d", ventas_totales, venta_max, anio_max);

    return 0;
}