/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 2
Exercício: 10
*/




#include <stdio.h>
#include <stdlib.h>

    
    typedef struct {
    int codigo;
    char nome[51];   
    int quantidade;
    double preco;
} Produto;

int main(void) {
    int n;
    Produto *produtos = NULL;

    printf("Informe a quantidade de produtos: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (n <= 0) {
        printf("A quantidade deve ser maior que zero.\n");
        return 1;
    }

    produtos = (Produto *) malloc(n * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Codigo: ");
        if (scanf("%d", &produtos[i].codigo) != 1) {
            printf("Entrada invalida para codigo.\n");
            free(produtos);
            return 1;
        }

        printf("Nome (sem espacos): ");
        if (scanf("%50s", produtos[i].nome) != 1) {
            printf("Entrada invalida para nome.\n");
            free(produtos);
            return 1;
        }

        printf("Quantidade em estoque: ");
        if (scanf("%d", &produtos[i].quantidade) != 1) {
            printf("Entrada invalida para quantidade.\n");
            free(produtos);
            return 1;
        }

        printf("Preco de venda: ");
        if (scanf("%lf", &produtos[i].preco) != 1) {
            printf("Entrada invalida para preco.\n");
            free(produtos);
            return 1;
        }
    }

    int idxMaiorPreco = 0;
    int idxMaiorQtd = 0;

    for (int i = 1; i < n; i++) {
        if (produtos[i].preco > produtos[idxMaiorPreco].preco) {
            idxMaiorPreco = i;
        }

        if (produtos[i].quantidade > produtos[idxMaiorQtd].quantidade) {
            idxMaiorQtd = i;
        }
    }

    printf("\n=== Produto com MAIOR PRECO ===\n");
    printf("Codigo: %d\n", produtos[idxMaiorPreco].codigo);
    printf("Nome: %s\n", produtos[idxMaiorPreco].nome);
    printf("Quantidade: %d\n", produtos[idxMaiorPreco].quantidade);
    printf("Preco: %.2f\n", produtos[idxMaiorPreco].preco);

    printf("\n=== Produto com MAIOR QUANTIDADE EM ESTOQUE ===\n");
    printf("Codigo: %d\n", produtos[idxMaiorQtd].codigo);
    printf("Nome: %s\n", produtos[idxMaiorQtd].nome);
    printf("Quantidade: %d\n", produtos[idxMaiorQtd].quantidade);
    printf("Preco: %.2f\n", produtos[idxMaiorQtd].preco);

    free(produtos);
    produtos = NULL;

    return 0;
}
    


