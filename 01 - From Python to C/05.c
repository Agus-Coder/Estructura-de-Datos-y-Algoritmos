#include <stdio.h>

int main()
{

    int edad;
    float sueldo;
    int acc_edad = 0;
    int tot_mayor_100 = 0;
    float menor;
    float entre;
    float mayor;

    printf("Ingrese la edad del empleado: \n");
    scanf("%d", &edad);

    printf("Ingrese el sueldo del empleado: \n");
    scanf("%f", &sueldo);

    while (!(edad == 0 && sueldo == 0))
    {

        if (sueldo > 10000){
            acc_edad += edad;
            tot_mayor_100 += 1;
        }

        printf("Ingrese la edad del empleado: \n");
        scanf("%d", &edad);

        printf("Ingrese el sueldo del empleado: \n");
        scanf("%f", &sueldo);
    }

    return 0;
}