/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 9
*/




#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char sobrenome[100];
    int anoNascimento;
} Aluno;

int main() {
    int n;
    Aluno *alunos = NULL;

    printf("Informe a quantidade de alunos: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n <= 0) {
        printf("A quantidade deve ser maior que zero.\n");
        return 1;
    }

    alunos = (Aluno *) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Matricula: ");
        if (scanf("%d", &alunos[i].matricula) != 1) {
            printf("Entrada invalida para matricula.\n");
            free(alunos);
            return 1;
        }

        printf("Sobrenome: ");
        if (scanf("%99s", alunos[i].sobrenome) != 1) {
            printf("Entrada invalida para sobrenome.\n");
            free(alunos);
            return 1;
        }

        printf("Ano de nascimento: ");
        if (scanf("%d", &alunos[i].anoNascimento) != 1) {
            printf("Entrada invalida para ano de nascimento.\n");
            free(alunos);
            return 1;
        }
    }

    printf("\n=== Dados dos alunos cadastrados ===\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Sobrenome: %s\n", alunos[i].sobrenome);
        printf("Ano de nascimento: %d\n\n", alunos[i].anoNascimento);
    }

    free(alunos);
    alunos = NULL;

    return 0;
}
