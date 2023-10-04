/*
Gabriel Dos Santos Severo
Marcus Vinicius De Oliveira Silva
Otto Jacometo
Rodrigo Tedeschi Rampazzo
*/

#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    //while para certificar que nao passarao parametros errados, mesmo que haja tratamento no codigo.
    int n=0;
    do{
    printf("Digite quantos primeiros n termos devem ser somados.\n");
    scanf("%d",&n);
    }while(n<=0);
    /*
        INTRODUÇÃO DOS DADOS PARA CÁLCULO DE FUNÇÕES
        Aqui declaramos três variáveis, passando para o método "calculaNPrimeiros" o número de iterações e cada uma das funções.
    */
    double nFuncUm=calculaNPrimeiros(n,funcao1);
    double nFuncDois=calculaNPrimeiros(n,funcao2); 
    double nFuncTres=calculaNPrimeiros(n,funcao3);
    printf("Soma dos %d primeiros termos da\nFuncao 1: %f\nFuncao 2: %f\nFuncao 3: %f\n",n,nFuncUm,nFuncDois,nFuncTres);
}