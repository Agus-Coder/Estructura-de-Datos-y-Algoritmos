#include <stdio.h>

int main()
{

    float precio_compra[] = {
        832.10,
        832.63,
        829.69,
        828.21,
        828.21,
        827.83,
        827.83,
        828.10,
        827.10,
        826.11,
        824.55,
        823.68,
        823.70,
        823.36,
        831.18,
        821.85,
        821.64,
        821.66,
        821.49,
        821.49,
        820.21,
        819.22,
        819.20};

    char fecha[23][11] = {"06/03/2024", "05/03/2024", "04/03/2024", "01/03/2024", "29/02/2024",
                    "28/02/2024", "28/02/2024", "28/02/2024", "27/02/2024", "26/02/2024",
                    "23/02/2024", "22/02/2024", "21/02/2024", "20/02/2024", "19/02/2024",
                    "16/02/2024", "16/02/2024", "15/02/2024", "15/02/2024", "14/02/2024",
                    "09/02/2024", "08/02/2024", "08/02/2024"};

    float precio_max = 0;
    int max_index = 0;

    for (int i = 0; i < sizeof(precio_compra); i++)
    {
        if (i == 0 || precio_compra[i] > precio_max)
        {
            precio_max = precio_compra[i];
            max_index = i;
        }
    }
    printf("El precio maximo encontrado es de %.2f y pertenece a la fecha %s \n", precio_max, fecha[max_index]);
    return 0;
}