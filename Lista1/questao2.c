/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 2
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x = 10;
    float y = 20;
    char z = 'A';

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %.2f\n", y);  
    printf("Valor de z: %c\n", z);

    int *a;
    a = &x;
    float *b;
    b = &y;
    char *c;
    c = &z;

    *a = 100;
    *b = 200;
    *c = 'B';


    printf("\nValor de x: %d\n", *a);
    printf("Valor de y: %.2f\n", *b);
    printf("Valor de z: %c\n", *c);

    return 0;





}