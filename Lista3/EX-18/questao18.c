/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 18
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

void removerOcorrenciasX(No **inicio, int x) {
	No *atual;
	No *anterior;
	No *remover;

	if (inicio == NULL) {
		return;
	}

	while (*inicio != NULL && (*inicio)->valor == x) {
		remover = *inicio;
		*inicio = (*inicio)->prox;
		free(remover);
	}

	anterior = NULL;
	atual = *inicio;

	while (atual != NULL) {
		if (atual->valor == x) {
			remover = atual;
			anterior->prox = atual->prox;
			atual = atual->prox;
			free(remover);
		} else {
			anterior = atual;
			atual = atual->prox;
		}
	}
}

No *inserirNoFinal(No *inicio, int valor) {
	No *novo = (No *)malloc(sizeof(No));
	No *atual;

	if (novo == NULL) {
		return inicio;
	}

	novo->valor = valor;
	novo->prox = NULL;

	if (inicio == NULL) {
		return novo;
	}

	atual = inicio;
	while (atual->prox != NULL) {
		atual = atual->prox;
	}
	atual->prox = novo;

	return inicio;
}

void imprimirLista(const No *inicio) {
	const No *atual = inicio;

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
	No *lista = NULL;

	lista = inserirNoFinal(lista, 5);
	lista = inserirNoFinal(lista, 3);
	lista = inserirNoFinal(lista, 5);
	lista = inserirNoFinal(lista, 8);
	lista = inserirNoFinal(lista, 5);
	lista = inserirNoFinal(lista, 1);

	printf("Lista original: ");
	imprimirLista(lista);

	removerOcorrenciasX(&lista, 5);

	printf("Lista sem ocorrencias de 5: ");
	imprimirLista(lista);

	liberarLista(lista);
	return 0;
}

