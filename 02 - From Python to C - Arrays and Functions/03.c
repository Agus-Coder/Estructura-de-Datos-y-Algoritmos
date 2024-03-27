#include <stdio.h>

// Prototypes
int cargar_clientes(long nro_cuenta[50], char nombre[10][50], char surname[10][50], int tipo[50], float saldo[50]);
void ordenar(long nro_cuenta[50], char nombre[10][50], char surname[10][50], int tipo[50], float saldo[50], int cantidad_cuentas);
int minimo_saldo(float saldo[50], int cuentas_totales);

int main()
{
    long cuenta[50];
    char nombre_cliente[10][50];
    char apellido_cliente[10][50];
    int tipo[50];
    float saldo[50];
    int total_cuentas;

    total_cuentas = cargar_clientes(cuenta, nombre_cliente, apellido_cliente, tipo, saldo);

    ordenar(cuenta, nombre_cliente, apellido_cliente, tipo, saldo, total_cuentas);

    int posicion_minimo = minimo_saldo(saldo, total_cuentas);

    printf("La cuenta con menor saldo corresponde a %c %c con un tipo de cuenta %d.\n", nombre_cliente[10][posicion_minimo], apellido_cliente[10][posicion_minimo], tipo[posicion_minimo]);

    return 0;
}

int cargar_clientes(long nro_cuenta[50], char nombre[10][50], char surname[10][50], int tipo[50], float saldo[50])
{
    int cargas;
    int i = 0;
    printf("Ingrese la cantidad de cuentas y clientes a cargar\n");
    scanf("%d", &cargas);
    while (cargas <= 0 || cargas > 50)
    {
        printf("Ingrese la cantidad de cuentas y clientes a cargar\n");
        scanf("%d", &cargas);
    }

    printf("Ingrese numero de cuenta\n");
    scanf("%ld", &nro_cuenta[i]);

    while (nro_cuenta[i] < 0)
    {
        printf("Ingrese numero de cuenta\n");
        scanf("%ld", &nro_cuenta[i]);
    }

    while (nro_cuenta[i] != 0 && i < cargas)
    {
        printf("Ingrese el nombre del cliente\n");
        scanf(" %s", &nombre[10][i]);

        printf("Ingrese el apellido del cliente\n");
        scanf(" %s", &surname[10][i]);

        printf("Ingrese el tipo de cuenta\n");
        scanf("%d", &tipo[i]);
        while (tipo[i] != 1 && tipo[i] != 2)
        {
            printf("Ingrese el tipo de cuenta\n");
            scanf("%d", &tipo[i]);
        }

        printf("Ingrese el saldo de la cuenta\n");
        scanf("%f", &saldo[i]);
        while (saldo[i] > 10000000.00 || saldo[i] < -10000000.00) // Seteo limites de valores maximos de saldo
        {
            printf("Ingrese el saldo de la cuenta\n");
            scanf("%f", &saldo[i]);
        }

        i++;

        if (i < cargas)
        {

            printf("Ingrese numero de cuenta\n");
            scanf("%ld", &nro_cuenta[i]);

            while (nro_cuenta[i] < 0)
            {
                printf("Ingrese numero de cuenta\n");
                scanf("%ld", &nro_cuenta[i]);
            }
        }
    }
    return cargas;
}

void ordenar(long nro_cuenta[50], char nombre[10][50], char surname[10][50], int tipo[50], float saldo[50], int total_cuentas)
{
    int i;
    int j;
    long aux_nro_cuenta;
    char aux_nombre[10];
    char aux_surname[10];
    int aux_tipo;
    float aux_saldo;

    for (i = 0; i < total_cuentas; i++)
    {
        for (j = i + 1; j < total_cuentas; j++)
        {
            if (nro_cuenta[j] < nro_cuenta[i])
            {
                aux_nro_cuenta = nro_cuenta[i];
                nro_cuenta[i] = nro_cuenta[j];
                nro_cuenta[j] = aux_nro_cuenta;

                aux_nombre[10] = nombre[10][i];
                nombre[10][i] = nombre[10][j];
                nombre[10][j] = aux_nombre[10];

                aux_surname[10] = surname[10][i];
                surname[10][i] = surname[10][j];
                surname[10][j] = aux_surname[10];

                aux_tipo = tipo[i];
                tipo[i] = tipo[j];
                tipo[j] = aux_tipo;

                aux_saldo = saldo[i];
                saldo[i] = saldo[j];
                saldo[j] = aux_saldo;
            }
        }
    }
    return;
}

int minimo_saldo(float saldo[50], int cuentas_totales)
{
    int i = 0;
    float minimo = saldo[0];
    int posicion_minimo = 0;
    while (i < cuentas_totales)
    {
        if (minimo > saldo[i])
        {
            posicion_minimo = i;
        }
    }
    return posicion_minimo;
}