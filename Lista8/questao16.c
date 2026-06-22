/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 8
Exercício: 16


*/ 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
    int info;
    int alt;
    struct NO* esq;
    struct NO* dir;
} NO;

typedef NO* ArvAVL;

typedef struct {
    struct NO** dados;
    int topo;
    int capacidade;
} Pilha;

Pilha cria_pilha(int capacidade) {
    Pilha p;
    p.dados = (struct NO**)malloc(capacidade * sizeof(struct NO*));
    p.topo = -1;
    p.capacidade = capacidade;
    return p;
}

void libera_pilha(Pilha p) {
    free(p.dados);
}

void push(Pilha *p, struct NO* no) {
    if(p->topo < p->capacidade - 1) {
        p->dados[++p->topo] = no;
    }
}

struct NO* pop(Pilha *p) {
    if(p->topo >= 0) {
        return p->dados[p->topo--];
    }
    return NULL;
}

struct NO* topo(Pilha p) {
    if(p.topo >= 0) {
        return p.dados[p.topo];
    }
    return NULL;
}

int pilha_vazia(Pilha p) {
    return p.topo == -1;
}

int maior(int x, int y) {
    return x > y ? x : y;
}

int alt_NO(struct NO* no) {
    if(no == NULL) return -1;
    return no->alt;
}

int fatorBalanceamento_NO(struct NO* no) {
    if(no == NULL) return 0;
    return alt_NO(no->esq) - alt_NO(no->dir);
}

void rotacaoLL(struct NO** raiz) {
    struct NO* temp = (*raiz)->esq;
    (*raiz)->esq = temp->dir;
    temp->dir = *raiz;
    
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    temp->alt = maior(alt_NO(temp->esq), alt_NO(temp->dir)) + 1;
    
    *raiz = temp;
}

void rotacaoRR(struct NO** raiz) {
    struct NO* temp = (*raiz)->dir;
    (*raiz)->dir = temp->esq;
    temp->esq = *raiz;
    
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    temp->alt = maior(alt_NO(temp->esq), alt_NO(temp->dir)) + 1;
    
    *raiz = temp;
}

void rotacaoLR(struct NO** raiz) {
    rotacaoRR(&((*raiz)->esq));
    rotacaoLL(raiz);
}

void rotacaoRL(struct NO** raiz) {
    rotacaoLL(&((*raiz)->dir));
    rotacaoRR(raiz);
}

struct NO* cria_no(int valor) {
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL) {
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

struct NO* encontra_minimo(struct NO* no) {
    struct NO* atual = no;
    while(atual != NULL && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

int remove_ArvAVL_Iterativo(ArvAVL *raiz, int valor) {
    if(*raiz == NULL) return 0;
    
    Pilha p = cria_pilha(100);
    struct NO* atual = *raiz;
    struct NO* pai = NULL;
    
    while(atual != NULL && atual->info != valor) {
        pai = atual;
        push(&p, pai);
        
        if(valor < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    
    if(atual == NULL) {
        libera_pilha(p);
        return 0;
    }
    
    if(atual->esq == NULL && atual->dir == NULL) {
        if(pai == NULL) {
            *raiz = NULL;
        } else if(pai->esq == atual) {
            pai->esq = NULL;
        } else {
            pai->dir = NULL;
        }
        free(atual);
    }
    else if(atual->esq == NULL) {
        if(pai == NULL) {
            *raiz = atual->dir;
        } else if(pai->esq == atual) {
            pai->esq = atual->dir;
        } else {
            pai->dir = atual->dir;
        }
        free(atual);
    }
    else if(atual->dir == NULL) {
        if(pai == NULL) {
            *raiz = atual->esq;
        } else if(pai->esq == atual) {
            pai->esq = atual->esq;
        } else {
            pai->dir = atual->esq;
        }
        free(atual);
    }
    else {
        struct NO* sucessor_pai = atual;
        struct NO* sucessor = atual->dir;
        
        while(sucessor->esq != NULL) {
            push(&p, sucessor_pai);
            sucessor_pai = sucessor;
            sucessor = sucessor->esq;
        }
        
        atual->info = sucessor->info;
        
        if(sucessor_pai == atual) {
            atual->dir = sucessor->dir;
        } else {
            sucessor_pai->esq = sucessor->dir;
        }
        
        free(sucessor);
        
        if(sucessor_pai != atual) {
            push(&p, sucessor_pai);
        }
    }
    
    while(!pilha_vazia(p)) {
        struct NO* no = pop(&p);
        
        no->alt = maior(alt_NO(no->esq), alt_NO(no->dir)) + 1;
        
        int fator = fatorBalanceamento_NO(no);
        
        if(fator >= 2) {
            if(fatorBalanceamento_NO(no->esq) <= -1) {
                rotacaoLR(no == *raiz ? raiz : 
                         (topo(p) != NULL ? (topo(p)->esq == no ? 
                         &(topo(p)->esq) : &(topo(p)->dir)) : raiz));
            } else {
                rotacaoLL(no == *raiz ? raiz : 
                         (topo(p) != NULL ? (topo(p)->esq == no ? 
                         &(topo(p)->esq) : &(topo(p)->dir)) : raiz));
            }
        }
        else if(fator <= -2) {
            if(fatorBalanceamento_NO(no->dir) >= 1) {
                rotacaoRL(no == *raiz ? raiz : 
                         (topo(p) != NULL ? (topo(p)->esq == no ? 
                         &(topo(p)->esq) : &(topo(p)->dir)) : raiz));
            } else {
                rotacaoRR(no == *raiz ? raiz : 
                         (topo(p) != NULL ? (topo(p)->esq == no ? 
                         &(topo(p)->esq) : &(topo(p)->dir)) : raiz));
            }
        }
    }
    
    libera_pilha(p);
    return 1;
}

void preOrdem_ArvAVL(struct NO* raiz) {
    if(raiz != NULL) {
        printf("%d(alt:%d) ", raiz->info, raiz->alt);
        preOrdem_ArvAVL(raiz->esq);
        preOrdem_ArvAVL(raiz->dir);
    }
}

void emOrdem_ArvAVL(struct NO* raiz) {
    if(raiz != NULL) {
        emOrdem_ArvAVL(raiz->esq);
        printf("%d ", raiz->info);
        emOrdem_ArvAVL(raiz->dir);
    }
}

void libera_arvore(struct NO* raiz) {
    if(raiz != NULL) {
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    printf("=== TESTE: REMOCAO ITERATIVA EM AVL ===\n\n");
    
    printf("TESTE 1: Remocao com rebalanceamento\n");
    ArvAVL arvore = NULL;
    int valores[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 65, 77, 90};
    
    printf("Inserindo valores: ");
    for(int i = 0; i < 14; i++) {
        int valor = valores[i];
        struct NO* novo = cria_no(valor);
        if(arvore == NULL) {
            arvore = novo;
        } else {
            struct NO* atual = arvore;
            struct NO* pai = NULL;
            
            while(atual != NULL) {
                pai = atual;
                if(valor < atual->info) {
                    atual = atual->esq;
                } else {
                    atual = atual->dir;
                }
            }
            
            if(valor < pai->info) {
                pai->esq = novo;
            } else {
                pai->dir = novo;
            }
            
            novo->alt = 0;
            pai->alt = maior(alt_NO(pai->esq), alt_NO(pai->dir)) + 1;
        }
        printf("%d ", valor);
    }
    printf("\n\n");
    
    printf("Arvore completa - Pre-ordem: ");
    preOrdem_ArvAVL(arvore);
    printf("\n");
    printf("Arvore completa - Em-ordem: ");
    emOrdem_ArvAVL(arvore);
    printf("\n\n");
    
    printf("Removendo 5 (folha)...\n");
    remove_ArvAVL_Iterativo(&arvore, 5);
    printf("Apos remocao - Pre-ordem: ");
    preOrdem_ArvAVL(arvore);
    printf("\n");
    printf("Apos remocao - Em-ordem: ");
    emOrdem_ArvAVL(arvore);
    printf("\n\n");
    
    printf("Removendo 25 (um filho)...\n");
    remove_ArvAVL_Iterativo(&arvore, 25);
    printf("Apos remocao - Pre-ordem: ");
    preOrdem_ArvAVL(arvore);
    printf("\n");
    printf("Apos remocao - Em-ordem: ");
    emOrdem_ArvAVL(arvore);
    printf("\n\n");
    
    printf("Removendo 50 (dois filhos, raiz)...\n");
    remove_ArvAVL_Iterativo(&arvore, 50);
    printf("Apos remocao - Pre-ordem: ");
    preOrdem_ArvAVL(arvore);
    printf("\n");
    printf("Apos remocao - Em-ordem: ");
    emOrdem_ArvAVL(arvore);
    printf("\n\n");
    
    libera_arvore(arvore);
    
    printf("=== TESTE 2: CASOS ESPECIAIS ===\n\n");
    
    printf("Caso 1: Arvore vazia\n");
    ArvAVL arvore_vazia = NULL;
    int removido = remove_ArvAVL_Iterativo(&arvore_vazia, 10);
    printf("Remocao de valor inexistente: %s\n", removido ? "sucesso" : "falhou (esperado)");
    printf("\n");
    
    printf("Caso 2: Uma unica folha\n");
    ArvAVL arvore_single = cria_no(42);
    printf("Antes: ");
    emOrdem_ArvAVL(arvore_single);
    printf("\n");
    remove_ArvAVL_Iterativo(&arvore_single, 42);
    printf("Depois: ");
    if(arvore_single == NULL) printf("(arvore vazia)");
    else emOrdem_ArvAVL(arvore_single);
    printf("\n\n");
    libera_arvore(arvore_single);
    
    printf("Caso 3: Remocao com rotacao\n");
    ArvAVL arvore_rotacao = NULL;
    int vals_rotacao[] = {10, 5, 15, 2, 7, 12, 20, 1, 3, 6, 8, 11, 13, 18, 25};
    printf("Inserindo: ");
    for(int i = 0; i < 15; i++) {
        struct NO* novo = cria_no(vals_rotacao[i]);
        printf("%d ", vals_rotacao[i]);
        if(arvore_rotacao == NULL) {
            arvore_rotacao = novo;
        } else {
            struct NO* atual = arvore_rotacao;
            struct NO* pai = NULL;
            
            while(atual != NULL) {
                pai = atual;
                if(vals_rotacao[i] < atual->info) {
                    atual = atual->esq;
                } else {
                    atual = atual->dir;
                }
            }
            
            if(vals_rotacao[i] < pai->info) {
                pai->esq = novo;
            } else {
                pai->dir = novo;
            }
            
            novo->alt = 0;
            pai->alt = maior(alt_NO(pai->esq), alt_NO(pai->dir)) + 1;
        }
    }
    printf("\nAntes: Em-ordem: ");
    emOrdem_ArvAVL(arvore_rotacao);
    printf("\n");
    
    printf("Removendo 2...\n");
    remove_ArvAVL_Iterativo(&arvore_rotacao, 2);
    printf("Depois: Em-ordem: ");
    emOrdem_ArvAVL(arvore_rotacao);
    printf("\n");
    
    libera_arvore(arvore_rotacao);
    
    return 0;
}
