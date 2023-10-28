#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

pol polFromFile(char *filename){
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Erro ao abrir arquivo.");
        return newPol(0);
    }

    float vCoef[100];
    int i=0;

    while (!feof(fp)){
        fscanf(fp, "%f", &vCoef[i]);
        //printf("%d: %f\n",i, vCoef[i]);
        i++;
    }
    fclose(fp);

    pol p = newPol(i);
    if (polIsNull(p)){
        printf("Erro ao criar o polinomio\n");
        return p;
    }

    carregaPol(p, vCoef);

    return p;
}


void carregaPol(pol p, float *v){
    if(p.coef==NULL){                           //verifica se o polinomio nao e nulo
        printf("Polinômio nulo. // carregaPol()/");
    }
    else{
        for(int i=0; i<p.grau; i++){
            p.coef[i]=v[i];
        }
    }
}

pol newPol(int g){
    pol p;
    if(g>0){
        p.grau=g;
        p.coef=malloc(g*sizeof(float));         //Alocação única
        if (p.coef!=NULL){
            for (int i=0; i<p.grau; i++)        //Inicialização das entradas
            {
                p.coef[i] = 0;
            }
        }
        else{
            printf("Memória insuficiente para alocação. //newPol()");
        }
    }
    else{
        p.grau=0;
        p.coef=NULL;
        //printf("Parâmetro inválido. //newPol()");
    }
    return p;
}

void printaPol(pol p){
    if(polIsNull(p)){                           //verifica se o polinomio nao e nulo
        printf("Polinômio nulo. // printaPol()");
    }
    else{
        printf("\np(x) = %.2f + ",p.coef[0]);
        for(int i=1; i<p.grau;i++){
            if(p.coef[i]!=0){
                printf("(%.2f)*x^%d",p.coef[i],i);
                if(i+1<p.grau)
                    printf(" + ");
            }
        }
        //printf("\n");
    }
}

bool polIsNull(pol p)
{
    return p.coef==NULL;                        //verifica se o vetor de coeficientes é nulo
}

float funcao(pol p, float z){
    float res=0;                                //resultado de p(z)

    if(!polIsNull(p) && p.grau>0){              //verifica se o polinomio possui coeficientes e tamanho (se é valido)
        for(int i=0; i<p.grau; i++){           //percorre os coeficientes do polinomio, servindo também de expoente de z
            res+= p.coef[i] * pow(z, i);       //soma ao resultado o produto entre o coeficiente e z elevado à i-esima potencia 
        }
    }
    else{
        printf("Polinomio invalido. // funcao()");
    }

    return res;                         //retorna o resultado;
}

void freePol(pol *p)                    //libera o vetor de coeficiente do polinomio
{
    if (p->coef!=NULL)
    {
        free(p->coef);
        p->coef = NULL;
        printf("\nMemória liberada.");
    }
}

pol somaPol(pol p1, pol p2, bool sub){
    pol res;
    if(polIsNull(p1) || polIsNull(p2)){         //verifica se os polinomios sao validos
        printf("Polinômios inválidos. // somaPol()");
        res=newPol(0);
    }
    else{
        int i;
        pol p= newPol(p2.grau);                     //cria um polinomio novo para poder mexer nos coeficientes livremente

        if(sub){
            for(i=0; i<p.grau;i++){
                p.coef[i]=(-1)*p2.coef[i];             //se a operação desejada for subtração, o polinomio p2 terá seus coeficientes multiplicados por -1
                //printf("%f\n",p.coef[i]);
            }
        }
        else
            carregaPol(p,p2.coef);

        if(p1.grau >= p2.grau){                   //o vetor de coef do polinomio resultante deve ter o mesmo tamanho que o maior vetor entre os dois polinomios
            res=newPol(p1.grau);
        }
        else{
            res=newPol(p2.grau);
        }

        for(i=0; i<p1.grau && i<p2.grau; i++){                  //soma todos os coeficientes correspondentes de x de mesmo grau 
            res.coef[i]=p1.coef[i]+p.coef[i];         //percorre os vetores coef de p1 e p2 com graus correspondentes
        }

        if(p1.grau < p2.grau){                    //como G(p1)<G(p2) o vetor de coeficientes de p2 é maior que o de p1, portanto o vetor coef do polinomio resultante terá os coeficientes restantes de p2 transcritos em si
            for(i=p1.grau; i<p.grau; i++){       //percorre o restante do vetor coef de p2
                res.coef[i]=p.coef[i];
            }        
        }
        else if(p1.grau > p2.grau){               //como G(p1)>G(p2) o vetor de coeficientes de p1 é maior que o de p2, portanto o vetor coef do polinomio resultante terá os coeficientes restantes de p1 transcritos em si
            for(i=p2.grau; i<p1.grau; i++){       //percorre o restante do vetor coef de p1
                res.coef[i]=p1.coef[i];
            }   
        }
    }
    return res;
}

pol prodPol(pol p1, pol p2){
    pol res;
    if(polIsNull(p1) || polIsNull(p2)){         //verifica se os polinomios sao validos
        printf("Polinômios inválidos. // prodPol()");
        res=newPol(0);
    }
    else{
        res= newPol(p1.grau+p2.grau-1);
        for(int i=0; i<p1.grau; i++){
            for(int j=0; j<p2.grau; j++){
                res.coef[i+j]+=p1.coef[i]*p2.coef[j];                   //formula produto entre polinomios
            }
        }
    }
    return res;
}

pol derivaPol(pol p){
    pol d;
    if(polIsNull(p)){         //verifica se o polinomio e valido
        printf("Polinômio inválido. // derivaPol()");
        d=newPol(0);
    }
    else{
        d=newPol(p.grau-1);                     //derivada sempre perde 1 grau de polinomio
        for(int i=0; i<p.grau; i++){                            
            d.coef[i] = (i+1)*p.coef[i+1];                          //formula derivada de polinomios
            //printf("%d * %f = %f\n",i,p.coef[i],i*p.coef[i]);
        }
    }
    return d;
}

pol integraIndefPol(pol p, float c){
    pol res;
    if(polIsNull(p)){         //verifica se o polinomio e valido
        printf("Polinômio inválido. // integraIndefPol()");
        res=newPol(0);
    }
    else{
        res= newPol(p.grau+1);
        res.coef[0]=c;
        for(int i=0; i<p.grau; i++){
            res.coef[i+1] = (p.coef[i])/(i+1);
            //printf("%f / %d = %f\n",p.coef[i],i+1,p.coef[i]/(i+1));
        }
    }
    return res;
}

float integraDefPol(pol p, float sup, float inf){
    float res=0;
    if(polIsNull(p)){         //verifica se o polinomio e valido
        printf("Polinômio inválido. // integraDefPol()");
        res=newPol(0);
    }
    else{
        if(sup<inf){            //se o limite superior for menor que o inferior, inverte-se os valores
            sup+=inf;
            inf=sup-inf;
            sup=sup-inf;
        }

        res=funcao(integraIndefPol(p,0),sup)-funcao(integraIndefPol(p,0),inf);
    }
    return res;

}

float newtonRaphson(pol p, float xZero, int tmax, float e){
    float res=0, ant=0, rMaisProx=xZero;

    if(polIsNull(p)){         //verifica se o polinomio e valido
        printf("Polinômio inválido. // newtonRaphson()");
        return res;
    }
    else if(tmax<=0 || e<=0){       //verifica e>0 e tmax>0
        printf("Parâmetros não atendem às condições básicas. // newtonRaphson()");
        return res;
    }
    else{
        ant=xZero;
        for(int i=0; i<tmax; i++){              //iterações limitadas pelo parametro max
            res = ant - funcao(p, ant)/funcao(derivaPol(p), ant);
            //printf("\nres:%f   ant:%f === f(res):%f   f(ant):%f", res,ant,funcao(p,res),funcao(p,ant));

            if(fabs(res - ant) < e){                                 //encontrou a raiz dentro do estimado
                printf("Raíz encontrada em %d iterações.\n", i+1);
                return res;
            }
            else{
                if(fabs(funcao(p,rMaisProx)) > fabs(funcao(p,res))){  //armazena qual o x mais proximo de 0, enquanto nao acha a raiz.
                    //printf("\np(%f) > p(%f) === %f > %f",rMaisProx,res,fabs(funcao(p,rMaisProx)),fabs(funcao(p,res)));
                    rMaisProx=res;
                }
                ant=res;
            }
        }
        printf("Raíz não encontrada nos parâmetros definidos.\n");
        return rMaisProx;               //raiz nao encontrada, retorna o valor mais proximo
    }
}