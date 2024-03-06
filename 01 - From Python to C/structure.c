#include<stdio.h>

int main(){
    printf("Working on C!");

    // Variables
    int a = 21;
    float b = 3.14;
    double d = 3.141516
    char e[4] = 'char'; //cadena de 4 caracteres
    int vector[5]; //vector de 5 enteros


    // Lectura de datos:
    // Lectura de entero
    printf("Ingrese un numero entero:\n");
    scanf("%d", $a);

    printf("Ingrese un numero flotante:\n");
    // Lectura de float
    scanf("%f", $b);

    printf("Ingrese un numero string:\n");
    // Lectura de string
    scanf("%s", $e);


    // Condicionales
    if (a%b ==0){
        printf("%d", a, " Es multiplo de %d", b);
    }else{
        printf("%d", a, " No es multiplo de %d", b);
    }


    // Estructuras de repeticion
    // While
    while (a>0){
        a--;
        b++;
    }
    printf("El valor final de b es de %d", b);

    // for
    for (int i = 1; i<10; i++){ // notar que se podria inicializar i por fuera del ciclo, depende el scope deseado 
        printf("%d", i);
    }

    return 0;

}