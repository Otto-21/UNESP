#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vetor.h"

/*------------------------------------------------------------------------------
    ALOCAÇÃO E LIBERAÇÃO DE MEMÓRIA
------------------------------------------------------------------------------*/

vetor new_vetor(int n, int init)
/*
    Inicializa um vetor de n elementos com valor init em todas as entradas.
*/
{
    vetor v;
    v.n = n;
    /*
        Veja que tratamos falhas de alocação e entradas inválidas de n como a 
        criação de um vetor NULL. 
    */
    if (n<=0)
    {
        v.data = NULL;
    }
    //Alocação dinâmica
    else
    {
        v.data = malloc(n*sizeof(int));
    }

    if (v.data!=NULL)
    {
        //Inicializa entradas
        for (int i=0; i<v.n; i++)
        {
            v.data[i] = init;
        }
    }
    else
    {
        printf("Falha na alocação dos dados do vetor.");
        v.n = 0;
    }

    return v;
}

void free_vetor(vetor *v)
/*
    Libera memória em um vetor
*/
{
    /*
        OPERADOR -> 
        serve para acessar os elementos de um ponteiro dentro de um struct que
        foi também declarado como ponteiro.
        Utiliza-se u->n ou u->data ao invés de (*u).n ou (*u).data
    */
    if (v->data!=NULL)
    {
        free((*v).data); //Sintaxe alternativa de v->data
        v->data = NULL;
    }
}

bool vetor_is_null(vetor v)
{
    
    if (v.data==NULL)
    {
        return true;
    }
    return false;
}

/*------------------------------------------------------------------------------
    OUTRAS FUNÇÕES
------------------------------------------------------------------------------*/

vetor soma_vetores(vetor u, vetor v)
/*
    Retorna o vetor resultado da soma de u e v.
*/
{
    vetor out;
    //Checa se u e v são compatíveis e não são null
    if (!vetor_is_null(u) && !vetor_is_null(v))
    {
        if(u.n==v.n)
        {
            //Calcula soma
            out = new_vetor(u.n,0);
            if (!vetor_is_null(out))
            {
                for (int i=0; i<u.n; i++)
                {
                    out.data[i] = u.data[i] + v.data[i];
                }
            }
            else
            {
                printf("Falha na alocação para vetor de saída.");
            }
        }
        else
        {
            printf("Vetores incompatíveis para soma.");
            out = new_vetor(0,0);
        }
    }
    else
    {
        printf("Vetor de entrada é NULL.");
        out = new_vetor(0,0);
    }
    return out;
}

vetor ppscalar_vetor(vetor u, float p)
/*
    Retorna o vetor resultado do produto de u pelo escalar p.
*/
{
    vetor out;
    //Checa se u e v são compatíveis e não são null
    if (!vetor_is_null(u))
    {
        out = new_vetor(u.n,0);
        if (!vetor_is_null(out))
        {
            //calcula vetor de saída
            for (int i=0; i<u.n; i++)
            {
                out.data[i] = p*u.data[i];
            }
        }
        else
        {
            printf("Falha na alocação do vetor de saída.");
        }
    }
    else
    {
        printf("Vetor de entrada é NULL.");
        out = new_vetor(0,0);
    }

    return out;
}

void vetor_read(vetor v)
/*
    Pede para usuário inserir elementos do vetor.
*/
{
    for (int i=0; i<v.n; i++)
    {
        printf("Digite a entrada %d do vetor: ",i);
        scanf("%d",&v.data[i]);
    }
}

void vetor_print(vetor v)
/*
    Imprime as entradas do vetor na tela.
*/
{
    for (int i=0; i<v.n; i++)
    {
        printf("%d ",v.data[i]);
    }
}