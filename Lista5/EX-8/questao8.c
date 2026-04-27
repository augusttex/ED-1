/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 8

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

int pilhas_iguais(Pilha *p1, Pilha *p2) {
    Pilha aux1, aux2;
    inicializar(&aux1);
    inicializar(&aux2);
    int iguais = 1;

    while (!vazia(p1) && !vazia(p2)) {
        int v1 = pop(p1);
        int v2 = pop(p2);
        push(&aux1, v1);
        push(&aux2, v2);

        if (v1 != v2) {
            iguais = 0;
            break;
        }
    }

    if (!vazia(p1) || !vazia(p2)) {
        iguais = 0;
    }

    while (!vazia(&aux1)) {
        push(p1, pop(&aux1));
    }
    while (!vazia(&aux2)) {
        push(p2, pop(&aux2));
    }

    return iguais;
}

int main() {
    Pilha p1, p2;
    inicializar(&p1);
    inicializar(&p2);

    push(&p1, 10);
    push(&p1, 20);
    push(&p1, 30);

    push(&p2, 10);
    push(&p2, 20);
    push(&p2, 30);

    if (pilhas_iguais(&p1, &p2)) {
        printf("Iguais\n");
    } else {
        printf("Diferentes\n");
    }

    return 0;
}