#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[15];
	char sobrenome[15];
	char endereco[26];
	int numero;
}Endereco;

int main(){
	FILE *arq;
	
	Endereco end;
	int reg, i=1;
	char buffer[1000];
	char *pch; //pesquisa char
	
	arq=fopen("campo_var_reg_fixo.dad","r+b");
	
	while(fread(buffer, sizeof(Endereco), 1, arq)){ //enquanto nao for nulo a atribuicao ao buffer da leitura
	//do tamanho de um struct no arquivo, continua
		printf("%2d - ", i++);
		pch = strtok(buffer,"|");	//atribui a pch o primeiro campo, delimitado por "|"
        while (pch != NULL){
           printf("%s ",pch);
           pch = strtok(NULL,"|");
        }
        printf("\n");
	}
	
	printf("...Pesquisa...\n");
    printf("Numero do registro: ");
    scanf("%d",&reg);
    fseek(arq, sizeof(Endereco)*(reg-1), 0); //fseek(arquivo, lugar para direcionar a leitura, origem)
    fread(buffer, sizeof(Endereco), 1, arq);
      
    pch = strtok(buffer,"|");
    while (pch != NULL)
         {
           printf("%s ",pch);
           pch = strtok(NULL,"|");
         }   
    
    fclose(arq);
	getch();
    
}
