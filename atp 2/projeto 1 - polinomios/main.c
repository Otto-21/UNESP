#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "polinomio.h"


int main(){

    char arqPol[100];
    pol p1,p2;
    p1.coef=NULL;
    p2.coef=NULL;


    while (p1.coef == NULL) {      //repete enquanto nao carregar o polinomio
        printf("Insira o nome da .txt para leitura:");
        scanf("%s", arqPol);
        //printf("\n%s\n",arqPol);
        p1 = polFromFile(arqPol);
    }
    printf("Leitura concluída com êxito.\n");
    

    printf("\nPrimeiro polinomio:");
    printaPol(p1);
    printf("\n\n");
    pol dP1=derivaPol(p1);
    printf("Derivada do primeiro polinomio:");
    printaPol(dP1);
    printf("\n\n");


   while (p2.coef == NULL) {      //repete enquanto nao carregar o polinomio
        printf("Insira o nome da .txt para leitura:");
        scanf("%s", arqPol);
        //printf("\n%s\n",arqPol);
        p2 = polFromFile(arqPol);
    }
    printf("Leitura concluída com êxito.\n");
    

    printf("\nSegundo polinomio:");
    printaPol(p2);
    printf("\n\n");
    pol dP2=derivaPol(p2);
    printf("Derivada do segundo polinomio:");
    printaPol(dP2);
    printf("\n\n");


    pol p3=somaPol(p1,p2,false);
    printf("Soma dos polinomios:");
    printaPol(p3);
    printf("\n\n");


    p3=somaPol(p1,p2,true);
    printf("Subtração dos polinomios:");
    printaPol(p3);
    printf("\n\n");


    pol p4=prodPol(p1,p2);
    printf("Produto dos polinomios:");
    printaPol(p4);
    printf("\n\n");


    int c=0;
    printf("Entre com a constante para calcular-se a integral indefinida dos polinômios.\n");
    scanf("%d",&c);
    printf("\nIntegral indefinida do polinomio 1:");
    pol p5=integraIndefPol(p1,c);
    printaPol(p5);
    printf("\n\n");
    printf("Integral indefinida do polinomio 2:");
    p5=integraIndefPol(p2,c);
    printaPol(p5);
    printf("\n\n");


    int inf,sup;
    printf("Entre com o limite inferior e superior, respectivamente, para calcular-se a integral definida dos polinômios.\n");
    scanf("%d %d",&inf,&sup);
    printf("\nIntegral definida do primeiro polinomio: %.2f\n",integraDefPol(p1,inf,sup));
    printf("Integral definida do segundo polinomio: %.2f",integraDefPol(p2,inf,sup));
    printf("\n\n");


    int tmax;
    float xZero, e;
    printf("Digite os parâmetros para o método de Newton Raphson.\nValor inicial de x: ");
    scanf("%f", &xZero);
    printf("Valor de precisão numerica de epsilon: ");
    scanf("%f", &e);
    printf("Numero maximo de iterações: ");
    scanf("%d", &tmax);

    printf("\nUma raiz do primeiro polinomio é (aproximadamente): %f",newtonRaphson(p1, xZero, tmax, e));
    printf("\n\n");
    printf("Uma raiz do segundo polinomio é (aproximadamente): %f\n",newtonRaphson(p2, xZero, tmax, e));

    freePol(&p1);
    freePol(&p2);
    return 0;
}