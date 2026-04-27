/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 5 
Exercício: 6

*/

#include <stdio.h>

char pilha[100];
int topo = -1;

void push(char c) { pilha[++topo] = c; }
char pop() { return pilha[topo--]; }
int vazia() { return topo == -1; }

int verifica_parenteses(char *expressao) {
    topo = -1; 
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            push('(');
        } 
        else if (expressao[i] == ')') {
            if (vazia()) {
                return 0; 
            }
            pop(); 
        }
    }
    
    return vazia(); 
}

int main() {
    char* testes[] = {
        "( ( ) )", 
        "( ( )( ) )", 
        "( ) ( )", 
        ")(", 
        "( ( ) (", 
        ") ) ( ("
    };

    for (int i = 0; i < 6; i++) {
        if (verifica_parenteses(testes[i])) {
            printf("%s -> Correto\n", testes[i]);
        } else {
            printf("%s -> Incorreto\n", testes[i]);
        }
    }

    return 0;
}