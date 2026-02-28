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
    int y = 20;

    int *i;
    int *u;
    i = &x;
    u = &y;

    printf("Endereço de x: %p\n", i);
    printf("Endereço de y: %p\n\n", u);

    if(i > u)
    {
        printf("O endereço de x é maior que o endereço de y.\n Endereço: %p\n", i);
    }
    else if (i < u)
    {
        printf("O endereço de y é maior que o endereço de x.\n Endereço: %p\n", u);
    }
    


}