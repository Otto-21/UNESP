#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fd;

    char buffer[1000];
    int i, reg;
    char size=0;
    char *pch;

    fd = fopen("campo_var_reg_var.dad", "r+b");
    //fd = fopen("campo_var_reg_var.dad", "r+t");

    //o terceiro tem tamnho 26=ctrl-Z=EOF; então se ler como texto vai dar problema; vai parar de ler no segundo
    //size = fgetc(fd);
    //while (size != EOF) {//tem um que tem tamanho 26 e aí se comparar com EOF é verdade...
    while (fread(&size, sizeof(size), 1, fd)) {   
        fread(buffer, size, 1, fd);
        buffer[size]='\0';
        
		pch = strtok(buffer,"|");
        while (pch != NULL)
         {
           printf("%s ",pch);
           pch = strtok(NULL,"|");
         }
        printf("\n");
        //size = fgetc(fd);
    }


    printf("\n...Pesquisa...\n"); //formato: nº+dados
    printf("Numero do registro: ");
    scanf("%d",&reg);
    fseek(fd, 0, 0);
    fread(&size, sizeof(size), 1, fd);
    for(i=1; i < reg; i++)
     {
        fseek(fd, size, 1);
        fread(&size, sizeof(size), 1, fd);        
     }  
    fread(buffer, size, 1, fd); 
    buffer[size]='\0';
    
	pch = strtok(buffer,"|");   
    while (pch != NULL)
     {
        printf("%s ",pch);
        pch = strtok(NULL,"|");
     }

    fclose(fd);
    getch();
}
