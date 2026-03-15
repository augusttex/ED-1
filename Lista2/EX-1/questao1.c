/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 1
*/




#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *x = NULL;
    int i;

    x = (int *) malloc(5* sizeof(int));
    if (x == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &x[i]);
    }

    for(i = 0; i < 5; i++) {
        printf("Numero %d: %d\n", i + 1, x[i]);
    }

    free(x);
    x = NULL;




    return 0;
}
