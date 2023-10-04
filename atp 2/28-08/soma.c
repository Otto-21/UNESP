#include<stdlib.h>
#include<stdio.h>
float soma(float *x,int n){

    if(x==NULL){
        printf("vetor inserido nulo.");
        return 0;
    }
    float sum=0;

    //Inicializa um ponteiro para iterar sobre os elementos de x. x aponta para seu primeiro elemento. Iteramos ate que aux aponte para o endereco do ultimo elemento de x.
    for(float *aux=x; aux<=&x[n-1];aux++){
        //adiciona valor de aux a sum
        sum+=*aux;
    }
    return sum;
}

int main(){
    float x[8]={1,4,5.5,6,7,8.012,96,12};
    printf("%f\n",soma(x,8));
    return 0;
}