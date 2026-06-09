/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 12

Funcao: Verifica se duas arvores binarias sao iguais

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

int arvores_iguais(struct NO* arv1, struct NO* arv2) {
    if(arv1 == NULL && arv2 == NULL)
        return 1;
    
    if(arv1 == NULL || arv2 == NULL)
        return 0;
    
    if(arv1->info != arv2->info)
        return 0;
    
    return arvores_iguais(arv1->esq, arv2->esq) &&
           arvores_iguais(arv1->dir, arv2->dir);
}

void imprime_inOrdem(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    imprime_inOrdem(raiz->esq);
    printf("%d ", raiz->info);
    imprime_inOrdem(raiz->dir);
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    printf("=== TESTE 1: Duas arvores IGUAIS ===\n\n");
    
    ArvBin *arv1 = cria_ArvBin();
    insere_ArvBin_Busca(arv1, 50);
    insere_ArvBin_Busca(arv1, 30);
    insere_ArvBin_Busca(arv1, 70);
    insere_ArvBin_Busca(arv1, 20);
    insere_ArvBin_Busca(arv1, 40);
    
    printf("Arvore 1: ");
    imprime_inOrdem(*arv1);
    printf("\n");
    
    ArvBin *arv2 = cria_ArvBin();
    insere_ArvBin_Busca(arv2, 50);
    insere_ArvBin_Busca(arv2, 30);
    insere_ArvBin_Busca(arv2, 70);
    insere_ArvBin_Busca(arv2, 20);
    insere_ArvBin_Busca(arv2, 40);
    
    printf("Arvore 2: ");
    imprime_inOrdem(*arv2);
    printf("\n\n");
    
    if(arvores_iguais(*arv1, *arv2))
        printf("Resultado: IGUAIS\n\n");
    else
        printf("Resultado: DIFERENTES\n\n");
    
    printf("=== TESTE 2: Duas arvores DIFERENTES (valores) ===\n\n");
    
    struct NO* arv3 = cria_no(50);
    arv3->esq = cria_no(30);
    arv3->dir = cria_no(70);
    arv3->esq->esq = cria_no(20);
    arv3->esq->dir = cria_no(40);
    
    printf("Arvore 3: ");
    imprime_inOrdem(arv3);
    printf("\n");
    
    struct NO* arv4 = cria_no(50);
    arv4->esq = cria_no(30);
    arv4->dir = cria_no(70);
    arv4->esq->esq = cria_no(25);
    arv4->esq->dir = cria_no(40);
    
    printf("Arvore 4: ");
    imprime_inOrdem(arv4);
    printf("\n\n");
    
    if(arvores_iguais(arv3, arv4))
        printf("Resultado: IGUAIS\n\n");
    else
        printf("Resultado: DIFERENTES (20 != 25)\n\n");
    
    printf("=== TESTE 3: Duas arvores DIFERENTES (estrutura) ===\n\n");
    
    struct NO* arv5 = cria_no(50);
    arv5->esq = cria_no(30);
    arv5->dir = cria_no(70);
    arv5->esq->esq = cria_no(20);
    arv5->esq->dir = cria_no(40);
    
    printf("Arvore 5: ");
    imprime_inOrdem(arv5);
    printf("\n");
    
    struct NO* arv6 = cria_no(50);
    arv6->esq = cria_no(30);
    arv6->dir = cria_no(70);
    arv6->esq->esq = cria_no(20);
    
    printf("Arvore 6: ");
    imprime_inOrdem(arv6);
    printf("\n\n");
    
    if(arvores_iguais(arv5, arv6))
        printf("Resultado: IGUAIS\n\n");
    else
        printf("Resultado: DIFERENTES (estrutura diferente)\n\n");
    
    printf("=== TESTE 4: Arvore vazia == Arvore vazia ===\n\n");
    
    struct NO* arv7 = NULL;
    struct NO* arv8 = NULL;
    
    printf("Arvore 7: vazia\n");
    printf("Arvore 8: vazia\n\n");
    
    if(arvores_iguais(arv7, arv8))
        printf("Resultado: IGUAIS\n");
    else
        printf("Resultado: DIFERENTES\n");
    
    libera_arvore(arv3);
    libera_arvore(arv4);
    libera_arvore(arv5);
    libera_arvore(arv6);
    
    return 0;
}
