/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 13
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char n1[15];
    char n2[15];
    


    printf("Digite a primeira string: ");
    fgets(n1, sizeof(n1), stdin);
    n1[strcspn(n1, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("Digite a segunda string: ");
    fgets(n2, sizeof(n2), stdin);
    n2[strcspn(n2, "\n")] = '\0';
    setbuf(stdin, NULL);

    char *x = n1;
    char *y = n2;

     if(strstr(x, y) != NULL)
     {
        printf("\nA string [%s] esta contida na string [%s]\n", y, x);
     }
     else
     {
        printf("\nA string [%s] nao esta contida na string [%s]\n", y, x);
     }
    
   
    return 0;


}