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
    int a, b;
    int *x, *y;

    printf("Digite um numero inteiro para a: ");
    scanf("%d", &a);
    printf("Digite um numero inteiro para b: ");
    scanf("%d", &b);

    x = &a;
    y = &b;

    

    printf("Soma de A e B: %d\n", *x + *y);
    printf("Subtracao de A e B: %d\n", *x - *y);
    printf("Multiplicacao de A e B: %d\n", *x * *y);
    printf("Divisao de A e B: %2.f\n", (float)(*x) / (*y));

    return 0; 

}