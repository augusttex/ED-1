/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 5
*/




#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int loteria[6] = {1, 3, 5, 7, 9, 11};
    int bilhete[6];
    int acertos = 0;
    int *corretos; 
    int k = 0;

    
    for(int i = 0; i < 6; i++) {
        printf("Digite o numero %d do seu bilhete: ", i + 1);
        scanf("%d", &bilhete[i]);
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(bilhete[i] == loteria[j]) {
                acertos++;
                
                
            }
        }
    }
    corretos = (int *) malloc(acertos * sizeof(int));
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(bilhete[i] == loteria[j]) {
                corretos[k++] = bilhete[i];
            }
        }
    }
    printf("\nNumeros corretos: ");
    for (int i = 0; i < acertos; i++) {
    printf("%d ", corretos[i]);
    }
    printf("\nNumeros sorteados: ");
    for (int i = 0; i < 6; i++) {
    printf("%d ", loteria[i]);
    }

    free(corretos);
    corretos = NULL;



    return 0;
}
