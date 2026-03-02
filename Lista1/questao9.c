/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 9
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    float v[10];
    for(int i = 0; i < 10; i++) {
        float *x = &v[i];
        printf("v[%d] = %p\n", i, x);
    }
    return 0;
}