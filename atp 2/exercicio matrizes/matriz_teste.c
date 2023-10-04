#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "matriz_seq.h"

int main()
{
    
    printf("Digite os números de linhas e colunas da matriz: ");
    int lin, col;
    scanf("%d %d",&lin,&col);
    mtz A = new_mtz(lin,col,0);
    mtz_print(A);
    mtz_read(A);
    mtz_print(A);

    printf("Digite os números de linhas e colunas da segunda matriz: ");
    scanf("%d %d",&lin,&col);
    mtz B = new_mtz(lin,col,0);
    mtz_read(B);
    mtz_print(B);

    printf("Soma das matrizes: \n");
    mtz S = soma_mtz(A,B);
    mtz_print(S);

    /*
    printf("Digite os números de linhas e colunas da matriz: ");
    int lin, col;
    scanf("%d %d",&lin,&col);
    mtzseq A = new_mtz(lin,col,0);
    mtzseq_print(A);
    mtzseq_read(A);
    mtzseq_print(A);

    printf("Digite os números de linhas e colunas da segunda matriz: ");
    scanf("%d %d",&lin,&col);
    mtzseq B = new_mtzseq(lin,col,0);
    mtzseq_read(B);
    mtzseq_print(B);

    printf("Soma das matrizes: \n");
    mtzseq S = soma_mtzseq(A,B);
    mtzseq_print(S);
    */
    return 0;
}