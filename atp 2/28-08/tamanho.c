#include<stdlib.h>
#include<stdio.h>

int main(){
    printf("Tamanho das variáveis (em bytes):\n");
    printf("%ld \n", sizeof(int));
    printf("%ld \n", sizeof(int*));
    printf("%ld \n", sizeof(char));
    printf("%ld \n", sizeof(char*));
    printf("%ld \n", sizeof(float));
    printf("%ld \n", sizeof(float*));
    return 0;
}