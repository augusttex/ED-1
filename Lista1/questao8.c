/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 8
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v[6];

    for(int i = 0; i < 6; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < 6; i++) {
        int *x = &v[i];
        printf("Valor: %d || Endereco: %p\n", * x, &v[i]);
    }
}