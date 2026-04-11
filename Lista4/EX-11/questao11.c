/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 11

para este exercício, escrever 
1 geral
2 geral
3 idoso
4 idoso
5 idoso
6 geral
7 idoso
 (ou algum outro) e então colocar "." e dar enter.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GERAL 0
#define IDOSO 1

typedef struct No {
    int id;
    int tipo;
    int pulos_sofridos;
    struct No *ant;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void processar_chegada(Fila *f, int id, int tipo) {
    No *novo = (No*)malloc(sizeof(No));
    novo->id = id;
    novo->tipo = tipo;
    novo->pulos_sofridos = 0;
    novo->prox = NULL;
    novo->ant = f->fim;

    if (f->fim != NULL) {
        f->fim->prox = novo;
    } else {
        f->inicio = novo;
    }
    f->fim = novo;

    if (tipo == IDOSO) {
        No *atual = f->fim;

        while (atual->ant != NULL && atual->ant->tipo == GERAL && atual->ant->pulos_sofridos < 2) {
            No *anterior = atual->ant;

            int temp_id = anterior->id;
            anterior->id = atual->id;
            atual->id = temp_id;

            int temp_tipo = anterior->tipo;
            anterior->tipo = atual->tipo;
            atual->tipo = temp_tipo;

            int temp_pulos = anterior->pulos_sofridos;
            anterior->pulos_sofridos = atual->pulos_sofridos;
            atual->pulos_sofridos = temp_pulos;

            atual->pulos_sofridos++;

            atual = anterior;
        }
    }
}

void imprimir_e_liberar(Fila *f) {
    No *atual = f->inicio;
    int primeiro = 1;
    
    while (atual != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->id);
        primeiro = 0;
        
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    printf("\n");
}

int main() {
    Fila fila_banco;
    inicializar_fila(&fila_banco);

    int id;
    char categoria[15];

    while (scanf("%d %s", &id, categoria) == 2) {
        int tipo = (strcmp(categoria, "idoso") == 0) ? IDOSO : GERAL;
        processar_chegada(&fila_banco, id, tipo);
    }

    imprimir_e_liberar(&fila_banco);

    return 0;
}