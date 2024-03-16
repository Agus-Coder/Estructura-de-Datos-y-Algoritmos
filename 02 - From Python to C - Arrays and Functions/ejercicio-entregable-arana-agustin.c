// Alumno: Arana Agustin
#include <stdio.h>

// Prototypes
int data_input(long dni[50], int age[50], float salary[50]);
int min(float salary[50], int people);
float average_age(int age[50], float salary[50], int people);
float percentage(float salary[50], int people);

// Main function
int main()
{
    int cargados = 0;
    long dni[50];
    int edad[50];
    float salario[50];

    cargados = data_input(dni, edad, salario);

    // Inciso A - DNI del menor salario
    int i_menor_salario = min(salario, cargados);
    float menor_salario = salario[i_menor_salario];
    long dni_menor_salario = dni[i_menor_salario];

    //
    float age_average = average_age(edad, salario, cargados);

    //
    float porcentaje = percentage(salario, cargados);

    printf("El DNI de la persona con el menor salario es %ld, con %.2f de salario.\n", dni_menor_salario, menor_salario);
    printf("El promedio de edad de las personas que cobran mas de 35.000$ son %.1f anios\n", age_average);
    printf("El porcentaje de personas que ganan menos de 30.000$ es de %.2f%%", porcentaje);

    return 0;
}

// Functions development

int data_input(long dni[50], int age[50], float salary[50])
{
    int i = 0;
    printf("Ingrese el numero de documento:\n");
    scanf("%ld", &dni[i]);

    while (dni[i] < 0 || dni[i] > 50000000)
    {
        printf("Ingrese el numero de documento:\n");
        scanf("%ld", &dni[i]);
    }

    while (dni[i] != 0)
    {
        printf("Ingrese la edad de la persona:\n");
        scanf("%d", &age[i]);
        while (age[i] < 18 || age[i] > 120)
        {
            printf("Ingrese la edad de la persona:\n");
            scanf("%d", &age[i]);
        }

        printf("Ingrese el salario de la persona:\n");
        scanf("%f", &salary[i]);
        while (salary[i] <= 0)
        {
            printf("Ingrese el salario de la persona:\n");
            scanf("%f", &salary[i]);
        }

        i++;

        printf("Ingrese el numero de documento:\n");
        scanf("%ld", &dni[i]);
        while (dni[i] < 0 || dni[i] > 50000000)
        {
            printf("Ingrese el numero de documento:\n");
            scanf("%ld", &dni[i]);
        }
    }

    return i;
}

int min(float salary[50], int personas)
{
    int i = 0;
    float minimo;
    int posicion_minimo;

    while (i < personas)
    {
        if (i == 0 || salary[i] < minimo)
        {
            minimo = salary[i];
            posicion_minimo = i;
        }
        i++;
    }
    return posicion_minimo;
}

float average_age(int age[50], float salary[50], int personas)
{
    int i = 0;
    float counter = 0;
    float acc = 0;
    float average;
    while (i < personas)
    {
        if (salary[i] > 35000)
        {
            acc += age[i];
            counter += 1;
        }
        i++;
    }
    average = acc / counter;

    return average;
}

float percentage(float salary[50], int personas)
{
    int i = 0;
    float counter = 0;
    float total = 0;
    float percent;
    while (i < personas)
    {
        if (salary[i] < 30000)
        {
            counter += 1;
        }
        i++;
        total++;
    }
    percent = (counter / total) * 100.0;
    return percent;
}
