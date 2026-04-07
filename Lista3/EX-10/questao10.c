/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 10
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_TAM 100

struct produto {
	int codProd;
	char nomeProd[10];
	float valor;
	int qtdeEstoque;
};

typedef struct {
	struct produto dados[MAX_TAM];
	int tamanho;
} ListaEstaticaProdutos;

bool buscarProdutoMenorPreco(const ListaEstaticaProdutos *lista, struct produto *menorPreco) {
	int i;
	int indiceMenor;

	if (lista == NULL || menorPreco == NULL || lista->tamanho <= 0) {
		return false;
	}

	indiceMenor = 0;

	for (i = 1; i < lista->tamanho; i++) {
		if (lista->dados[i].valor < lista->dados[indiceMenor].valor) {
			indiceMenor = i;
		}
	}

	*menorPreco = lista->dados[indiceMenor];
	return true;
}

int main(void) {
	ListaEstaticaProdutos lista = {
		{
			{101, "Arroz", 25.90f, 30},
			{102, "Feijao", 8.50f, 20},
			{103, "Macarrao", 6.75f, 15},
			{104, "Leite", 7.20f, 40}
		},
		4
	};
	struct produto menor;

	if (buscarProdutoMenorPreco(&lista, &menor)) {
		printf("Produto de menor preco:\n");
		printf("Codigo: %d\n", menor.codProd);
		printf("Nome: %s\n", menor.nomeProd);
		printf("Valor: %.2f\n", menor.valor);
		printf("Estoque: %d\n", menor.qtdeEstoque);
	}

	return 0;
}

