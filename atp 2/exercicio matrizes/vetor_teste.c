#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vetor.h"

int main()
{

    printf("Digite o tamanho do primeiro vetor: ");
    int n;
    scanf("%d",&n);
    vetor v = new_vetor(n,0);
    vetor_read(v);
    vetor_print(v);
    printf("\n");

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d",&n);
    vetor u = new_vetor(n,0);
    vetor_read(u);
    vetor_print(u);
    printf("\n");

    vetor soma = soma_vetores(u,v);
    printf("Vetor soma: ");
    vetor_print(soma);
    
    free_vetor(&v);
    free_vetor(&u);

    return 0;
}