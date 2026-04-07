/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 11
*/

#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

ListaEstatica obterApenasPares(const ListaEstatica *lista) {
	ListaEstatica listaPares;
	int i;

	listaPares.tamanho = 0;

	if (lista == NULL) {
		return listaPares;
	}

	for (i = 0; i < lista->tamanho && listaPares.tamanho < MAX_TAM; i++) {
		if (lista->dados[i] % 2 == 0) {
			listaPares.dados[listaPares.tamanho] = lista->dados[i];
			listaPares.tamanho++;
		}
	}

	return listaPares;
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
	ListaEstatica listaOriginal = {{1, 2, 3, 4, 5, 6, 7, 8}, 8};
	ListaEstatica listaPares;

	listaPares = obterApenasPares(&listaOriginal);

	printf("Lista original: ");
	imprimirLista(&listaOriginal);
	printf("Lista com pares: ");
	imprimirLista(&listaPares);

	return 0;
}

