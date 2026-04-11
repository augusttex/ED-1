/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 6
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

void preencherFilaOrdenada(Fila *fila, const int valores[], int quantidade) {
	int i;

	for (i = 0; i < quantidade; i++) {
		enfileirar(fila, valores[i]);
	}
}

void preencherTerceiraFila(const Fila *f1, const Fila *f2, Fila *f3) {
	No *p1 = f1->inicio;
	No *p2 = f2->inicio;

	while (p1 != NULL && p2 != NULL) {
		if (p1->valor <= p2->valor) {
			enfileirar(f3, p1->valor);
			p1 = p1->prox;
		} else {
			enfileirar(f3, p2->valor);
			p2 = p2->prox;
		}
	}

	while (p1 != NULL) {
		enfileirar(f3, p1->valor);
		p1 = p1->prox;
	}

	while (p2 != NULL) {
		enfileirar(f3, p2->valor);
		p2 = p2->prox;
	}
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
	Fila f3;
	int valores1[] = {1, 4, 7, 10};
	int valores2[] = {2, 3, 8, 12};

	inicializarFila(&f1);
	inicializarFila(&f2);
	inicializarFila(&f3);

	preencherFilaOrdenada(&f1, valores1, 4);
	preencherFilaOrdenada(&f2, valores2, 4);
	preencherTerceiraFila(&f1, &f2, &f3);

	printf("Fila 1:\n");
	imprimirFila(&f1);
	printf("Fila 2:\n");
	imprimirFila(&f2);
	printf("Fila 3 (resultado):\n");
	imprimirFila(&f3);

	liberarFila(&f1);
	liberarFila(&f2);
	liberarFila(&f3);
	return 0;
}
