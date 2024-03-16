#include <stdio.h>

// 1 - Prototipos
int cargar(int day[50], char city[50], int capacity[50], int sells[50]);
int max(int pasajes[50], int cargas);
float calcular_porcentaje_ventas(int capacidad[50], int ventas[50], char ciudad[50], char inicial, int cargas);
void ordenar(int ventas[50], char ciudad[50], int cargas);
void mostrar_ciudades(char ciudad[50], int ventas[50], int cargas);

// 2 - Funcion Main
int main()
{
    int dia[50];
    char ciudad[50];
    int capacidad[50];
    int venta[50];
    float porcentaje[50];

    int cargas = cargar(dia, ciudad, capacidad, venta);

    // Inciso A
    int i_maximo_ventas = max(venta, cargas);
    char ciudad_max_ventas = ciudad[i_maximo_ventas];
    int dia_max_ventas = dia[i_maximo_ventas];
    int max_ventas = venta[i_maximo_ventas];


    printf("Inciso A - Maximo de ventas por ciudad\n");
    printf("La ciudad y el dia con mayor cantidad de pasajes vendidos es %c con %d pasajes el dia %d\n", ciudad_max_ventas, max_ventas, dia_max_ventas);
    printf("\n");

    // Inciso B
    float porcentaje_ayacucho = calcular_porcentaje_ventas(capacidad, venta, ciudad, 'a', cargas);
    float porcentaje_bsas = calcular_porcentaje_ventas(capacidad, venta, ciudad, 'b', cargas);
    float porcentaje_mardel = calcular_porcentaje_ventas(capacidad, venta, ciudad, 'm', cargas);
    float porcentaje_stafe = calcular_porcentaje_ventas(capacidad, venta, ciudad, 's', cargas);

    printf("Inciso B - Porcentaje de ventas\n");
    printf("La ciudad de Ayacucho vendio el %.2f%% de pasajes\n", porcentaje_ayacucho);
    printf("La ciudad de Bs As vendio el %.2f%% de pasajes\n", porcentaje_bsas);
    printf("La ciudad de Mar del Plata vendio el %.2f%% de pasajes\n", porcentaje_mardel);
    printf("La ciudad de Santa Fe vendio el %.2f%% de pasajes\n", porcentaje_stafe);
    printf("\n");

    // Inciso C
    printf("Inciso C - Orden de ciudades por ventas\n");
    ordenar(venta, ciudad, cargas);
    mostrar_ciudades(ciudad, venta, cargas);

    return 0;
}
// dia va de 1 a 30, hay un vuelo por dia

int cargar(int dia[50], char ciudad[50], int capacidad[50], int ventas[50])
{
    int i = 0;
    printf("Ingrese el dia de vuelo:\n");
    scanf("%d", &dia[i]);

    while (dia[i] <= 0 || dia[i] > 30) // Pensamos los dias 1 a 30 de un mes
    {
        printf("Ingrese el dia de vuelo:\n");
        scanf("%d", &dia[i]);
    }

    while (dia[i] != 0)
    {
        printf("Ingrese el destino:\n");
        scanf(" %c", &ciudad[i]);
        while (ciudad[i] != 'm' && ciudad[i] != 'a' && ciudad[i] != 'b' && ciudad[i] != 's') // m mardel, a ayacucho, b bs as, s santa fe
        {
            printf("Ingrese el destino,  a, b, m o s:\n");
            scanf(" %c", &ciudad[i]);
        }

        printf("Ingrese la capacidad de avion:\n");
        scanf(" %d", &capacidad[i]);
        while (capacidad[i] <= 0 || capacidad[i] >= 150)
        {
            printf("Ingrese la capacidad de avion:\n");
            scanf(" %d", &capacidad[i]);
        }

        printf("Ingrese la cantidad de pasajes vendidos:\n");
        scanf(" %d", &ventas[i]);
        while (ventas[i] > capacidad[i])
        {
            printf("Ingrese la cantidad de pasajes vendidos:\n");
            scanf(" %d", &ventas[i]);
        }

        i++;

        printf("Ingrese el dia de vuelo:\n");
        scanf("%d", &dia[i]);
        while (dia[i] < 0 || dia[i] > 30)
        {
            printf("Ingrese el dia de vuelo:\n");
            scanf("%d", &dia[i]);
        }
    }

    return i;
}

int max(int venta[50], int cargas)
{
    int i = 0;
    float maximo;
    int posicion_maximo;

    while (i < cargas)
    {
        if (i == 0 || venta[i] > maximo)
        {
            maximo = venta[i];
            posicion_maximo = i;
        }
        i++;
    }
    return posicion_maximo;
}

float calcular_porcentaje_ventas(int capacidad[50], int ventas[50], char ciudad[50], char inicial, int cargas)
{
    int i = 0;
    float total_capacidad = 0;
    float total_ventas = 0;
    float porcentaje;
    while (i < cargas)
    {
        if (ciudad[i] == inicial)
        {
            total_capacidad += capacidad[i];
            total_ventas += ventas[i];
        }
        i++;
    }
    porcentaje = total_ventas / total_capacidad * 100.0;
    return porcentaje;
}

void ordenar(int ventas[50], char ciudad[50], int cargas)
{
    int i;
    int j;
    int aux_ventas;
    char aux_ciudad;
    for (i = 0; i < cargas; i++)
    {
        for (j = i + 1; j < cargas; j++)
        {
            if (ventas[j] > ventas[i])
            {

                aux_ventas = ventas[i];
                ventas[i] = ventas[j];
                ventas[j] = aux_ventas;

                aux_ciudad = ciudad[i];
                ciudad[i] = ciudad[j];
                ciudad[j] = aux_ciudad;
            }
        }
    }
    return;
}

void mostrar_ciudades(char ciudad[50], int ventas[50], int cargas)
{
    int i;
    for (i = 0; i < cargas; i++)
    {
        if (ciudad[i] == 'a')
        {
            printf("La ciudad de Ayacucho vendio un total de %d pasajes\n", ventas[i]);
        }
        else if (ciudad[i] == 'b')
        {
            printf("La ciudad de Buenos Aires vendio un total de %d pasajes\n", ventas[i]);
        }
        else if (ciudad[i] == 'm')
        {
            printf("La ciudad de Mar del Plata vendio un total de %d pasajes\n", ventas[i]);
        }
        else if (ciudad[i] == 's')
        {
            printf("La ciudad de Santa Fe vendio un total de %d pasajes\n", ventas[i]);
        }
    }
    return;
}