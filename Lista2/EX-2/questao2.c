/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 2
*/




#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int tam;
    int par = 0, impar = 0;

    printf("Qual o tamanho do vetor X? ");
    scanf("%d", &tam);

    int *x = (int *) malloc(tam * sizeof(int));
    if (x == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1; }


    for (int i = 0; i < tam; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &x[i]);
    }

    for(int i = 0; i < tam; i++)
    {
        if(x[i] % 2 == 0)  
            par++;
        else
            impar++;  
    }

    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d\n", impar);

    free(x);
    x = NULL;

    

    return 0;
}
