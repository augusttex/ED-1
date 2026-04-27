/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 7

*/

#include <stdio.h>

int pilha[100];
int topo = -1;

void push(int v) { pilha[++topo] = v; }
int pop() { return pilha[topo--]; }
int vazia() { return topo == -1; }

void ordenar() {
    int pilha_aux[100];
    int topo_aux = -1;

    while (!vazia()) {
        int temp = pop();

        while (topo_aux != -1 && pilha_aux[topo_aux] > temp) {
            push(pilha_aux[topo_aux--]);
        }

        pilha_aux[++topo_aux] = temp;
    }

    while (topo_aux != -1) {
        push(pilha_aux[topo_aux--]);
    }
}

int main() {
    push(34);
    push(3);
    push(31);
    push(98);
    push(92);
    push(23);

    ordenar();

    while (!vazia()) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}