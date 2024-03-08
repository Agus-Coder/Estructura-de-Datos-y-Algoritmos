#include <stdio.h>

int main()
{
    int number;
    int may_4_men_25 = 0;
    int min = 0;
    int acc = 0;
    int mult_6 = 0;

    printf("Ingrese un numero, ingrese un numero negativo para terminar el programa\n");
    scanf("%d", &number);

    while (number > 0)
    {
        if (number > 4 && number < 25)
        {
            may_4_men_25++;
        }

        if (number % 6 == 0)
        {
            acc += number;
            mult_6 += 1;
        }

        if (min == 0 || number < min)
        {
            min = number;
        }
        printf("Ingrese un numero, ingrese un numero negativo para terminar el programa\n");
        scanf("%d", &number);
    }
    float average = acc / mult_6;

    printf("Inciso a: %d, inciso b: %.2f, inciso c: %d", may_4_men_25, average, min);

    return 0;
}