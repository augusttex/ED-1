/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 12

*/

#include <stdio.h>

typedef struct {
    int itens[1000];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p) { p->topo = -1; }
void push(Pilha *p, int v) { p->itens[++(p->topo)] = v; }
int pop(Pilha *p) { return p->itens[(p->topo)--]; }
int vazia_pilha(Pilha *p) { return p->topo == -1; }

typedef struct {
    int itens[1000];
    int inicio;
    int fim;
} Fila;

void inicializar_fila(Fila *f) { f->inicio = 0; f->fim = 0; }
void enqueue(Fila *f, int v) { f->itens[(f->fim)++] = v; }
int dequeue(Fila *f) { return f->itens[(f->inicio)++]; }
int vazia_fila(Fila *f) { return f->inicio == f->fim; }

void processar_valor(Pilha *p, int valor) {
    if (valor > 0) {
        push(p, valor);
    } else if (valor < 0) {
        if (!vazia_pilha(p)) {
            pop(p);
        }
    }
}

int main() {
    Fila par, impar;
    Pilha p;
    
    printf("Digite uma sequencia de numeros (termina com 0): ");
    inicializar_fila(&par);
    inicializar_fila(&impar);
    inicializar_pilha(&p);

    int valor;
    while (scanf("%d", &valor) == 1 && valor != 0) {
        if (valor % 2 == 0) {
            enqueue(&par, valor);
        } else {
            enqueue(&impar, valor);
        }
    }

    int turno_impar = 1;

    while (!vazia_fila(&par) || !vazia_fila(&impar)) {
        if (turno_impar) {
            if (!vazia_fila(&impar)) {
                processar_valor(&p, dequeue(&impar));
            }
            turno_impar = 0;
        } else {
            if (!vazia_fila(&par)) {
                processar_valor(&p, dequeue(&par));
            }
            turno_impar = 1;
        }
    }

    while (!vazia_pilha(&p)) {
        printf("%d ", pop(&p));
    }
    printf("\n");

    return 0;
}