/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 3
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alocarString(int tamanho) {
    char *s = malloc((tamanho + 1) * sizeof(char));
    return s;
}

int main() {
    
    int tam;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);

    getchar();
    char *str = alocarString(tam);
        if(str == NULL)
        {
        printf("Erro ao alocar memoria.\n");
        return 1;
        }

    printf("Digite a string: ");
    fgets(str, tam + 1, stdin);
    str[strcspn(str, "\n")] = '\0';

    for(int i = 0; str[i] != '\0'; i++) {
        if(strchr("aeiouAEIOU", str[i]) == NULL) {
            printf("%c ", str[i]);
        }
    }
    



    return 0;
}
