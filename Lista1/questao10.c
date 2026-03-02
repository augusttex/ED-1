/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 10
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    float v[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                float *x = &v[i][j];
                printf("v[%d][%d] = %p\n", i, j, x);
            }
        }

    return 0;
}