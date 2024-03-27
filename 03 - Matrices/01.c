#include <stdio.h>

void cargar(int mat[10][10], int filas, int columnas); // ojo, las cargas es para cargar 1, 2, 3, ..., n numeros en la matriz, sin tener que ingresarlos a mano
void mostrar(int mat[10][10], int filas, int columnas);
int sum_2nd_row(int mat[10][10], int columnas);
int may_2nd_col(int mat[10][10], int filas);
float average_of_multiplies_five(int mat[10][10], int fila, int columna);
int sum_first_diagonal(int mat[10][10], int fila);
void minimum_per_row(int mat[10][10], int fila, int columnas);
void mostrar_raiz_secundaria(int mat[10][10], int fila, int columna);
void debajo_de_raiz_primaria(int mat[10][10], int fila, int columnas);
int matriz_transpuesta(int mat[10][10], int fila);

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
    int sumatoria;
    sumatoria = sum_2nd_row(matriz, columna);
    printf("La sumatoria de la segunda fila es: %d\n", sumatoria);

    // Inciso B
    int maximo;
    maximo = may_2nd_col(matriz, fila);
    printf("El maximo de la segunda columna es: %d\n", maximo);

    // Inciso C
    float average_5;
    average_5 = average_of_multiplies_five(matriz, fila, columna);
    printf("El promedio de los multiplos de 5 es: %.1f\n", average_5);

    // Inciso D
    int sumatoria_diagonal;
    sumatoria_diagonal = sum_first_diagonal(matriz, fila);
    printf("La sumatora de la diagonal principal es %d\n", sumatoria_diagonal);

    // Inciso E
    minimum_per_row(matriz, fila, columna);

    // inciso F
    mostrar_raiz_secundaria(matriz, fila, columna);

    // Inciso G
    debajo_de_raiz_primaria(matriz, fila, columna);

    // Inciso H
    matriz_transpuesta(matriz, fila);
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

int sum_2nd_row(int mat[10][10], int columnas)
{
    int j;
    int acumulador = 0;

    for (j = 0; j < columnas; j++)
    {
        acumulador += mat[1][j];
    }

    return acumulador;
}

int may_2nd_col(int mat[][10], int filas)
{

    int i = 0;
    int maximo = mat[1][0];
    while (i < filas)
    {
        if (maximo < mat[i][1])
        {
            maximo = mat[i][1];
        }
        i++;
    }
    return maximo;
}

float average_of_multiplies_five(int mat[10][10], int fila, int columna)
{
    int i, j;
    float total = 0.0;
    float suma = 0.0;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            if (mat[i][j] % 5 == 0)
            {
                suma += mat[i][j];
                total += 1;
            }
        }
    }
    float promedio;
    // promedio = total / suma; CUIDADO! PONELE UN NOMBRE ADECUADO A LAS COSAS!!!
    promedio = suma / total;

    return promedio;
}

int sum_first_diagonal(int mat[10][10], int fila)
{

    int i;
    int acumulador = 0;
    for (i = 0; i < fila; i++)
    {
        acumulador += mat[i][i];
    }
    return acumulador;
}

void minimum_per_row(int mat[10][10], int fila, int columnas)
{
    int i = 0;
    int j;
    int minimo = 0;
    while (i < fila)
    {
        minimo = mat[i][0];
        for (j = 0; j < columnas; j++)
        {
            if (minimo > mat[i][j])
            {
                minimo = mat[i][j];
            }
        }
        printf("El elemento minimo de la %d fila es: %d\n", i + 1, minimo);
        i++;
    }
}

void mostrar_raiz_secundaria(int mat[10][10], int fila, int columna)
{
    int i, j;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            if (i + j == fila - 1) // Esta sumatoria tiene que ser igual a N - 1
            {
                printf(" %d \t", mat[i][j]);
            }
            else
            {
                printf("  \t");
            }
        }
        printf("\n");
    }

    return;
}

void debajo_de_raiz_primaria(int mat[10][10], int fila, int columnas)
{
    int i, j;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j <= i)
            {
                printf(" %d \t", mat[i][j]);
            }
            else
            {
                printf("  \t");
            }
        }
        printf("\n");
    }

    return;
}

int matriz_transpuesta(int mat[10][10], int fila)
{
    int i, j;
    for (i = 0; i < fila; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (mat[i][j] == mat[j][i])
            {
                printf("Los elementos mat[i][j]: %d y mat[j][i]: %d son iguales", mat[i][j], mat[j][i]);
            }
        }
    }
    return 1;
}