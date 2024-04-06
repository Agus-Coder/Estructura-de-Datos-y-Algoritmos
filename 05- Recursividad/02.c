#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void al_reves(int num);

int main()
{
    int resultado;

    al_reves(1283567);

    return 0;
}

void al_reves(int num)
{
    int rest;
    int total;
    if (num != 0)
    {
        rest = num % 10;
        total = num / 10;
        printf("%d", rest);
        al_reves(total);
    }

    return;
}