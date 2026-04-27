/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 10

*/

#include <stdio.h>

typedef struct {
    int itens[100];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p) { p->topo = -1; }
void push(Pilha *p, int v) { p->itens[++(p->topo)] = v; }
int pop(Pilha *p) { return p->itens[(p->topo)--]; }
int vazia_pilha(Pilha *p) { return p->topo == -1; }

typedef struct {
    int itens[100];
    int inicio;
    int fim;
} Fila;

void inicializar_fila(Fila *f) { f->inicio = 0; f->fim = 0; }
void enqueue(Fila *f, int v) { f->itens[(f->fim)++] = v; }
int dequeue(Fila *f) { return f->itens[(f->inicio)++]; }
int vazia_fila(Fila *f) { return f->inicio == f->fim; }

void inverter_fila(Fila *f, Pilha *p) {
    while (!vazia_fila(f)) {
        push(p, dequeue(f));
    }
    
    while (!vazia_pilha(p)) {
        enqueue(f, pop(p));
    }
}

int main() {
    Fila f;
    Pilha p;
    
    inicializar_fila(&f);
    inicializar_pilha(&p);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    enqueue(&f, 40);

    inverter_fila(&f, &p);

    while (!vazia_fila(&f)) {
        printf("%d ", dequeue(&f));
    }
    printf("\n");

    return 0;
}