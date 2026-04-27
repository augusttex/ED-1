/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 14

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

void converter(int num, int base) {
    Pilha p;
    inicializar(&p);
    
    if (num == 0) {
        printf("0\n");
        return;
    }

    while (num > 0) {
        push(&p, num % base);
        num /= base;
    }

    while (!vazia(&p)) {
        int resto = pop(&p);
        if (resto < 10) {
            printf("%d", resto);
        } else {
            printf("%c", 55 + resto);
        }
    }
    printf("\n");
}

int main() {
    int num, opcao;
    
    printf("Digite o numero: ");
    if (scanf("%d", &num) != 1) return 0;

    printf("1: Binario\n2: Octal\n3: Hexadecimal\nOpcao: ");
    if (scanf("%d", &opcao) != 1) return 0;

    if (opcao == 1) {
        converter(num, 2);
    } else if (opcao == 2) {
        converter(num, 8);
    } else if (opcao == 3) {
        converter(num, 16);
    }

    return 0;
}