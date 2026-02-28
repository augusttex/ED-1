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
    int x;
    int y;


    printf("Digite um numero inteiro para x: ");
    scanf("%d", &x);
    printf("Digite um numero inteiro para y: ");
    scanf("%d", &y);

    int *i;
    int *u;

    i = &x;
    u = &y;

    

    if(i > u)
    {
        printf("O endereco de x é maior que o endereco de y.\n Valor: %d\n", x);
    }
    else if (i < u)
    {
        printf("O endereco de y é maior que o endereco de x.\n Valor: %d\n", y);
    }
}