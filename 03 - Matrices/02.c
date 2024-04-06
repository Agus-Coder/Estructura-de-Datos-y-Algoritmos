#include <stdio.h>

void cargar(int mat[10][10], int filas, int columnas); // ojo, las cargas es para cargar 1, 2, 3, ..., n numeros en la matriz, sin tener que ingresarlos a mano
void mostrar(int mat[10][10], int filas, int columnas);
void mostrar_transpuesta(int mat[10][10], int filas, int columnas);
float promedio_diagonales(int mat[10][10], int fila, int columna);
void cargar_transpuesta(int mat[10][10], int filas, int columnas);
void multiplicacion_matrices(int mat1[10][10], int mat2[10][10], int fila, int columna, int mat3[10][10]);
int contar_primos(int mat1[10][10], int filas, int columnas);

int main()
{
    int fila;
    int columna;
    int matriz[10][10];
    int matriz2[10][10];
    int matriz3[10][10];
    int primos = 0;
    printf("Ingrese la cantidad de filas:\t");
    scanf(" %d", &fila);
    printf("Ingrese la cantidad de columnas:\t");
    scanf(" %d", &columna);

    cargar(matriz, fila, columna);
    mostrar(matriz, fila, columna);

    printf("\n");

    // Inciso A
    mostrar_transpuesta(matriz, fila, columna);
    printf("\n");

    // Inciso B
    float promedio_diag = 0.0;
    promedio_diag = promedio_diagonales(matriz, fila, columna);
    printf("El promedio de las diagonales es %f\n", promedio_diag);
    printf("\n");

    // Inciso C
    cargar_transpuesta(matriz2, fila, columna);
    multiplicacion_matrices(matriz, matriz2, fila, columna, matriz3);
    mostrar(matriz3, fila, columna);
    printf("\n");

    // Inciso D
    primos = contar_primos(matriz, fila, columna);
    printf("la matriz 1 posee %d numeros primos \n", primos);
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

float promedio_diagonales(int mat[10][10], int fila, int columna)
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
    float total_numeros = fila * 2;

    float promedio = suma_total / total_numeros;
    return promedio;
}

void cargar_transpuesta(int mat[10][10], int filas, int columnas)
{
    int i, j;
    int carga = 1;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            mat[j][i] = carga;
            carga++;
        }
    }

    return;
}

void multiplicacion_matrices(int mat1[10][10], int mat2[10][10], int fila, int columna, int mat3[10][10])
{
    int i, j, k;
    for (i = 0; i < fila; i++) // Este segundo for es el que va a cambiar de fila en cada interaccion
    {
        mat3[i][j] = 0;
        for (j = 0; j < fila; j++) // Este segundo for es el que va a cambiar de columna en cada interaccion
        {
            mat3[i][j] = 0;
            for (k = 0; k < fila; k++) // Este primer for es el que va a cargar lugar a lugar, el resultado de cada multiplicacion            {
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return;
}

int contar_primos(int mat[10][10], int filas, int columnas)
{
    int i = 0;
    int j = 0;
    int k;
    int contador = 0;
    int divisiones;
    while (i < filas)
    {
        while (j < columnas)
        {
            if (mat[i][j] == 0 || mat[i][j] == 1)
            {
                contador++;
            }
            else
            {
                divisiones = 0;
                for (k = 1; k <= mat[i][j]; k++)
                {
                    if (mat[i][j] % k == 0)
                    {
                        divisiones++;
                    }
                }
                if (divisiones <= 2 )
                {
                    contador++;
                }
            }
            j++;
        }
        j=0;
        i++;
    }
    return contador;
}