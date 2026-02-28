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
    int a, b, c;
    int *x, *y, *z;
    int t;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &a, &b, &c);  


    x = &a;
    y = &b;
    z = &c; 

    
    if (*x > *y) { t = *x; *x = *y; *y = t; }
    if (*y > *z) { t = *y; *y = *z; *z = t; }
    if (*x > *y) { t = *x; *x = *y; *y = t; }

    printf("Valores ordenados: %d %d %d\n", *x, *y, *z);
    printf("Enderecos: %p %p %p\n", x, y, z);

    return 0;
}