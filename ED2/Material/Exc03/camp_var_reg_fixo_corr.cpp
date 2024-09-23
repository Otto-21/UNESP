#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct endereco {
    char nome[15];
    char sobrenome[15];
    char rua[26];
    int numero;
};

int main() {
    FILE *fd;
    
    struct endereco end;
    char buffer[1000];
    int i, reg;
    char *pch;
    
    fd = fopen("campo_var_reg_fixo.dad", "r+b"); 
    
    while(fread(buffer, sizeof(end), 1, fd))
    {  
		pch = strtok(buffer,"|");
        while (pch != NULL)
         {
           printf("%s ",pch);
           pch = strtok(NULL,"|");
         }
        printf("\n");
    }    
    
    printf("...Pesquisa...\n");
    printf("Numero do registro: ");
    scanf("%d",&reg);
    fseek(fd, sizeof(endereco)*(reg-1), 0);
    fread(buffer, sizeof(endereco), 1, fd);    
    pch = strtok(buffer,"|");
    while (pch != NULL)
         {
           printf("%s ",pch);
           pch = strtok(NULL,"|");
         }   
    
    fclose(fd);

    getch();
}
