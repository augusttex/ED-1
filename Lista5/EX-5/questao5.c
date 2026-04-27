/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 5

*/

#include <stdio.h>
#include <string.h>

char pilha[100];
int topo = -1;

void push(char c) { pilha[++topo] = c; }
char pop() { return pilha[topo--]; }

int palindromo(char *palavra) {
    int tamanho = strlen(palavra);
    topo = -1;
    
    for (int i = 0; i < tamanho; i++) {
        push(palavra[i]);
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] != pop()) {
            return 0; 
        }
    }
    
    return 1; 
}