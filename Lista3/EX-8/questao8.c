/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 8
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

bool buscarMaior(const ListaEstatica *lista, int *posicaoMaior, int *valorMaior) {
	int i;
	int indiceMaior;

	if (lista == NULL || posicaoMaior == NULL || valorMaior == NULL || lista->tamanho <= 0) {
		return false;
	}

	indiceMaior = 0;

	for (i = 1; i < lista->tamanho; i++) {
		if (lista->dados[i] > lista->dados[indiceMaior]) {
			indiceMaior = i;
		}
	}

	*posicaoMaior = indiceMaior;
	*valorMaior = lista->dados[indiceMaior];
	return true;
}

int main(void) {
	ListaEstatica lista = {{12, 8, 35, 17, 35, 4}, 6};
	int posicao;
	int valor;

	if (buscarMaior(&lista, &posicao, &valor)) {
		printf("Posicao do maior: %d\n", posicao);
		printf("Valor do maior: %d\n", valor);
	}

	return 0;
}

