/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 7
*/




#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *x = NULL;
    int *t;
    int n, qntd = 0;

    while (1) {
        printf("Digite um numero: ");
        if (scanf("%d", &n) != 1) {
            printf("Entrada invalida.\n");
            free(x);
            return 1;
        }

        if (n < 0) {
            break;
        }

        t = realloc(x, (qntd + 1) * sizeof(int));
        if (t == NULL) {
            printf("Erro ao alocar memoria.\n");
            free(x);
            return 1;
        }

        x = t;
        x[qntd] = n;
        qntd++;
    }

    printf("Vetor lido: ");
    for (int i = 0; i < qntd; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);
    x = NULL;

    return 0;
}






