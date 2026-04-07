/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 16
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

static int inserirNoFinal(No **inicio, No **fim, int valor) {
	No *novo = (No *)malloc(sizeof(No));

	if (novo == NULL) {
		return 0;
	}

	novo->valor = valor;
	novo->prox = NULL;

	if (*inicio == NULL) {
		*inicio = novo;
		*fim = novo;
	} else {
		(*fim)->prox = novo;
		*fim = novo;
	}

	return 1;
}

static void liberarLista(No *inicio) {
	No *atual = inicio;

	while (atual != NULL) {
		No *temp = atual;
		atual = atual->prox;
		free(temp);
	}
}

No *concatenarListas(const No *l1, const No *l2) {
	const No *atual;
	No *resultado = NULL;
	No *fim = NULL;

	atual = l1;
	while (atual != NULL) {
		if (!inserirNoFinal(&resultado, &fim, atual->valor)) {
			liberarLista(resultado);
			return NULL;
		}
		atual = atual->prox;
	}

	atual = l2;
	while (atual != NULL) {
		if (!inserirNoFinal(&resultado, &fim, atual->valor)) {
			liberarLista(resultado);
			return NULL;
		}
		atual = atual->prox;
	}

	return resultado;
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

int main(void) {
	No a3 = {3, NULL};
	No a2 = {2, &a3};
	No a1 = {1, &a2};

	No b2 = {5, NULL};
	No b1 = {4, &b2};

	No *concatenada = concatenarListas(&a1, &b1);

	printf("Lista 1 original: ");
	imprimirLista(&a1);
	printf("Lista 2 original: ");
	imprimirLista(&b1);
	printf("Lista concatenada: ");
	imprimirLista(concatenada);

	liberarLista(concatenada);
	return 0;
}

