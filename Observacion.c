#include <stdio.h>

int main()
{
    int a[3] = {1, 2, 3}, num = 3;
    dupli(a);
    doble(num);
    printf("%d", a[0] + num);
    return 0;
}

void dupli(int arre[])
{
    arre[0] = arre[0] * 2; // ojo, las modificaciones a array no hace falta retornarlas, el array... si, simplemente se modifica
}

void doble(int a)
{
    a = a * 2;
}