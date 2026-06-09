/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 13

Funcao: Verifica se uma ABB e estritamente binaria (todos os nos tem 0 ou 2 filhos)

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

int eh_estritamente_binaria(struct NO* raiz) {
    if(raiz == NULL)
        return 1;
    
    int tem_esq = (raiz->esq != NULL);
    int tem_dir = (raiz->dir != NULL);
    
    if(tem_esq != tem_dir)
        return 0;
    
    if(!tem_esq && !tem_dir)
        return 1;
    
    return eh_estritamente_binaria(raiz->esq) &&
           eh_estritamente_binaria(raiz->dir);
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
    printf("=== TESTE 1: Arvore ESTRITAMENTE BINARIA ===\n\n");
    
    ArvBin *arv1 = cria_ArvBin();
    insere_ArvBin_Busca(arv1, 50);
    insere_ArvBin_Busca(arv1, 30);
    insere_ArvBin_Busca(arv1, 70);
    insere_ArvBin_Busca(arv1, 20);
    insere_ArvBin_Busca(arv1, 40);
    insere_ArvBin_Busca(arv1, 60);
    insere_ArvBin_Busca(arv1, 80);
    
    printf("Arvore 1 (em ordem): ");
    imprime_inOrdem(*arv1);
    printf("\n");
    printf("Estrutura:\n");
    printf("          50\n");
    printf("         /  \\\n");
    printf("       30    70\n");
    printf("      / \\   / \\\n");
    printf("    20 40 60 80\n\n");
    
    if(eh_estritamente_binaria(*arv1))
        printf("Resultado: ESTRITAMENTE BINARIA\n\n");
    else
        printf("Resultado: NAO E ESTRITAMENTE BINARIA\n\n");
    
    printf("=== TESTE 2: Arvore NAO ESTRITAMENTE BINARIA (um filho) ===\n\n");
    
    struct NO* arv2 = cria_no(50);
    arv2->esq = cria_no(30);
    arv2->dir = cria_no(70);
    arv2->esq->esq = cria_no(20);
    
    printf("Arvore 2 (em ordem): ");
    imprime_inOrdem(arv2);
    printf("\n");
    printf("Estrutura:\n");
    printf("        50\n");
    printf("       /  \\\n");
    printf("     30    70\n");
    printf("    /\n");
    printf("  20\n\n");
    printf("(No 30 tem apenas filho esquerdo!)\n\n");
    
    if(eh_estritamente_binaria(arv2))
        printf("Resultado: ESTRITAMENTE BINARIA\n\n");
    else
        printf("Resultado: NAO E ESTRITAMENTE BINARIA\n\n");
    
    printf("=== TESTE 3: Arvore COM FOLHAS (valida) ===\n\n");
    
    struct NO* arv3 = cria_no(50);
    arv3->esq = cria_no(30);
    arv3->dir = cria_no(70);
    arv3->esq->esq = cria_no(20);
    arv3->esq->dir = cria_no(40);
    arv3->dir->esq = cria_no(60);
    arv3->dir->dir = cria_no(80);
    
    printf("Arvore 3 (em ordem): ");
    imprime_inOrdem(arv3);
    printf("\n");
    printf("Estrutura:\n");
    printf("          50\n");
    printf("         /  \\\n");
    printf("       30    70\n");
    printf("      / \\   / \\\n");
    printf("    20 40 60 80\n\n");
    
    if(eh_estritamente_binaria(arv3))
        printf("Resultado: ESTRITAMENTE BINARIA\n\n");
    else
        printf("Resultado: NAO E ESTRITAMENTE BINARIA\n\n");
    
    printf("=== TESTE 4: Arvore SO COM RAIZ (um no) ===\n\n");
    
    struct NO* arv4 = cria_no(50);
    
    printf("Arvore 4 (em ordem): ");
    imprime_inOrdem(arv4);
    printf("\n");
    printf("Estrutura: so a raiz (folha)\n\n");
    
    if(eh_estritamente_binaria(arv4))
        printf("Resultado: ESTRITAMENTE BINARIA (uma folha e valida)\n\n");
    else
        printf("Resultado: NAO E ESTRITAMENTE BINARIA\n\n");
    
    printf("=== TESTE 5: Arvore VAZIA ===\n\n");
    
    struct NO* arv5 = NULL;
    
    printf("Arvore 5: vazia\n\n");
    
    if(eh_estritamente_binaria(arv5))
        printf("Resultado: ESTRITAMENTE BINARIA (arvore vazia e valida)\n");
    else
        printf("Resultado: NAO E ESTRITAMENTE BINARIA\n");
    
    libera_arvore(arv2);
    libera_arvore(arv3);
    libera_arvore(arv4);
    
    return 0;
}
