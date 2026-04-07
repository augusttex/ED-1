/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 15
*/

#include <stdio.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

int copiarListaParaVetor(const No *inicio, int vetor[], int capacidade) {
	int i = 0;
	const No *atual = inicio;

	if (vetor == NULL || capacidade <= 0) {
		return 0;
	}

	while (atual != NULL && i < capacidade) {
		vetor[i] = atual->valor;
		i++;
		atual = atual->prox;
	}

	return i;
}

int main(void) {
	No n4 = {40, NULL};
	No n3 = {30, &n4};
	No n2 = {20, &n3};
	No n1 = {10, &n2};
	int vetor[10];
	int quantidade;
	int i;

	quantidade = copiarListaParaVetor(&n1, vetor, 10);

	printf("Elementos copiados para o vetor: [");
	for (i = 0; i < quantidade; i++) {
		printf("%d", vetor[i]);
		if (i < quantidade - 1) {
			printf(", ");
		}
	}
	printf("]\n");

	return 0;
}

