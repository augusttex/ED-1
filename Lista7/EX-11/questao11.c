/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 11


*/ 

#include <stdio.h>
#include <stdlib.h>

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

void espelho_inPlace(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    struct NO* temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;
    
    espelho_inPlace(raiz->esq);
    espelho_inPlace(raiz->dir);
}

struct NO* espelho_nova_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return NULL;
    
    struct NO* novo = cria_no(raiz->info);
    if(novo != NULL) {
        novo->esq = espelho_nova_arvore(raiz->dir);
        novo->dir = espelho_nova_arvore(raiz->esq);
    }
    
    return novo;
}

void imprime_preOrdem(struct NO* raiz, int nivel) {
    if(raiz == NULL)
        return;
    
    for(int i = 0; i < nivel; i++)
        printf("  ");
    
    printf("%d\n", raiz->info);
    
    if(raiz->esq != NULL || raiz->dir != NULL) {
        imprime_preOrdem(raiz->esq, nivel + 1);
        imprime_preOrdem(raiz->dir, nivel + 1);
    }
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    printf("=== TESTE 1: Espelho In-Place ===\n\n");
    
    ArvBin *raiz1 = cria_ArvBin();
    insere_ArvBin_Busca(raiz1, 4);
    insere_ArvBin_Busca(raiz1, 2);
    insere_ArvBin_Busca(raiz1, 6);
    insere_ArvBin_Busca(raiz1, 1);
    insere_ArvBin_Busca(raiz1, 3);
    insere_ArvBin_Busca(raiz1, 5);
    insere_ArvBin_Busca(raiz1, 10);
    insere_ArvBin_Busca(raiz1, 8);
    
    printf("Arvore original:\n");
    imprime_preOrdem(*raiz1, 0);
    
    espelho_inPlace(*raiz1);
    
    printf("\nArvore depois do espelho (in-place):\n");
    imprime_preOrdem(*raiz1, 0);
    
    printf("\n\n=== TESTE 2: Espelho com nova arvore ===\n\n");
    
    ArvBin *raiz2 = cria_ArvBin();
    insere_ArvBin_Busca(raiz2, 4);
    insere_ArvBin_Busca(raiz2, 2);
    insere_ArvBin_Busca(raiz2, 6);
    insere_ArvBin_Busca(raiz2, 1);
    insere_ArvBin_Busca(raiz2, 3);
    insere_ArvBin_Busca(raiz2, 5);
    insere_ArvBin_Busca(raiz2, 10);
    insere_ArvBin_Busca(raiz2, 8);
    
    printf("Arvore original:\n");
    imprime_preOrdem(*raiz2, 0);
    
    struct NO* espelho = espelho_nova_arvore(*raiz2);
    
    printf("\nEspelho (nova arvore):\n");
    imprime_preOrdem(espelho, 0);
    
    printf("\nArvore original (inalterada):\n");
    imprime_preOrdem(*raiz2, 0);
    
    libera_arvore(espelho);
    
    return 0;
}


