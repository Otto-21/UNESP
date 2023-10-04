#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vetorMod.h" //inclui o cabeçalho

vetor newVetor(float *data, int n){
    vetor v;
    v.data=data;
    v.n=n;
    return v;
}
float somaVetor(vetor v){
    if (v.data!=NULL && v.n>0)
    {
        float soma = 0;
        for (int i=0; i<v.n; i++)
        {
            soma += v.data[i];
        }
        return soma;
    }
    printf("Vetor não possui nenhum elemento.");
    return 0;
}

void imprimeVetor(vetor v){
    for (int i=0; i<v.n; i++)
    {
        printf("%f ",v.data[i]);
    }
}

int menor(float x, float y){
    if(x<y){
        return 1;
    }
    return 0;
}

int maior(float x, float y){
    if(x>y){
        return 1;
    }
    return 0;
}

void troca(vetor v, int i, int j){
    float aux=v.data[i];
    v.data[i]=v.data[j];
    v.data[j]=aux;
}

void ordena(vetor v, int (*compara)(float, float)){
    //itera sobre os elementos de v
    for(int i=0;i<v.n;i++){
        //Procura pelo extremo na fatia v[i:n]
        int index=i;
        for(int j=i+1;j<v.n;j++){
            if(compara(v.data[j],v.data[index])==1){
                index=j;
            }
        }
        troca(v,i,index);
    }
}