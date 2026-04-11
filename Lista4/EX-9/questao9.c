/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 9
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

int removerInicio(Fila *fila) {
	No *removido;
	int valor;

	if (filaVazia(fila)) {
		return -1;
	}

	removido = fila->inicio;
	valor = removido->valor;
	fila->inicio = removido->prox;

	if (fila->inicio == NULL) {
		fila->fim = NULL;
	}

	free(removido);
	return valor;
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
	while (!filaVazia(fila)) {
		removerInicio(fila);
	}
}

int main(void) {
	Fila fila;
	int valorRemovido;

	inicializarFila(&fila);
	enfileirar(&fila, 10);
	enfileirar(&fila, 20);
	enfileirar(&fila, 30);

	printf("Antes:\n");
	imprimirFila(&fila);

	valorRemovido = removerInicio(&fila);
	printf("Valor removido do inicio: %d\n", valorRemovido);

	printf("Depois:\n");
	imprimirFila(&fila);

	liberarFila(&fila);
	return 0;
}
