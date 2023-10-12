#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

/*pol new_pol(char *s){
    FILE *fp= fopen(s, 'r');
    if (fp==NULL)
    {
        printf("Não foi possível abrir o arquivo.");
    }
    else{
        int i[],j=0;
        fscanf(fp, "%d",i[j])
        while(!feof(fp)){
            j++;
            fscanf(fp,"%d",i[j])
        }
    }
}*/

pol newPol(int g){
    pol p;
    if(t>0){
        p.grau=g;
        p.coef=malloc(g*sizeof(float));         //Alocação única
        if (p.coef!=NULL){
            for (int i=0; i<p.grau; i++)        //Inicialização das entradas
            {
                p.coef[i] = 0;
            }
        }
        else{
            printf("Memória insuficiente para alocação.");
        }
    }
    else{
        p.grau=0;
        p.coef=NULL;
    }
    return p;
}

bool polIsNull(pol p)
{
    return p.coef==NULL;                        //verifica se o vetor de coeficientes é nulo
}

float funcao(pol *p, float z){
    float res=0;                                //resultado de p(z)

    if(polIsNull(p) && p->grau>0){              //verifica se o polinomio possui coeficientes e tamanho (se é valido)
        for(int i=0; i<p->grau; i++){           //percorre os coeficientes do polinomio, servindo também de expoente de z
            tot+= p->coef[i] * pow(z, i);       //soma ao resultado o produto entre o coeficiente e z elevado à i-esima potencia 
        }
    }
    else{
        printf("Polinomio invalido")
    }

    return res;                         //retorna o resultado;
}

void freePol(pol *p)                    //libera o vetor de coeficiente do polinomio
{
    if (!polIsNull(p))
    {
        free(p->coef);
        p->coef = NULL;
    }
}

pol somaPol(pol *p1, pol *p2){
    pol res;
    if(polIsNull(p1) || polIsNull(p2)){         //verifica se os polinomios sao validos
        printf("Polinômios inválidos.");
        res=newPol(0);
    }
    else{
        int i;

        if(p1->grau >= p2->grau){                   //o vetor de coef do polinomio resultante deve ter o mesmo tamanho que o maior vetor entre os dois polinomios
            res=newPol(p1->grau);
        }
        else{
            res=newPol(p2->grau);
        }

        for(i=0; i<p1->grau; i++){                  //soma todos os coeficientes correspondentes de x de mesmo grau 
            res[i]=p1->coef[i]+p2->coef[i];         //percorre os vetores coef de p1 e p2 com graus correspondentes
        }

        if(p1->grau < p2->grau){                    //como G(p1)<G(p2) o vetor de coeficientes de p2 é maior que o de p1, portanto o vetor coef do polinomio resultante terá os coeficientes restantes de p2 transcritos em si
            for(i=p1->grau; i<p2->grau; i++){       //percorre o restante do vetor coef de p2
                res[i]=p2->coef[i];
            }        
        }
        else if(p1->grau > p2->grau){               //como G(p1)>G(p2) o vetor de coeficientes de p1 é maior que o de p2, portanto o vetor coef do polinomio resultante terá os coeficientes restantes de p1 transcritos em si
            for(i=p2->grau; i<p1->grau; i++){       //percorre o restante do vetor coef de p1
                res[i]=p1->coef[i];
            }   
        }
    }
    return res;
}