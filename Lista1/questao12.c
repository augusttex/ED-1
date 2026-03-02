/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 12
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main()
{
   int v[5];
        for(int i = 0; i < 5; i++){
            printf("\nDigite o valor da posicao [%d]: ", i + 1);
            scanf("%d", &v[i]);}
        for(int i = 0; i < 5; i++){
            int *x = &v[i];
            if(*x % 2 == 0){
                printf("Endereco da posicao [%d] (par): %p || Valor: %d\n", i + 1, x, *x);
            }
        }
    return 0;


}