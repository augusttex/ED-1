/*Nome: Augusto Castilho
Matrícula: 54880
Lista: 7
Exercício: 20

Funcao: Arvore de municipios com dados completos

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AREA_BRASIL 8514876.0

struct Municipio {
    char nome[100];
    double area;
    int populacao;
};

struct NO {
    struct Municipio dados;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

struct NO* cria_no(char* nome, double area, int populacao) {
    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL) {
        strcpy(novo->dados.nome, nome);
        novo->dados.area = area;
        novo->dados.populacao = populacao;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

struct NO* insere_municipio(struct NO* raiz, char* nome, double area, int populacao) {
    if(raiz == NULL) {
        return cria_no(nome, area, populacao);
    }
    
    int cmp = strcmp(nome, raiz->dados.nome);
    
    if(cmp < 0) {
        raiz->esq = insere_municipio(raiz->esq, nome, area, populacao);
    }
    else if(cmp > 0) {
        raiz->dir = insere_municipio(raiz->dir, nome, area, populacao);
    }
    
    return raiz;
}

struct NO* busca_municipio(struct NO* raiz, char* nome) {
    if(raiz == NULL)
        return NULL;
    
    int cmp = strcmp(nome, raiz->dados.nome);
    
    if(cmp == 0)
        return raiz;
    else if(cmp < 0)
        return busca_municipio(raiz->esq, nome);
    else
        return busca_municipio(raiz->dir, nome);
}

int contar_municipios(struct NO* raiz) {
    if(raiz == NULL)
        return 0;
    
    return 1 + contar_municipios(raiz->esq) + contar_municipios(raiz->dir);
}

void listar_em_ordem(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    listar_em_ordem(raiz->esq);
    printf("%-30s | Area: %10.2f km2 | Pop: %10d | Densidade: %8.2f hab/km2\n",
        raiz->dados.nome,
        raiz->dados.area,
        raiz->dados.populacao,
        raiz->dados.populacao / raiz->dados.area);
    listar_em_ordem(raiz->dir);
}

void cidades_por_populacao(struct NO* raiz, int minimo) {
    if(raiz == NULL)
        return;
    
    cidades_por_populacao(raiz->esq, minimo);
    
    if(raiz->dados.populacao > minimo) {
        printf("- %s (Pop: %d)\n", raiz->dados.nome, raiz->dados.populacao);
    }
    
    cidades_por_populacao(raiz->dir, minimo);
}

void calcular_densidade_demografica(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    calcular_densidade_demografica(raiz->esq);
    
    double densidade = raiz->dados.populacao / raiz->dados.area;
    printf("%-30s: %8.2f hab/km2\n", raiz->dados.nome, densidade);
    
    calcular_densidade_demografica(raiz->dir);
}

void calcular_percentual_area(struct NO* raiz, double* area_total) {
    if(raiz == NULL)
        return;
    
    calcular_percentual_area(raiz->esq, area_total);
    *area_total += raiz->dados.area;
    calcular_percentual_area(raiz->dir, area_total);
}

void encontrar_maior_populacao(struct NO* raiz, struct Municipio* maior) {
    if(raiz == NULL)
        return;
    
    encontrar_maior_populacao(raiz->esq, maior);
    
    if(raiz->dados.populacao > maior->populacao) {
        strcpy(maior->nome, raiz->dados.nome);
        maior->populacao = raiz->dados.populacao;
        maior->area = raiz->dados.area;
    }
    
    encontrar_maior_populacao(raiz->dir, maior);
}

void libera_arvore(struct NO* raiz) {
    if(raiz == NULL)
        return;
    
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main() {
    struct NO* arvore = NULL;
    
    printf("=== CADASTRO DE MUNICIPIOS ===\n\n");
    
    arvore = insere_municipio(arvore, "Sao Paulo", 1521.0, 11895893);
    arvore = insere_municipio(arvore, "Rio de Janeiro", 1197.0, 6747815);
    arvore = insere_municipio(arvore, "Brasilia", 5779.0, 3108637);
    arvore = insere_municipio(arvore, "Salvador", 692.0, 2857329);
    arvore = insere_municipio(arvore, "Fortaleza", 313.0, 2676507);
    arvore = insere_municipio(arvore, "Belo Horizonte", 331.0, 2397068);
    arvore = insere_municipio(arvore, "Manaus", 11401.0, 2219580);
    arvore = insere_municipio(arvore, "Curitiba", 435.0, 1963726);
    arvore = insere_municipio(arvore, "Recife", 218.0, 1655149);
    arvore = insere_municipio(arvore, "Porto Alegre", 497.0, 1417080);
    
    printf("(a) CONTAR MUNICIPIOS:\n");
    printf("Total de municipios cadastrados: %d\n\n", contar_municipios(arvore));
    
    printf("(e) MUNICIPIOS EM ORDEM ALFABETICA:\n");
    listar_em_ordem(arvore);
    printf("\n");
    
    printf("(b) CIDADES COM MAIS DE 2.000.000 HABITANTES:\n");
    cidades_por_populacao(arvore, 2000000);
    printf("\n");
    
    printf("(c) DENSIDADE DEMOGRAFICA:\n");
    calcular_densidade_demografica(arvore);
    printf("\n");
    
    printf("(d) PERCENTUAL DE AREA EM RELACAO AO BRASIL:\n");
    double area_total = 0.0;
    calcular_percentual_area(arvore, &area_total);
    double percentual = (area_total / AREA_BRASIL) * 100;
    printf("Area total dos municipios: %.2f km2\n", area_total);
    printf("Percentual em relacao ao Brasil: %.4f%%\n\n", percentual);
    
    printf("(f) CIDADE COM MAIOR POPULACAO:\n");
    struct Municipio maior = {"", 0, 0};
    encontrar_maior_populacao(arvore, &maior);
    printf("Nome: %s\n", maior.nome);
    printf("Area: %.2f km2\n", maior.area);
    printf("Populacao: %d\n", maior.populacao);
    printf("Densidade: %.2f hab/km2\n", maior.populacao / maior.area);
    
    libera_arvore(arvore);
    
    return 0;
}
