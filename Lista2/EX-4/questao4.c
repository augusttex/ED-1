/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 4
*/




#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int n;
    int X;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("O vetor deve ter tamanho positivo\n");
        return 1;
    }
    
    int *x = (int *) malloc(n * sizeof(int));
    if (x == NULL) { 
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &x[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    
    printf("\nDe um valor para X: ");
    scanf("%d", &X);
    

    printf("Multiplos de X no vetor: ");
    for(int i = 0; i < n; i++)
    {
        if(x[i] % X == 0)
            printf("\n%d", x[i]);
    }

    free(x);
    x = NULL;


    return 0;
}
