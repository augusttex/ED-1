/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 12
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_TAM 100

typedef struct {
	int dados[MAX_TAM];
	int tamanho;
} ListaEstatica;

bool listaOrdenada(const ListaEstatica *lista) {
	int i;
	bool crescente = true;
	bool decrescente = true;

	if (lista == NULL || lista->tamanho <= 1) {
		return true;
	}

	for (i = 1; i < lista->tamanho; i++) {
		if (lista->dados[i] < lista->dados[i - 1]) {
			crescente = false;
		}
		if (lista->dados[i] > lista->dados[i - 1]) {
			decrescente = false;
		}
	}

	return crescente || decrescente;
}

int main(void) {
	ListaEstatica listaCrescente = {{1, 2, 2, 5, 8}, 5};
	ListaEstatica listaDecrescente = {{9, 7, 7, 3, 1}, 5};
	ListaEstatica listaNaoOrdenada = {{1, 4, 3, 6, 2}, 5};

	printf("Lista crescente ordenada? %s\n", listaOrdenada(&listaCrescente) ? "Sim" : "Nao");
	printf("Lista decrescente ordenada? %s\n", listaOrdenada(&listaDecrescente) ? "Sim" : "Nao");
	printf("Lista nao ordenada? %s\n", listaOrdenada(&listaNaoOrdenada) ? "Sim" : "Nao");

	return 0;
}

