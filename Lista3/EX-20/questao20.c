/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 20
*/

#include <stdbool.h>
#include <stdio.h>

typedef struct No {
	int valor;
	struct No *prox;
} No;

bool listasIguais(const No *l1, const No *l2) {
	const No *p1 = l1;
	const No *p2 = l2;

	while (p1 != NULL && p2 != NULL) {
		if (p1->valor != p2->valor) {
			return false;
		}
		p1 = p1->prox;
		p2 = p2->prox;
	}

	return p1 == NULL && p2 == NULL;
}

int main(void) {
	No a3 = {30, NULL};
	No a2 = {20, &a3};
	No a1 = {10, &a2};

	No b3 = {30, NULL};
	No b2 = {20, &b3};
	No b1 = {10, &b2};

	No c3 = {40, NULL};
	No c2 = {20, &c3};
	No c1 = {10, &c2};

	printf("Lista A e Lista B sao iguais? %s\n", listasIguais(&a1, &b1) ? "Sim" : "Nao");
	printf("Lista A e Lista C sao iguais? %s\n", listasIguais(&a1, &c1) ? "Sim" : "Nao");

	return 0;
}

