#include<stdio.h>
#include<conio.h>
#include<string>

#define MAX 10

int main() {
    FILE *fd;
    
    struct endereco {
        char nome[15];
        char sobrenome[15];
        char rua[26];
        int numero;
    };
    
    struct endereco end[MAX], temp;
    int i,reg;
    
    fd = fopen("fixo.dad", "r+b");

    fread(end, sizeof(end), 1, fd);    

    for (i=0; i<MAX; i++) {
        printf("%s %s %s %d\n", end[i].nome, end[i].sobrenome, end[i].rua, end[i].numero);
    }        

    printf("...Pesquisa...\n");
    printf("Numero do registro: ");
    scanf("%d",&reg);
    fseek(fd, sizeof(endereco)*(reg-1), 0);
    fread(&temp, sizeof(endereco), 1, fd);    
    printf("%s %s %s %d\n", temp.nome, temp.sobrenome, temp.rua, temp.numero);    
    
    fclose(fd);

    getch();
}
