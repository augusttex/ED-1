/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

typedef struct {
	No *inicio;
	No *fim;
} Fila;

void inicializarFila(Fila *fila) {
	fila->inicio = NULL;
	fila->fim = NULL;
}

int filaVazia(const Fila *fila) {
	return fila->inicio == NULL;
}

int enfileirar(Fila *fila, int valor) {
	No *novo = (No *)malloc(sizeof(No));

	if (novo == NULL) {
		return 0;
	}

	novo->valor = valor;
	novo->prox = NULL;

	if (filaVazia(fila)) {
		fila->inicio = novo;
		fila->fim = novo;
	} else {
		fila->fim->prox = novo;
		fila->fim = novo;
	}

	return 1;
}

int tamanhoFila(const Fila *fila) {
	int tamanho = 0;
	No *atual = fila->inicio;

	while (atual != NULL) {
		tamanho++;
		atual = atual->prox;
	}

	return tamanho;
}

int F1MaisElem(const Fila *f1, const Fila *f2) {
	return tamanhoFila(f1) > tamanhoFila(f2);
}

void liberarFila(Fila *fila) {
	No *atual = fila->inicio;
	No *proximo;

	while (atual != NULL) {
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}

	fila->inicio = NULL;
	fila->fim = NULL;
}

int main(void) {
	Fila f1;
	Fila f2;

	inicializarFila(&f1);
	inicializarFila(&f2);

	enfileirar(&f1, 10);
	enfileirar(&f1, 20);
	enfileirar(&f1, 30);

	enfileirar(&f2, 40);
	enfileirar(&f2, 50);

	if (F1MaisElem(&f1, &f2)) {
		printf("F1 tem mais elementos do que F2.\n");
	} else {
		printf("F1 nao tem mais elementos do que F2.\n");
	}

	liberarFila(&f1);
	liberarFila(&f2);
	return 0;
}
