/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 10
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

int quantidadePares(const Fila *fila) {
	int quantidade = 0;
	No *atual = fila->inicio;

	while (atual != NULL) {
		if (atual->valor % 2 == 0) {
			quantidade++;
		}
		atual = atual->prox;
	}

	return quantidade;
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
	Fila fila;

	inicializarFila(&fila);
	enfileirar(&fila, 1);
	enfileirar(&fila, 2);
	enfileirar(&fila, 3);
	enfileirar(&fila, 4);
	enfileirar(&fila, 6);

	imprimirFila(&fila);
	printf("Quantidade de elementos pares: %d\n", quantidadePares(&fila));

	liberarFila(&fila);
	return 0;
}
