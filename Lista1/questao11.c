/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 11
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    float v[5];
        for(int i = 0; i < 5; i++){
            printf("\nDigite o valor da posicao [%d]: ", i + 1);
            scanf("%f", &v[i]);
        }
        for(int i = 0; i < 5; i++){
            float *x = &v[i];
            *x *= 2;
            printf("Valor da posicao [%d] (dobro): %.2f\n", i + 1, *x);
        }

        return 0;

}