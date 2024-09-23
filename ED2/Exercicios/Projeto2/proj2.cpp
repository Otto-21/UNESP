//Otto Jacometo
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char idAluno[4]; //4 bytes
	char siglaDisc[4]; //4 bytes
	char nomeAluno[50]; //maximo 50 bytes
	char nomeDisc[50]; //maximo 50 bytes
	float media; //4 bytes
	float frequecia; //4 bytes
} HISTORICO; 

typedef struct{
    char idAluno[4]; //4 bytes
	char siglaDisc[4]; //4 bytes
    int offset;
} INDICE_P;

void carregarHistorico(char *nomeArquivoInicial, char *nomeArquivoNovo){
	FILE *insere;
	HISTORICO h;
	FILE *novo;
    FILE *arq;
	char registro[100];
	int tam, offset=-1;

    arq= fopen("lista.bin", "wb");
	
	insere = fopen(nomeArquivoInicial, "r+b");
	novo = fopen(nomeArquivoNovo, "w+b"); //arquivo novo com a lista
	
	if(insere!=NULL){
		fwrite(&offset, sizeof(int), 1, novo);
		while(fread(&h, sizeof(HISTORICO), 1, insere) > 0){ //carrega o registro
			sprintf(registro, "%s#%s#%s#%s#%.1f#%.1f",h.idAluno,h.siglaDisc,h.nomeAluno,h.nomeDisc,h.media,h.frequecia);
			tam=strlen(registro);
			fwrite(&tam, sizeof(int), 1, novo);
			fwrite(registro, sizeof(char), tam, novo);
		}
		printf("\nArquivo carregado.");
	}

    
	fclose(arq);
	fclose(novo);
	fclose(insere);
}

void carregarBuscaPrim(char *nomeArquivoInicial, char *nomeArquivoNovo){
    FILE *insere;
    FILE *novo;
    FILE *arq;
    int offset=-1;
    char idAluno[4], siglaDisc[4];

    arq = fopen("indicePrimario.bin", "wb");

    insere = fopen(nomeArquivoInicial, "r+b");
	novo = fopen(nomeArquivoNovo, "w+b"); //arquivo novo com a lista

    if(insere!=NULL){
		fwrite(&offset, sizeof(int), 1, novo);
        //carrega o registro
		while(fread(&idAluno, sizeof(char), 4, insere) > 0 && fread(&siglaDisc, sizeof(char), 4, insere) > 0){ 
			fwrite(&idAluno, sizeof(char), 4, novo);
			fwrite(&siglaDisc, sizeof(char), 4, novo);
		}
		printf("\nArquivo carregado.");
	}
	
    fclose(arq);
	fclose(novo);
	fclose(insere);
}

void carregarBuscaSec(char *nomeArquivoInicial, char *nomeArquivoNovo){
    FILE *insere;
	FILE *novo;
    FILE *arq;
	char nome[50];
	int tam, offset=-1;

    arq = fopen("indiceSecundario.bin", "wb");
	
	insere = fopen(nomeArquivoInicial, "r+b");
	novo = fopen(nomeArquivoNovo, "w+b"); //arquivo novo com a lista
	if(insere!=NULL){
        fwrite(&offset, sizeof(int), 1, novo);
        while(fread(&nome, sizeof(char), 50, insere)){
            tam=strlen(nome);
            fwrite(&tam, sizeof(int), 1, novo);
            fwrite(&nome, sizeof(char), tam, novo);
        }
        printf("\nArquivo carregado.");
    }
	
	fclose(novo);
	fclose(insere);
}

void atualizarIndicePrimario(char *nomeArqIndice, char *nomeArqLista){
    FILE *arq, *lista;
    int tamanho, offset=0;
    char buffer[250], idAluno[4], siglaDisc[4];
    
    arq=fopen(nomeArqIndice, "r+b");
    lista=fopen(nomeArqLista, "r+b");

    if(arq==NULL || lista==NULL){
        printf("\nArquivo(s) nulo(s).");
    }
    else{
        while(fread(&tamanho, sizeof(int), 1, lista) > 0){
            fread(&buffer, sizeof(char), tamanho, lista);
            buffer[tamanho]='\0';

            strcpy(idAluno, strtok(buffer, "#"));
            idAluno[3]='\0';
            fwrite(&idAluno, sizeof(char), 4, arq);

            strcpy(siglaDisc, strtok(NULL, "#"));
            siglaDisc[3]='\0';
            fwrite(&siglaDisc, sizeof(char), 4, arq);
            
            fwrite(&offset, sizeof(int), 1, arq);

            offset += tamanho+sizeof(int); //tamanho do registro + bytes para tamanho (soma -> saber o offset)
            //indice = idAluno + siglaDisc + offsetDoRegistro 
        }
        printf("\nLista de indice primario atualizada.");
    }

    fclose(arq);
    fclose(lista);
}

void inserirLista(char *lista, char *insert, int quantidade){
    FILE *arq, *listaInsert;
    int offset=0, tamanho=0, offsetNovo=0;
    char buffer[250];

    arq= fopen(lista, "r+b");
	listaInsert= fopen(insert, "r+b");

    if(arq==NULL || listaInsert==NULL){
        printf("\nArquivo(s) nulo(s).");
    }
    else{
        fread(&offset, sizeof(int), 1, listaInsert);
        if(offset>-1){
            fseek(listaInsert, offset, 0);
            offsetNovo=offset;
        }
        else
            offsetNovo=4;
        for(int i=0; i < quantidade; i++){
            if(fread(&tamanho, sizeof(int), 1, listaInsert) > 0){
                if(fread(&buffer, sizeof(char), tamanho, listaInsert) > 0){
                    fwrite(&tamanho, sizeof(int), 1, arq);
                    fwrite(&buffer, sizeof(char), tamanho, arq);
                    offsetNovo+=tamanho+4; //tamanho do registro + bytes pertencente ao tamanho
                }
                else
                    printf("\nErro ao ler registro.");
            }
            else
                printf("\nErro ao ler tamanho do registro.");
        }
        fseek(listaInsert, 0, 0);
        fwrite(&offsetNovo, sizeof(int), 1, listaInsert);
        printf("\nRegistro(s) inserido(s).");
    }

    fclose(listaInsert);
	fclose(arq);
}

void intercala (INDICE_P *indice, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    INDICE_P L[n1], R[n2];

    // Copiando dados para arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = indice[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = indice[m + 1 + j];

    // Mesclando os arrays temporários de volta em arr[l..r]
    int i = 0; // Índice inicial de L[]
    int j = 0; // Índice inicial de R[]
    int k = l; // Índice inicial do array mesclado

    while (i < n1 && j < n2) {
        if(atoi(L[i].idAluno) < atoi(R[j].idAluno)){//id1 < id2
            indice[k] = L[i];
            i++;
        }
        else{
            if(atoi(L[i].idAluno) > atoi(R[j].idAluno)){//id1 > id2
                indice[k] = R[j];
                j++;
            }
            else{ //Id iguais
                if(atoi(L[i].siglaDisc) <= atoi(R[j].siglaDisc)){//sigla1 <= sigla2
                    indice[k] = L[i];
                    i++;
                }
                else{//sigla1 > sigla2
                    indice[k] = R[j];
                    j++;
                }
            }
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        indice[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        indice[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(INDICE_P *indice, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordena a primeira e a segunda metades
        mergeSort(indice, l, m);
        mergeSort(indice, m + 1, r);

        // Mescla as duas metades ordenadas
        intercala(indice, l, m, r);
    }
    
}

INDICE_P * carregarIndicePrimario(char *nomeArqIndice, int * totalIndiceP){
    INDICE_P *indice;
    FILE *arq;
    int offset, contador=0;
    char idAluno[4], siglaDisc[4];
    indice = (INDICE_P *) malloc(sizeof(INDICE_P) * 250);

    arq= fopen(nomeArqIndice, "r+b");

    if(arq==NULL){
        printf("\nArquivo nulo.");
    }
    else{
        if(indice==NULL){
            printf("\nErro ao alocar memória.");
        }
        else{
            while(fread(&idAluno, sizeof(char), 4, arq) > 0){
                fread(&siglaDisc, sizeof(char), 4, arq);
                fread(&offset, sizeof(int), 1, arq);
                
                strcpy(indice[contador].idAluno, idAluno);
                strcpy(indice[contador].siglaDisc, siglaDisc);
                indice[contador].offset= offset;

                contador++;
            }
            *totalIndiceP= contador;
            printf("\nIndice primario carregado para memoria.");
        }
    }
    fclose(arq);

    mergeSort(indice, 0 , contador-1);

    printf("\nIndice ordenado:\n");
    for(int i=0; i<contador; i++){
        printf("\n%s - %s - %d", indice[i].idAluno, indice[i].siglaDisc, indice[i].offset);
    }
    return indice;
}



int main(){
//considerar o offset desde a posição 0 nos arquivos
    int qtd=0,op=-1, totalIndicePrimario=0;
    INDICE_P *indice;

	printf("\n================================\n");
	printf("\tProjeto 2 - ED2");
	printf("\n    Manipulação de Arquivos");
	printf("\n================================\n");
	printf("\n1) Carregar Arquivos (lista, busca primaria e secundaria).");
	printf("\n2) Inserir registro(s).");
	printf("\n3) Busca por chave primaria.");
	printf("\n4) Busca por chave secundaria.");
    printf("\n5) Carregar indice primário.");
	printf("\n0) Sair.");
	do{
		printf("\n\n================================\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("\nRealizado por: Otto Jacometo.\n");
				break;
			case 1:
				carregarHistorico("insere.bin", "insereRegistros.bin");
                carregarBuscaPrim("busca_p.bin", "buscaPrim.bin");
                carregarBuscaSec("busca_s.bin", "buscaSec.bin");
				break;
			case 2:
                printf("Deseja inserir quantos registros? ");
                scanf("%d", &qtd);
                inserirLista("lista.bin", "insereRegistros.bin", qtd);
                atualizarIndicePrimario("indicePrimario.bin", "lista.bin");
                indice= carregarIndicePrimario("indicePrimario.bin", &totalIndicePrimario);
				break;
			case 3:
				break;
			case 4:
				break;
            case 5:
                indice= carregarIndicePrimario("indicePrimario.bin", &totalIndicePrimario);
                break;
			default:
				printf("Opcao invalida.");
		}
		getchar();
	}while(op!=0);
}