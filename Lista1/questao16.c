/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 16
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    int *b, **c, ***d;

    b = &a;
    c = &b;
    d = &c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Dobro de a: %d\n", 2 * (*b));
    printf("Triplo de a: %d\n", 3 * (**c));
    printf("Quadruplo de a: %d\n", 4 * (***d));

    return 0;
}