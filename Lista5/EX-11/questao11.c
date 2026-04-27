/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 11

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

int main() {
    Pilha p;
    inicializar(&p);
    printf("Digite o numero de termos da sequencia de Fibonacci: ");
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    
    if (n >= 1) push(&p, 0);
    if (n >= 2) push(&p, 1);
    
    int a = 0, b = 1, proximo;
    for (int i = 2; i < n; i++) {
        proximo = a + b;
        push(&p, proximo);
        a = b;
        b = proximo;
    }
    
    while (!vazia(&p)) {
        printf("%d ", pop(&p));
    }
    printf("\n");
    
    return 0;
}