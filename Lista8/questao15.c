/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 8
Exercício: 15

Funcao: Versao iterativa do algoritmo de insercao em arvore AVL

*/ 

#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvAVL;

struct Pilha {
    struct NO** dados;
    int topo;
    int capacidade;
};

typedef struct Pilha* Pilha;

Pilha cria_pilha(int capacidade) {
    Pilha p = (Pilha)malloc(sizeof(struct Pilha));
    if(p != NULL) {
        p->dados = (struct NO**)malloc(capacidade * sizeof(struct NO*));
        p->topo = -1;
        p->capacidade = capacidade;
    }
    return p;
}

int pilha_vazia(Pilha p) {
    return (p->topo == -1);
}

int push(Pilha p, struct NO* no) {
    if(p->topo == p->capacidade - 1)
        return 0;
    p->dados[++p->topo] = no;
    return 1;
}

struct NO* pop(Pilha p) {
    if(pilha_vazia(p))
        return NULL;
    return p->dados[p->topo--];
}

struct NO* topo(Pilha p) {
    if(pilha_vazia(p))
        return NULL;
    return p->dados[p->topo];
}

void libera_pilha(Pilha p) {
    if(p != NULL) {
        free(p->dados);
        free(p);
    }
}

int alt_NO(struct NO* no) {
    if(no == NULL)
        return -1;
    return no->alt;
}

int fatorBalanceamento_NO(struct NO* no) {
    if(no == NULL)
        return 0;
    return abs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y) {
    return (x > y) ? x : y;
}

void rotacaoLL(struct NO** raiz) {
    struct NO *no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void rotacaoRR(struct NO** raiz) {
    struct NO *no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void rotacaoLR(struct NO** raiz) {
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(struct NO** raiz) {
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insere_ArvAVL_Iterativo(ArvAVL *raiz, int valor) {
    if(*raiz == NULL) {
        struct NO *novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    
    Pilha p = cria_pilha(100);
    struct NO* atual = *raiz;
    struct NO* pai = NULL;
    
    while(atual != NULL) {
        push(p, atual);
        pai = atual;
        
        if(valor < atual->info) {
            atual = atual->esq;
        }
        else if(valor > atual->info) {
            atual = atual->dir;
        }
        else {
            printf("Valor duplicado!!\n");
            libera_pilha(p);
            return 0;
        }
    }
    
    struct NO *novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL) {
        libera_pilha(p);
        return 0;
    }
    
    novo->info = valor;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    
    if(valor < pai->info) {
        pai->esq = novo;
    }
    else {
        pai->dir = novo;
    }
    
    while(!pilha_vazia(p)) {
        struct NO* no = pop(p);
        no->alt = maior(alt_NO(no->esq), alt_NO(no->dir)) + 1;
        
        int fb = fatorBalanceamento_NO(no);
        
        if(fb >= 2) {
            if(alt_NO(no->esq) > alt_NO(no->dir)) {
                if(valor < no->esq->info) {
                    rotacaoLL(&no);
                }
                else {
                    rotacaoLR(&no);
                }
            }
            else {
                if(valor < no->dir->info) {
                    rotacaoRL(&no);
                }
                else {
                    rotacaoRR(&no);
                }
            }
        }
        
        if(!pilha_vazia(p)) {
            struct NO* pai_no = topo(p);
            if(valor < pai_no->info) {
                pai_no->esq = no;
            }
            else {
                pai_no->dir = no;
            }
        }
        else {
            *raiz = no;
        }
    }
    
    libera_pilha(p);
    return 1;
}

void emOrdem_ArvAVL(ArvAVL raiz) {
    if(raiz == NULL)
        return;
    
    emOrdem_ArvAVL(raiz->esq);
    printf("%d(h:%d) ", raiz->info, raiz->alt);
    emOrdem_ArvAVL(raiz->dir);
}

void preOrdem_ArvAVL(ArvAVL raiz) {
    if(raiz == NULL)
        return;
    
    printf("%d(h:%d) ", raiz->info, raiz->alt);
    preOrdem_ArvAVL(raiz->esq);
    preOrdem_ArvAVL(raiz->dir);
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    printf("=== TESTE: INSERCAO ITERATIVA EM AVL ===\n\n");
    
    printf("TESTE 1: Insercao Iterativa\n");
    ArvAVL arvore_iter = NULL;
    int valores[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 65, 77, 90};
    
    printf("Inserindo: ");
    for(int i = 0; i < 14; i++) {
        printf("%d ", valores[i]);
        insere_ArvAVL_Iterativo(&arvore_iter, valores[i]);
    }
    printf("\n");
    
    printf("Pre-ordem: ");
    preOrdem_ArvAVL(arvore_iter);
    printf("\n");
    
    printf("Em-ordem: ");
    emOrdem_ArvAVL(arvore_iter);
    printf("\n\n");
    
    libera_arvore(arvore_iter);
    
    printf("=== TESTE 2: CASOS ESPECIAIS ===\n\n");
    
    printf("Caso 1: Arvore vazia\n");
    ArvAVL arvore_vazia = NULL;
    insere_ArvAVL_Iterativo(&arvore_vazia, 50);
    printf("Apos insercao: ");
    emOrdem_ArvAVL(arvore_vazia);
    printf("\n\n");
    libera_arvore(arvore_vazia);
    
    printf("Caso 2: Sequencia crescente\n");
    ArvAVL arvore_crescente = NULL;
    printf("Inserindo: 1 2 3 4 5 6 7\n");
    for(int i = 1; i <= 7; i++) {
        insere_ArvAVL_Iterativo(&arvore_crescente, i);
    }
    printf("Pre-ordem: ");
    preOrdem_ArvAVL(arvore_crescente);
    printf("\n");
    libera_arvore(arvore_crescente);
    
    return 0;
}
