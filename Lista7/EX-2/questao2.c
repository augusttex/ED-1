/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 2

*/ 

#include <stdio.h>
#include<stdlib.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // elemento ja existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


int contarNos_ArvBin(ArvBin *raiz){

    struct NO* pilha[100];
    int topo = 0;
    int nos = 0;
    
    if(raiz == NULL)
    return 0;

    pilha[topo] = *raiz;
    topo++;
    
    while(topo > 0)
    {
        struct NO* atual = pilha[--topo];
        nos++;
        if(atual->dir != NULL)
            pilha[topo++] = atual->dir;
        if(atual->esq != NULL)
            pilha[topo++] = atual->esq;
    }


    return nos;
}

int main()
{
    ArvBin *raiz = cria_ArvBin();

    insere_ArvBin(raiz, 50);
    insere_ArvBin(raiz, 30);
    insere_ArvBin(raiz, 70);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 40);

    printf("O numero de nos nessa arvore e: %d ", contarNos_ArvBin(raiz));
    return 0;
    
}