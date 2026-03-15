/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 6
*/




#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1500;
    int cont = 0;
    int *x = (int *) calloc(n, sizeof(int));
        if (x == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        if(x[i] == 0) {
            cont++;
    }
}
    printf("\nQuantidade de elementos iguais a zero: %d\n", cont);

    for(int i = 0; i < n; i++) {
        x[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
    if (i < 10 || i >= n - 10) {
        printf("%d ", x[i]);
    }
}

    free(x);
    x = NULL;

    
    return 0;
}


