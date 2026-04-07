/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 9
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

bool trocarPosicoes(ListaEstatica *lista, int pos1, int pos2) {
	int temp;

	if (lista == NULL || pos1 < 0 || pos2 < 0 || pos1 >= lista->tamanho || pos2 >= lista->tamanho) {
		return false;
	}

	temp = lista->dados[pos1];
	lista->dados[pos1] = lista->dados[pos2];
	lista->dados[pos2] = temp;

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
	bool operacaoInvalida;

	printf("Lista original: ");
	imprimirLista(&lista);

	if (trocarPosicoes(&lista, 1, 3)) {
		printf("Apos trocar posicoes 1 e 3: ");
		imprimirLista(&lista);
	}

	operacaoInvalida = trocarPosicoes(&lista, 2, 10);
	(void)operacaoInvalida;

	return 0;
}

