/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 13
*/

#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

void copiarSemRepetidos(const ListaEstatica *l1, ListaEstatica *l2) {
	int i;
	int j;
	int repetido;

	if (l1 == NULL || l2 == NULL) {
		return;
	}

	l2->tamanho = 0;

	for (i = 0; i < l1->tamanho && l2->tamanho < MAX_TAM; i++) {
		repetido = 0;

		for (j = 0; j < l2->tamanho; j++) {
			if (l1->dados[i] == l2->dados[j]) {
				repetido = 1;
				break;
			}
		}

		if (!repetido) {
			l2->dados[l2->tamanho] = l1->dados[i];
			l2->tamanho++;
		}
	}
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
	ListaEstatica l1 = {{4, 2, 4, 7, 2, 9, 9, 1}, 8};
	ListaEstatica l2;

	copiarSemRepetidos(&l1, &l2);

	printf("L1: ");
	imprimirLista(&l1);
	printf("L2 sem repetidos: ");
	imprimirLista(&l2);

	return 0;
}

