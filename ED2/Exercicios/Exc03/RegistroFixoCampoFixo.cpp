#include<stdio.h>
#include<conio.h>
#include<string>

#define MAX 10 //o total de registros no arquivo fixo.dad é 10

int main(){
	FILE *arq;
	
	typedef struct {
		char nome[15];
		char sobrenome[15];
		char rua[26];
		int numero;
	} Endereco;
	
	Endereco end[MAX]; //um vetor para armazenar todos os endereços do arquivo
	int reg;
	
	arq= fopen("fixo.dad", "r+b"); //abre para leitura + escrita em binario. cria o arquivo se nao exsitir
	
	fread(end, sizeof(end), 1, arq);//atribui à end 10 enderecos (sizeof(end) * 1) do arquivo arq
	
	//percorre o vetor e printa os valores salvos anteriormente
	for(int i=0; i<MAX; i++){
		printf("%2d - %s %s - %s %d\n", i+1, end[i].nome, end[i].sobrenome, end[i].rua, end[i].numero);
	}
	
	printf(".....Pesquisa.....\n");
    printf("Numero do registro: ");
    scanf("%d",&reg);
    
    Endereco temp; //armazena o registro pesquisado
    fseek(arq, sizeof(Endereco)*(reg-1), 0); //procura o registro (ex: se for o 5º, pula espaço de memória de 4 registros e pega o próximo)
    fread(&temp, sizeof(Endereco), 1, arq); //carrega o registro na variavel
    printf("%s %s - %s %d\n", temp.nome, temp.sobrenome, temp.rua, temp.numero);
    
	fclose(arq); //fecha o arquivo

    getch();
}
