/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 19
*/

#include <stdio.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

int tamanhoListaRecursivo(const No *inicio) {
	if (inicio == NULL) {
		return 0;
	}

	return 1 + tamanhoListaRecursivo(inicio->prox);
}

int main(void) {
	No n4 = {40, NULL};
	No n3 = {30, &n4};
	No n2 = {20, &n3};
	No n1 = {10, &n2};
	No *lista = &n1;

	printf("Tamanho da lista: %d\n", tamanhoListaRecursivo(lista));

	return 0;
}

