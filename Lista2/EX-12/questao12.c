/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 12
*/




#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int linhas, colunas;
    double **matriz = NULL;

    printf("Digite o numero de linhas: ");
    if (scanf("%d", &linhas) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Digite o numero de colunas: ");
    if (scanf("%d", &colunas) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (linhas <= 0 || colunas <= 0) {
        printf("Linhas e colunas devem ser maiores que zero.\n");
        return 1;
    }

    matriz = (double **) malloc(linhas * sizeof(double *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria para as linhas.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (double *) malloc(colunas * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria para as colunas.\n");
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }

    printf("\nDigite os valores da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            if (scanf("%lf", &matriz[i][j]) != 1) {
                printf("Entrada invalida.\n");
                for (int k = 0; k < linhas; k++) {
                    free(matriz[k]);
                }
                free(matriz);
                return 1;
            }
        }
    }

    printf("\nMatriz informada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%8.2lf ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
    
    return 0;
}
