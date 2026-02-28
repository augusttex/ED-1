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

    *x *= 2;
    *y *= 2;

    printf("Valor de a (dobro): %d\n", a);
    printf("Valor de b (dobro): %d\n", b);
    printf("Valor da soma: %d\n", *x + *y);

    return 0;

}