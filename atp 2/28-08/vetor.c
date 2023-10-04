#include<stdlib.h>
#include<stdio.h>

int main(){
    char b='x';
    //a variavel a recebe o endereco de b. Ou a aponta para b.
    char *a=&b;

    printf("%c \n",b);
    printf("%c \n",*a);
    //%p imprime endereco na tela
    printf("%p \n", &b);
    printf("%p \n",a);

    return 0;
}