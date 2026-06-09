/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 9




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

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2 ->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

struct NO* remover_pares(struct NO* raiz) {
    if(raiz == NULL)
        return NULL;
    
    raiz->esq = remover_pares(raiz->esq);
    raiz->dir = remover_pares(raiz->dir);
    
    if(raiz->info % 2 == 0) {
        struct NO* temp = remove_atual(raiz);
        return temp;
    }
    
    return raiz;
}

void imprime_inOrdem(struct NO* raiz) {
    if(raiz == NULL)
        return;
    imprime_inOrdem(raiz->esq);
    printf("%d ", raiz->info);
    imprime_inOrdem(raiz->dir);
}

int main()
{
    ArvBin *raiz = cria_ArvBin();

    insere_ArvBin_Balanceada(raiz, 67);
    insere_ArvBin_Balanceada(raiz, 93);
    insere_ArvBin_Balanceada(raiz, 71);
    insere_ArvBin_Balanceada(raiz, 20);
    insere_ArvBin_Balanceada(raiz, 40);

    printf("Arvore ANTES de remover pares:\n");
    imprime_inOrdem(*raiz);
    printf("\n\n");

    *raiz = remover_pares(*raiz);

    printf("Arvore DEPOIS de remover pares:\n");
    imprime_inOrdem(*raiz);
    printf("\n");
  
    return 0;
}


