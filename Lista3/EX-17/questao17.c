/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 17
*/

#include <stdio.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

No *inverterLista(No *inicio) {
	No *anterior = NULL;
	No *atual = inicio;
	No *proximo;

	while (atual != NULL) {
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = proximo;
	}

	return anterior;
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
	No n5 = {50, NULL};
	No n4 = {40, &n5};
	No n3 = {30, &n4};
	No n2 = {20, &n3};
	No n1 = {10, &n2};
	No *lista = &n1;

	printf("Lista original: ");
	imprimirLista(lista);

	lista = inverterLista(lista);

	printf("Lista invertida: ");
	imprimirLista(lista);

	return 0;
}

