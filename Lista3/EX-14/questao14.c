/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 14
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

No *criarListaEncadeada(const int vetor[], int tamanho) {
	int i;
	No *inicio = NULL;
	No *fim = NULL;
	No *novo;

	if (vetor == NULL || tamanho <= 0) {
		return NULL;
	}

	for (i = 0; i < tamanho; i++) {
		novo = (No *)malloc(sizeof(No));
		if (novo == NULL) {
			while (inicio != NULL) {
				No *temp = inicio;
				inicio = inicio->prox;
				free(temp);
			}
			return NULL;
		}

		novo->valor = vetor[i];
		novo->prox = NULL;

		if (inicio == NULL) {
			inicio = novo;
			fim = novo;
		} else {
			fim->prox = novo;
			fim = novo;
		}
	}

	return inicio;
}

void imprimirLista(No *inicio) {
	No *atual = inicio;

	printf("[");
	while (atual != NULL) {
		printf("%d", atual->valor);
		if (atual->prox != NULL) {
			printf(", ");
		}
		atual = atual->prox;
	}
	printf("]\n");
}

void liberarLista(No *inicio) {
	No *atual = inicio;

	while (atual != NULL) {
		No *temp = atual;
		atual = atual->prox;
		free(temp);
	}
}

int main(void) {
	int vetor[] = {3, 8, 1, 9, 4};
	int tamanho = (int)(sizeof(vetor) / sizeof(vetor[0]));
	No *lista;

	lista = criarListaEncadeada(vetor, tamanho);

	printf("Lista encadeada criada a partir do vetor: ");
	imprimirLista(lista);

	liberarLista(lista);
	return 0;
}

