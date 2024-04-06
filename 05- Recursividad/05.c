#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumatoria_matriz(int matriz[][3], int fila, int fil, int col);

int main()
{
    // int matriz[][2] = {{1, 2}, {3, 4}};

    int matriz[][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int resultado;
    resultado = sumatoria_matriz(matriz, 3, 0, 0);
    printf("La sumatoria de la matriz es: %d", resultado);

    return 0;
}

int sumatoria_matriz(int matriz[][3], int fila, int fil, int col)
{
    if (fil < fila)
    {
        if (col < fila)
        {
            return matriz[fil][col] + sumatoria_matriz(matriz, fila, fil, col + 1);
        }
        sumatoria_matriz(matriz, fila, fil + 1, 0);
    }
    else
    {
        return 0;
    }
}