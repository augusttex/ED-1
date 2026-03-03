/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 14
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[5];
    int b;
    int *x = a;


    printf("\nDigite o valor de b: ");
    scanf("%d", &b);

    for(int i = 0; i < 5; i++)
    {
         
        *x = b;
        printf("Valor do elemento [%d]: %d\n", i + 1, *x);
        x++;
    }

    return 0;
}