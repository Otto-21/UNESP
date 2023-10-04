#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
    /*
        ARQUIVO PARA IMPLEMENTAÇÃO DO CÁLCULO DAS FUNÇÕES
        Nesta seção realizamos o método para cálculo da soma dos N termos da função, e também implementamos o valor de cada uma das funções,
        sempre lembrando de realizar uma checagem se não existem valores nulos ou menores que 0
    */
double calculaNPrimeiros(int n, double(*funcao)(int)){
    if(n<=0 || funcao==NULL){
        printf("Parametros errados");
        return 0;
    }
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=funcao(i);
    }
    return sum;
}

double funcao1(int n){
    if(n>=0){
        return 1/(double)((4*n+1)*(4*n+3));
    }
    printf("Numero nulo\n");
    return 0;
}

double funcao2(int n){
    if(n>=0){
        return 1/(double)((n+1)*(n+1));
    }
    printf("Numero nulo\n");
    return 0;
}

double funcao3(int n){
    if(n>=0){
        return 1/(double)((2*n+1)*(2*n+1));
    }
    printf("Numero nulo\n");
    return 0;
}