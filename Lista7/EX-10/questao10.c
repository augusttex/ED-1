/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 10


*/ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int insere_ArvBin_Busca(ArvBin *raiz, int valor) {
    if(raiz == NULL)
        return 0;
    
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    if(*raiz == NULL) {
        *raiz = novo;
        return 1;
    }
    
    free(novo);
    
    if(valor < (*raiz)->info)
        return insere_ArvBin_Busca(&((*raiz)->esq), valor);
    else if(valor > (*raiz)->info)
        return insere_ArvBin_Busca(&((*raiz)->dir), valor);
    
    return 0;
}

struct NO* cria_no(int valor) {
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL) {
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

int eh_ABB_auxiliar(struct NO* raiz, int minimo, int maximo) {
    if(raiz == NULL)
        return 1;
    
    if(raiz->info <= minimo || raiz->info >= maximo)
        return 0;
    
    return eh_ABB_auxiliar(raiz->esq, minimo, raiz->info) &&
           eh_ABB_auxiliar(raiz->dir, raiz->info, maximo);
}

int eh_ABB(struct NO* raiz) {
    return eh_ABB_auxiliar(raiz, INT_MIN, INT_MAX);
}

void imprime_inOrdem(struct NO* raiz) {
    if(raiz == NULL)
        return;
    imprime_inOrdem(raiz->esq);
    printf("%d ", raiz->info);
    imprime_inOrdem(raiz->dir);
}

int main() {
    ArvBin *raiz1 = cria_ArvBin();
    
    printf("=== TESTE 1: Arvore valida (ABB) ===\n");
    insere_ArvBin_Busca(raiz1, 50);
    insere_ArvBin_Busca(raiz1, 30);
    insere_ArvBin_Busca(raiz1, 70);
    insere_ArvBin_Busca(raiz1, 20);
    insere_ArvBin_Busca(raiz1, 40);
    insere_ArvBin_Busca(raiz1, 60);
    insere_ArvBin_Busca(raiz1, 80);
    
    printf("Arvore: ");
    imprime_inOrdem(*raiz1);
    printf("\n");
    
    if(eh_ABB(*raiz1))
        printf("E uma arvore binaria de busca: SIM\n\n");
    else
        printf("E uma arvore binaria de busca: NAO\n\n");
    
    printf("=== TESTE 2: Arvore invalida (NAO e ABB) ===\n");
    struct NO* raiz2 = cria_no(50);
    raiz2->esq = cria_no(30);
    raiz2->dir = cria_no(70);
    raiz2->esq->dir = cria_no(65);
    
    printf("Arvore: ");
    imprime_inOrdem(raiz2);
    printf("\n");
    
    if(eh_ABB(raiz2))
        printf("E uma arvore binaria de busca: SIM\n\n");
    else {
        printf("E uma arvore binaria de busca: NAO\n");
        printf("(Motivo: 65 esta na esquerda de 50 mas e maior)\n\n");
    }
    
    printf("=== TESTE 3: Arvore simples (um no) ===\n");
    struct NO* raiz3 = cria_no(42);
    
    printf("Arvore: ");
    imprime_inOrdem(raiz3);
    printf("\n");
    
    if(eh_ABB(raiz3))
        printf("E uma arvore binaria de busca: SIM\n");
    else
        printf("E uma arvore binaria de busca: NAO\n");
    
    return 0;
}