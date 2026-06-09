/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 18

Funcao: Percursos nao recursivos em arvore binaria usando pilha

*/ 

#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

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

int pilha_cheia(Pilha p) {
    return (p->topo == p->capacidade - 1);
}

int push(Pilha p, struct NO* no) {
    if(pilha_cheia(p))
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

struct NO* cria_no(int valor) {
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL) {
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void preOrdem_naoRecursiva(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    Pilha p = cria_pilha(100);
    push(p, raiz);
    
    while(!pilha_vazia(p)) {
        struct NO* no = pop(p);
        printf("%d ", no->info);
        
        if(no->dir != NULL)
            push(p, no->dir);
        if(no->esq != NULL)
            push(p, no->esq);
    }
    
    libera_pilha(p);
}

void emOrdem_naoRecursiva(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    Pilha p = cria_pilha(100);
    struct NO* no = raiz;
    
    while(no != NULL || !pilha_vazia(p)) {
        while(no != NULL) {
            push(p, no);
            no = no->esq;
        }
        
        no = pop(p);
        printf("%d ", no->info);
        
        no = no->dir;
    }
    
    libera_pilha(p);
}

void posOrdem_naoRecursiva(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    Pilha p = cria_pilha(100);
    struct NO* ultimo = NULL;
    struct NO* no = raiz;
    
    while(no != NULL || !pilha_vazia(p)) {
        if(no != NULL) {
            push(p, no);
            no = no->esq;
        }
        else {
            struct NO* topo_pilha = topo(p);
            
            if(topo_pilha->dir != NULL && topo_pilha->dir != ultimo) {
                no = topo_pilha->dir;
            }
            else {
                printf("%d ", topo_pilha->info);
                ultimo = pop(p);
            }
        }
    }
    
    libera_pilha(p);
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    printf("=== TESTE: PERCURSOS NAO RECURSIVOS ===\n\n");
    
    struct NO* raiz = cria_no(1);
    raiz->esq = cria_no(2);
    raiz->dir = cria_no(3);
    raiz->esq->esq = cria_no(4);
    raiz->esq->dir = cria_no(5);
    raiz->dir->esq = cria_no(6);
    raiz->dir->dir = cria_no(7);
    raiz->esq->esq->esq = cria_no(8);
    raiz->esq->esq->dir = cria_no(9);
    
    printf("Arvore:\n");
    printf("          1\n");
    printf("        /   \\\n");
    printf("       2     3\n");
    printf("      / \\   / \\\n");
    printf("     4   5 6   7\n");
    printf("    / \\\n");
    printf("   8   9\n\n");
    
    printf("Pre-ordem (raiz, esq, dir): ");
    preOrdem_naoRecursiva(raiz);
    printf("\n");
    
    printf("Em-ordem (esq, raiz, dir): ");
    emOrdem_naoRecursiva(raiz);
    printf("\n");
    
    printf("Pos-ordem (esq, dir, raiz): ");
    posOrdem_naoRecursiva(raiz);
    printf("\n\n");
    
    printf("=== TESTE 2: ARVORE MENOR ===\n\n");
    
    struct NO* raiz2 = cria_no(50);
    raiz2->esq = cria_no(30);
    raiz2->dir = cria_no(70);
    raiz2->esq->esq = cria_no(20);
    raiz2->esq->dir = cria_no(40);
    raiz2->dir->esq = cria_no(60);
    raiz2->dir->dir = cria_no(80);
    
    printf("Arvore:\n");
    printf("          50\n");
    printf("        /    \\\n");
    printf("       30     70\n");
    printf("      /  \\   /  \\\n");
    printf("    20   40 60  80\n\n");
    
    printf("Pre-ordem: ");
    preOrdem_naoRecursiva(raiz2);
    printf("\n");
    
    printf("Em-ordem: ");
    emOrdem_naoRecursiva(raiz2);
    printf("\n");
    
    printf("Pos-ordem: ");
    posOrdem_naoRecursiva(raiz2);
    printf("\n");
    
    libera_arvore(raiz);
    libera_arvore(raiz2);
    
    return 0;
}
