#include<stdlib.h>
#include<stdio.h>

int main(){
    char b='x';
    char *a=&b;
    //ponteiro duplo: indirecao multipla
    char **p=NULL;

    //Modificacao indireta de b. Indirecao simples
    *a='t';
    printf("%c\n",b);

    //Modificacao indireta de b. Indirecao multipla
    p=&a;
    **p='g';
    printf("%c\n",b);
    return 0;
}