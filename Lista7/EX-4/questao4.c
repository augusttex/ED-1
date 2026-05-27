/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 4

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

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int insere_ArvBin_Balanceada(ArvBin *raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
        return 1;
    }
    
    free(novo);
    
    if(altura_ArvBin(&((*raiz)->esq)) <= altura_ArvBin(&((*raiz)->dir)))
    {
        return insere_ArvBin_Balanceada(&((*raiz)->esq), valor);
    }
    else{
        return insere_ArvBin_Balanceada(&((*raiz)->dir), valor);
    }
}


int main()
{
    ArvBin *raiz = cria_ArvBin();

    insere_ArvBin_Balanceada(raiz, 50);
    insere_ArvBin_Balanceada(raiz, 30);
    insere_ArvBin_Balanceada(raiz, 70);
    insere_ArvBin_Balanceada(raiz, 20);
    insere_ArvBin_Balanceada(raiz, 40);

    preOrdem_ArvBin(raiz);
    
    return 0;
    
}