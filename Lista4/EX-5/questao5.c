/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 4
Exercício: 5
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

void excluirNegativos(Fila *fila) {
	No *atual = fila->inicio;
	No *anterior = NULL;
	No *removido;

	while (atual != NULL) {
		if (atual->valor < 0) {
			removido = atual;

			if (anterior == NULL) {
				fila->inicio = atual->prox;
			} else {
				anterior->prox = atual->prox;
			}

			if (atual == fila->fim) {
				fila->fim = anterior;
			}

			atual = atual->prox;
			free(removido);
		} else {
			anterior = atual;
			atual = atual->prox;
		}
	}

	if (fila->inicio == NULL) {
		fila->fim = NULL;
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
	Fila fila;
	int quantidade;
	int valor;
	int i;

	inicializarFila(&fila);

	printf("Digite a quantidade de elementos: ");
	scanf("%d", &quantidade);

	for (i = 0; i < quantidade; i++) {
		printf("Digite o valor %d: ", i + 1);
		scanf("%d", &valor);
		enfileirar(&fila, valor);
	}

	printf("Antes de excluir os negativos:\n");
	imprimirFila(&fila);

	excluirNegativos(&fila);

	printf("Depois de excluir os negativos:\n");
	imprimirFila(&fila);

	liberarFila(&fila);
	return 0;
}
