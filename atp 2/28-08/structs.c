#include<stdlib.h>
#include<stdio.h>

typedef struct //criacao
{
    int rg;
    char *nome;
} pessoa;

int main(){
    pessoa prof;
    prof.rg=1234565;
    prof.nome="Emilio Bergamim Junior";

    printf("Nome do prof: %s \nEsse nao e o RG do prof: %d \n",prof.nome,prof.rg);
    return 0;
}