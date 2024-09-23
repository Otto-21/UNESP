#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *arq;

    char buffer[1000];
    int i=1, reg;
    char tam=0;
    char *pch;

    arq = fopen("campo_var_reg_var.dad", "r+b");
	
	while (fread(&tam, sizeof(tam), 1, arq)) {//armazena em tam o primeiro byte do arquivo, que indica
	//o tamanho do registro que o sucede
		printf("%2d - ", i++);
	
		fread(buffer, tam, 1, arq);
        buffer[tam]='\0';
		pch = strtok(buffer,"|");
        while(pch != NULL){
           printf("%s ",pch);
           pch = strtok(NULL,"|");
         }
        printf("\n");
	}
	
	printf("\n...Pesquisa...\n"); //formato: nº+dados
    printf("Numero do registro: ");
    scanf("%d",&reg);
    fseek(arq, 0, 0);//volta para o inicio do arquivo
    
    fread(&tam, sizeof(tam), 1, arq);//atribui o valor de bytes do registro a seguir
    for(i=1; i < reg; i++){ //roda até o inicio do i-ésimo registro, salvando o tamanho dele
        fseek(arq, tam, 1);
        fread(&tam, sizeof(tam), 1, arq);        
    }
	
	fread(buffer, tam, 1, arq); //carrega o registro solicitado
    buffer[tam]='\0';  
	
	pch = strtok(buffer,"|");   
    while (pch != NULL){
        printf("%s ",pch);
        pch = strtok(NULL,"|");
     }
	
	fclose(arq);
	getch();
}
