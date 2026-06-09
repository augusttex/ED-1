/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 14

Funcao: Versao recursiva de insercao, remocao e busca em ABB

*/ 

#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

struct NO* cria_no(int valor) {
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL) {
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

struct NO* insere_recursivo(struct NO* raiz, int valor) {
    if(raiz == NULL) {
        return cria_no(valor);
    }
    
    if(valor < raiz->info) {
        raiz->esq = insere_recursivo(raiz->esq, valor);
    }
    else if(valor > raiz->info) {
        raiz->dir = insere_recursivo(raiz->dir, valor);
    }
    
    return raiz;
}

struct NO* busca_recursiva(struct NO* raiz, int valor) {
    if(raiz == NULL)
        return NULL;
    
    if(valor == raiz->info)
        return raiz;
    
    if(valor < raiz->info)
        return busca_recursiva(raiz->esq, valor);
    else
        return busca_recursiva(raiz->dir, valor);
}

struct NO* encontra_minimo(struct NO* raiz) {
    if(raiz->esq == NULL)
        return raiz;
    return encontra_minimo(raiz->esq);
}

struct NO* remove_recursivo(struct NO* raiz, int valor) {
    if(raiz == NULL)
        return NULL;
    
    if(valor < raiz->info) {
        raiz->esq = remove_recursivo(raiz->esq, valor);
    }
    else if(valor > raiz->info) {
        raiz->dir = remove_recursivo(raiz->dir, valor);
    }
    else {
        if(raiz->esq == NULL) {
            struct NO* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if(raiz->dir == NULL) {
            struct NO* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        
        struct NO* minimo_dir = encontra_minimo(raiz->dir);
        raiz->info = minimo_dir->info;
        raiz->dir = remove_recursivo(raiz->dir, minimo_dir->info);
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

void imprime_preOrdem(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    printf("%d ", raiz->info);
    imprime_preOrdem(raiz->esq);
    imprime_preOrdem(raiz->dir);
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    printf("=== TESTE 1: INSERCAO RECURSIVA ===\n\n");
    
    struct NO* arv = NULL;
    
    printf("Inserindo valores: 50, 30, 70, 20, 40, 60, 80\n");
    arv = insere_recursivo(arv, 50);
    arv = insere_recursivo(arv, 30);
    arv = insere_recursivo(arv, 70);
    arv = insere_recursivo(arv, 20);
    arv = insere_recursivo(arv, 40);
    arv = insere_recursivo(arv, 60);
    arv = insere_recursivo(arv, 80);
    
    printf("Em ordem: ");
    imprime_inOrdem(arv);
    printf("\n");
    printf("Pre-ordem: ");
    imprime_preOrdem(arv);
    printf("\n\n");
    
    printf("=== TESTE 2: BUSCA RECURSIVA ===\n\n");
    
    int valores_busca[] = {40, 25, 60, 100};
    for(int i = 0; i < 4; i++) {
        struct NO* resultado = busca_recursiva(arv, valores_busca[i]);
        printf("Busca por %d: ", valores_busca[i]);
        if(resultado != NULL)
            printf("ENCONTRADO\n");
        else
            printf("NAO ENCONTRADO\n");
    }
    
    printf("\n=== TESTE 3: REMOCAO RECURSIVA ===\n\n");
    
    printf("Arvore antes (em ordem): ");
    imprime_inOrdem(arv);
    printf("\n\n");
    
    printf("Removendo 20 (folha)...\n");
    arv = remove_recursivo(arv, 20);
    printf("Apos remocao: ");
    imprime_inOrdem(arv);
    printf("\n\n");
    
    printf("Removendo 30 (um filho)...\n");
    arv = remove_recursivo(arv, 30);
    printf("Apos remocao: ");
    imprime_inOrdem(arv);
    printf("\n\n");
    
    printf("Removendo 50 (dois filhos - raiz)...\n");
    arv = remove_recursivo(arv, 50);
    printf("Apos remocao: ");
    imprime_inOrdem(arv);
    printf("\n\n");
    
    printf("=== TESTE 4: INSERCAO E REMOCAO COMBINADAS ===\n\n");
    
    struct NO* arv2 = NULL;
    
    int valores[] = {15, 10, 20, 5, 12, 17, 25};
    printf("Inserindo: ");
    for(int i = 0; i < 7; i++) {
        arv2 = insere_recursivo(arv2, valores[i]);
        printf("%d ", valores[i]);
    }
    printf("\n");
    printf("Em ordem: ");
    imprime_inOrdem(arv2);
    printf("\n\n");
    
    printf("Removendo: 5, 12, 25\n");
    arv2 = remove_recursivo(arv2, 5);
    arv2 = remove_recursivo(arv2, 12);
    arv2 = remove_recursivo(arv2, 25);
    printf("Apos remocoes: ");
    imprime_inOrdem(arv2);
    printf("\n");
    
    libera_arvore(arv);
    libera_arvore(arv2);
    
    return 0;
}
