/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 6
*/

#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

ListaEstatica concatenarListas(ListaEstatica lista1, ListaEstatica lista2) {
	ListaEstatica resultado;
	int i;

	resultado.tamanho = 0;

	for (i = 0; i < lista1.tamanho && resultado.tamanho < MAX_TAM; i++) {
		resultado.dados[resultado.tamanho] = lista1.dados[i];
		resultado.tamanho++;
	}

	for (i = 0; i < lista2.tamanho && resultado.tamanho < MAX_TAM; i++) {
		resultado.dados[resultado.tamanho] = lista2.dados[i];
		resultado.tamanho++;
	}

	return resultado;
}

void imprimirLista(ListaEstatica lista) {
	int i;

	printf("[");
	for (i = 0; i < lista.tamanho; i++) {
		printf("%d", lista.dados[i]);
		if (i < lista.tamanho - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(void) {
	ListaEstatica lista1 = {{1, 2, 3, 4}, 4};
	ListaEstatica lista2 = {{5, 6, 7}, 3};
	ListaEstatica listaConcatenada;

	listaConcatenada = concatenarListas(lista1, lista2);

	printf("Lista 1: ");
	imprimirLista(lista1);
	printf("Lista 2: ");
	imprimirLista(lista2);
	printf("Concatenacao: ");
	imprimirLista(listaConcatenada);

	return 0;
}

