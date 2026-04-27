/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 9

*/

#include <stdio.h>

typedef struct {
    int itens[100];
    int topo;
} Pilha;

void inicializar(Pilha *p) { p->topo = -1; }
void push(Pilha *p, int v) { p->itens[++(p->topo)] = v; }
int pop(Pilha *p) { return p->itens[(p->topo)--]; }
int vazia(Pilha *p) { return p->topo == -1; }

void copiar_pilha(Pilha *p1, Pilha *p2) {
    Pilha aux;
    inicializar(&aux);
    inicializar(p2);

    while (!vazia(p1)) {
        push(&aux, pop(p1));
    }

    while (!vazia(&aux)) {
        int valor = pop(&aux);
        push(p1, valor);
        push(p2, valor);
    }
}

int main() {
    Pilha p1, p2;
    inicializar(&p1);
    
    push(&p1, 10);
    push(&p1, 20);
    push(&p1, 30);

    copiar_pilha(&p1, &p2);

    while (!vazia(&p2)) {
        printf("%d ", pop(&p2));
    }
    printf("\n");

    return 0;
}