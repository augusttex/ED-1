/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 7
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

void concatenarFilas(Fila *f1, Fila *f2) {
	if (filaVazia(f2)) {
		return;
	}

	if (filaVazia(f1)) {
		f1->inicio = f2->inicio;
		f1->fim = f2->fim;
	} else {
		f1->fim->prox = f2->inicio;
		f1->fim = f2->fim;
	}

	f2->inicio = NULL;
	f2->fim = NULL;
}

void imprimirFila(const Fila *fila) {
	No *atual = fila->inicio;

	printf("Fila: ");
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
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

	enfileirar(&f1, 1);
	enfileirar(&f1, 2);
	enfileirar(&f1, 3);

	enfileirar(&f2, 4);
	enfileirar(&f2, 5);
	enfileirar(&f2, 6);

	printf("F1 antes:\n");
	imprimirFila(&f1);
	printf("F2 antes:\n");
	imprimirFila(&f2);

	concatenarFilas(&f1, &f2);

	printf("F1 depois da concatenacao:\n");
	imprimirFila(&f1);
	printf("F2 depois da concatenacao:\n");
	imprimirFila(&f2);

	liberarFila(&f1);
	liberarFila(&f2);
	return 0;
}
