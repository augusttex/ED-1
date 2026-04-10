/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 3

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

int desenfileirar(Fila *fila, int *valorRemovido) {
	No *removido;

	if (filaVazia(fila)) {
		return 0;
	}

	removido = fila->inicio;
	*valorRemovido = removido->valor;
	fila->inicio = removido->prox;

	if (fila->inicio == NULL) {
		fila->fim = NULL;
	}

	free(removido);
	return 1;
}

void reverso(Fila *fila) {
	No *anterior = NULL;
	No *atual = fila->inicio;
	No *proximo;

	if (filaVazia(fila) || fila->inicio == fila->fim) {
		return;
	}

	fila->fim = fila->inicio;

	while (atual != NULL) {
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = proximo;
	}

	fila->inicio = anterior;
}

void imprimirFila(const Fila *fila) {
	No *aux = fila->inicio;

	printf("Fila: ");
	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
	printf("\n");
}

void liberarFila(Fila *fila) {
	int valorRemovido;
	while (desenfileirar(fila, &valorRemovido)) {
	}
}

int main(void) {
	Fila fila;

	inicializarFila(&fila);

	enfileirar(&fila, 10);
	enfileirar(&fila, 20);
	enfileirar(&fila, 30);
	enfileirar(&fila, 40);

	printf("Antes do reverso:\n");
	imprimirFila(&fila);

	reverso(&fila);

	printf("Depois do reverso:\n");
	imprimirFila(&fila);

	liberarFila(&fila);
	return 0;
}
