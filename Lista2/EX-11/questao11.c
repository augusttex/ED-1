/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 11
*/




#include <stdio.h>
#include <stdlib.h>

int buscarValorNaMatriz(int **matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    
    int linhas, colunas;
    int **matriz = NULL;
    int valorBusca;

    printf("Informe o numero de linhas: ");
    if (scanf("%d", &linhas) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Informe o numero de colunas: ");
    if (scanf("%d", &colunas) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (linhas <= 0 || colunas <= 0) {
        printf("Linhas e colunas devem ser maiores que zero.\n");
        return 1;
    }

    matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria para linhas.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria para colunas.\n");
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("Entrada invalida.\n");
                for (int k = 0; k < linhas; k++) {
                    free(matriz[k]);
                }
                free(matriz);
                return 1;
            }
        }
    }

    printf("\nDigite o valor a buscar: ");
    if (scanf("%d", &valorBusca) != 1) {
        printf("Entrada invalida.\n");
        for (int i = 0; i < linhas; i++) {
            free(matriz[i]);
        }
        free(matriz);
        return 1;
    }

    if (buscarValorNaMatriz(matriz, linhas, colunas, valorBusca) == 1) {
        printf("Resultado: 1 (valor encontrado na matriz)\n");
    } else {
        printf("Resultado: 0 (valor nao encontrado na matriz)\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;

    return 0;
}
