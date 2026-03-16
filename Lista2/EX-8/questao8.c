/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 8
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    
    int n;
    double *vetor = NULL;

    printf("Quantos valores deseja armazenar no vetor (minimo 10)? ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n < 10) {
        printf("O tamanho do vetor deve ser maior ou igual a 10.\n");
        return 1;
    }

    vetor = (double *) malloc(n * sizeof(double));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    srand((unsigned int) time(NULL));

    for (int i = 0; i < 10; i++) {
        vetor[i] = rand() % 101; /* valores entre 0 e 100 */
    }

    printf("\nValores nos 10 primeiros elementos:\n");
    for (int i = 0; i < 10; i++) {
        printf("vetor[%d] = %.2f\n", i, vetor[i]);
    }

    free(vetor);
    vetor = NULL;


    return 0;
}
