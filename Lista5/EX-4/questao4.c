/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 4

*/

#include <stdio.h>

char pilha[100];
int topo = -1;

void push(char c) { pilha[++topo] = c; }
char pop() { return pilha[topo--]; }
int vazia() { return topo == -1; }

int main() {
    char c;
    printf("Digite uma frase (termina com '.'): ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c != ' ' && c != '.') {
            push(c); 
        } else {
            while (!vazia()) {
                putchar(pop());
            }
            putchar(c); 
            
            if (c == '.') break; 
        }
    }
    return 0;
}