/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 15
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10];
    int *p = a;
    int min, max;
    int *pmin = &min;
    int *pmax = &max;


    for(int i = 0; i < 10; i++)
    {
        printf("Digite o valor do elemento [%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    min = max = a[0];
     for(int i = 1; i < 10; i++)
     {
        p++;
        if(*p < *pmin) 
            *pmin = *p;
        if(*p > *pmax)
            *pmax = *p;
     }
    printf("O menor valor: %d\n", *pmin);
    printf("O maior valor: %d\n", *pmax);

    return 0;

}