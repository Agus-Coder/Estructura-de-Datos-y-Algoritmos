#include <stdio.h>

int main()
{
    int a = 0, b = 0;

    scanf("%d", &a);

    scanf("%d", &b);

    printf("%d", (a && !a) || (b && !b));

    return 0;
}

// Si el primer if da verdadero, se imprimirá:

// if( ! ( (a%3==0) || (a<=9) ) )

// !( (a%3==0) || (a<=9) ) siempre verdadero

//  (a%3==0) || (a<=9)  falso, ambos son falsos, siempre

// a%3==0 falso siempre
// a<=9 falso siempre

// {
//    if( (a%3) && (a>9))

//       printf("CUMPLE");

//    else

//       printf(" NO CUMPLE");

// }