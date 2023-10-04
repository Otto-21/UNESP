#include<stdio.h>
#include<stdlib.h>
#include "vetorMod.h"
int main(){
    float data[8]={4,2,7,7,9,13,68,1};
    vetor v=newVetor(data,8);

    ordena(v,menor);
    printf("Vetor ordenado de forma crescente: ");
    imprimeVetor(v);
    printf("\n");

    ordena(v,maior);
    printf("Vetor ordenado de forma decrescente: ");
    imprimeVetor(v);

    return 0;
}