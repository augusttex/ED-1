/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 8
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

int desenfileirar(Fila *fila, int *valor) {
	No *removido;

	if (filaVazia(fila)) {
		return 0;
	}

	removido = fila->inicio;
	*valor = removido->valor;
	fila->inicio = removido->prox;

	if (fila->inicio == NULL) {
		fila->fim = NULL;
	}

	free(removido);
	return 1;
}

void imprimirFila(const Fila *fila) {
	No *atual = fila->inicio;

	printf("Configuracao final da fila: ");
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
}

void liberarFila(Fila *fila) {
	int valor;

	while (desenfileirar(fila, &valor)) {
	}
}

int main(void) {
	Fila fila;
	int valor;

	inicializarFila(&fila);

	enfileirar(&fila, 10);
	enfileirar(&fila, 20);
	desenfileirar(&fila, &valor);
	enfileirar(&fila, 30);
	enfileirar(&fila, 45);
	enfileirar(&fila, 21);
	desenfileirar(&fila, &valor);
	desenfileirar(&fila, &valor);

	imprimirFila(&fila);
	liberarFila(&fila);
	return 0;
}
