/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 7
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

bool removerPrimeirosN(ListaEstatica *lista, int n) {
	int i;

	if (lista == NULL || n < 0 || n > lista->tamanho) {
		return false;
	}

	for (i = n; i < lista->tamanho; i++) {
		lista->dados[i - n] = lista->dados[i];
	}

	lista->tamanho -= n;
	return true;
}

void imprimirLista(const ListaEstatica *lista) {
	int i;

	printf("[");
	for (i = 0; i < lista->tamanho; i++) {
		printf("%d", lista->dados[i]);
		if (i < lista->tamanho - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(void) {
	ListaEstatica lista = {{10, 20, 30, 40, 50}, 5};
	bool operacaoValida;

	printf("Lista original: ");
	imprimirLista(&lista);

	if (removerPrimeirosN(&lista, 2)) {
		printf("Remocao de 2 elementos: ");
		imprimirLista(&lista);
	} else {
		printf("Nao foi possivel remover 2 elementos.\n");
	}

	operacaoValida = removerPrimeirosN(&lista, 10);
	(void)operacaoValida;

	return 0;
}

