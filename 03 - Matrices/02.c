#include <stdio.h>

void cargar(int mat[10][10], int filas, int columnas); // ojo, las cargas es para cargar 1, 2, 3, ..., n numeros en la matriz, sin tener que ingresarlos a mano
void mostrar(int mat[10][10], int filas, int columnas);
void mostrar_transpuesta(int mat[10][10], int filas, int columnas);
float sumar_diagonales(int mat[10][10], int fila, int columna);

int main()
{
    int fila;
    int columna;
    int matriz[10][10];
    printf("Ingrese la cantidad de filas:\t");
    scanf(" %d", &fila);
    printf("Ingrese la cantidad de columnas:\t");
    scanf(" %d", &columna);

    cargar(matriz, fila, columna);
    mostrar(matriz, fila, columna);
    // Inciso A
    mostrar_transpuesta(matriz, fila, columna);

    // Inciso B
    int sumatoria_primer_diagonal;
    sumatoria_primer_diagonal = sum_first_diagonal(matriz, fila);
    printf("La sumatora de la diagonal principal es %d\n", sumatoria_primer_diagonal);

    // inciso F
    sumar_diagonal_secundaria(matriz, fila, columna);

    return 0;
}

void cargar(int mat[10][10], int fila, int columna)
{
    int i, j;
    int carga = 1;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            mat[i][j] = carga;
            carga++;
        }
    }

    return;
}

void mostrar(int mat[10][10], int fila, int columna)
{
    int i, j;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            printf(" %d \t", mat[i][j]);
        }
        printf("\n");
    }

    return;
}

void mostrar_transpuesta(int mat[10][10], int fila, int columna)
{
    int i, j;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            printf(" %d \t", mat[j][i]);
        }
        printf("\n");
    }

    return;
}

float sumar_diagonales(int mat[10][10], int fila, int columna)
{
    int i, j;
    float suma_primer_diagonal = 0.0;
    float suma_segunda_diagonal = 0.0;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            if (i + j == fila - 1) // Esta sumatoria tiene que ser igual a N - 1
            {
                suma_segunda_diagonal += mat[i][j];
            }
            if (i == j)
            {
                suma_primer_diagonal += mat[i][j];
            }
        }
    }
    float suma_total = suma_primer_diagonal + suma_segunda_diagonal;
    float total_numeros = i * 2;
    float promedio = suma_total / total_numeros;

    return promedio;
}