/*
Nome:                     | RA:
---------------------------------------
Otto Jacometo             | 231150903
Rodrigo Tedeschi Rampazzo | 231153244
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

/*------------------------------------------------------------------------------
    Funções da matriz com ponteiro duplo
------------------------------------------------------------------------------*/

mtz new_mtz(int lin, int col, float init)
/*
    Inicializa mtz.
*/
{
    mtz m;

    if (lin>0 && col>0)
    {
        m.lin = lin; m.col = col;
        //Alocação das linhas: aloca ponteiros simples
        m.data = malloc(lin*sizeof(float *));
        if (m.data!=NULL)
        {
            //Alocação das colunas: aloca variável comum
            for (int i=0; i<lin; i++)
            {
                m.data[i] = malloc(col*sizeof(float));
                if (m.data[i]!=NULL)
                    //Inicialização das entradas
                    for (int j=0; j<col; j++)
                    {
                        m.data[i][j] = init;
                    }
                else
                {
                    printf("Memória insuficiente para alocação.");
                }
            }   
        }
        else
        {
            printf("Memória insuficiente para alocação.");
        }
    }
    else
    {
        m.lin = 0; m.col = 0;
        m.data = NULL;
    }

    return m;
}

bool mtz_is_null(mtz m)
/*
    Checa se alguma das alocações de mtz falhou.
*/
{
    if (m.data==NULL)
    {
        return true;
    }
    for (int i=0; i<m.lin; i++)
        if (m.data[i]==NULL)
        {
            return true;
        }
    return false;
}

void free_mtz(mtz *m)
/*
    Libera memória de mtz. Para cada malloc, é feito um free.
*/
{
    if (m->data!=NULL)
    {
        for (int i=0; i<m->lin; i++)
        {
            if (m->data[i]!=NULL)
            {
                free(m->data[i]);
            }
        }
        free(m->data); 
        m->data = NULL;
    }
}

void mtz_read(mtz m)
/*
    Pede para usuário inserir elementos na matriz.
*/
{
    if (mtz_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
        for (int j=0; j<m.col; j++)
        {
            printf("Digite a entrada [%d,%d]: ",i,j);
            scanf("%f",&m.data[i][j]);
        }
}

void mtz_print(mtz m)
/*
    Imprime na tela os elementos da matriz.
*/
{
    if (mtz_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
    {
        for (int j=0; j<m.col; j++)
        {
            printf("%f ",m.data[i][j]);
        }
        printf("\n");
    }
}

mtz soma_mtz(mtz A, mtz B)
/*
    Soma de duas matrizes
*/
{
    if (!mtz_is_null(A) && !mtz_is_null(B))
    {
        if (A.lin==B.lin && A.col==B.col)
        {
            mtz res = new_mtz(A.lin,A.col,0);
            if (mtz_is_null(res))
            {
                printf("Memória insuficiente para matriz de resultado.");
                return new_mtz(0,0,0);
            }
            for (int i=0; i<A.lin; i++)
                for (int j=0; j<A.col; j++)
                {
                    res.data[i][j] = A.data[i][j]+B.data[i][j];
                }
            return res;
        }
        printf("Matrizes incompatíveis para soma.");
        return new_mtz(0,0,0);
    }
    printf("Matriz de entrada é null.");
    return new_mtz(0,0,0);
}

mtz ppscalar_mtz(mtz A, int esc){
    if(mtz_is_null(A)){                            //verifica se a matriz é nula
        printf("A matriz enviada é nula");
        return new_mtz(0,0,0);                     //retorna uma matriz nula
    }

    mtz M = new_mtz(A.lin,A.col,0);                //cria nova matriz p/ resposta
    for(int i=0; i<A.lin; i++){                    //percorre as linhas
        for(int j=0; j<A.col; j++){                //percorre as colunas
            M.data[i][j] = A.data[i][j] * esc;     //preenche matriz de resposta com multiplicação da célula equivalente de A pelo escalar
        }
    }
    return M;                                      //retorna o produto da matriz
}

mtz mul_mtz(mtz A, mtz B){
    if(mtz_is_null(A) || mtz_is_null(B)){
        printf("Matriz passada e nula");
        return new_mtz(0,0,0);                          //matriz nula pois algum dos parametros é nulo
    }
    
    if(A.col!=B.lin){                                   //verifica a condição de multiplicação
        printf("O numero de colunas das primeira matriz deve ser igual ao numero de linhas da segunda.");
        return new_mtz(0,0,0);                          //matriz nula pois nao atende ao requisito do produto de matrizes
    }

    mtz M = new_mtz(A.lin, B.col, 0);               //cria nova matriz (linhas de A x colunas de B)
    for(int i=0; i<A.lin; i++){                     //percorre as linhas de A
        for(int j=0; j<B.col; j++){                 //precorre as colunas de B
            int soma=0;
            for(int k=0; k<A.col; k++){             //faz o papel do indice da somatoria
                soma+=A.data[i][k]*B.data[k][j];    //somatoria da multiplicação das celulas correspondentes
            }
            M.data[i][j] = soma;                    //atribuicao da somatoria à celula gerada pela operação
        }
    }
    return M;                                       //retorna o resultado da multiplicação
}

mtz transposta_mtz(mtz B){
    if(mtz_is_null(B)){
        printf("Matriz passada e nula");
        return new_mtz(0,0,0);                              //matriz nula pois algum dos parametros é nulo
    }
    
    mtz M = new_mtz(B.col, B.lin, 0);                   //cria matriz com valor de linha e coluna invertidos
    for(int i=0; i<B.lin; i++){                         //percorre as linhas
        for(int j=0; j<B.col; j++){                     //percorre as colunas
            M.data[j][i]=B.data[i][j];                  //transposição da celula
        }
    }
    return M;                                           //retorno da celula transposta
}