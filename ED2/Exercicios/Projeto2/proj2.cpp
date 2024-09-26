//Otto Jacometo
//Thiago Uliame

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

typedef struct{
    char idAluno[4];
	char siglaDisc[4];
    int offsetAnterior;
    //todo: int offsetRegistro;
    char nome[50];
} INDICE_S;

void carregarHistorico(char *nomeArquivoInicial, char *nomeArquivoNovo){
    /*
        formata o arquivo de registros (bufferizando-o)
    */

	FILE *insere;
	HISTORICO h;
	FILE *novo;
    FILE *arq;
	char registro[100];
	int tam, offset=-1;

    arq= fopen("lista.bin", "wb");
    fclose(arq);

    arq= fopen("indicePrimario.bin", "wb");
    fclose(arq);

    arq= fopen("indiceSecundarioNomes.bin", "wb");
    fclose(arq);

    arq= fopen("indiceSecundarioListaEncadeada.bin", "wb");
    fclose(arq);
	
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

	fclose(novo);
	fclose(insere);
}

void carregarBuscaPrim(char *nomeArquivoInicial, char *nomeArquivoNovo){
    /*
        formata o arquivo de busca primaria, colocando um offset para saber quais buscas ja foram feitas
    */
    FILE *insere;
    FILE *novo;
    int offset=-1;
    char idAluno[4], siglaDisc[4];

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
	
	fclose(novo);
	fclose(insere);
}

void carregarBuscaSec(char *nomeArquivoInicial, char *nomeArquivoNovo){
    /*
        formata o arquivo de busca secundaria, colocando um offset para saber quais buscas ja foram feitas
    */
    FILE *insere;
	FILE *novo;
	char nome[50];
	int tam, offset=-1;
	
	insere = fopen(nomeArquivoInicial, "r+b");
	novo = fopen(nomeArquivoNovo, "w+b"); //arquivo novo com a lista
	if(insere!=NULL || novo != NULL){
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

void atualizarIndices(char *nomeArqIndiceP, char *nomeArqLista,
INDICE_S *indiceS, int *tamIndiceS, char nomes[][50]){
    /*
        atualiza o arquivo de indice primario
        carrega o vetor de struct de indice secundario e calcula seu tamanho
        e carrega o vetor de nomes
    */
    
    FILE *arqPrimario, *lista;
    int tamanhoBuffer, offset=0, tamNomes=0;
    char buffer[250], idAluno[4], siglaDisc[4];
    *tamIndiceS=0;

    arqPrimario= fopen(nomeArqIndiceP, "w+b");
    lista= fopen(nomeArqLista, "r+b");

    if(arqPrimario==NULL || indiceS==NULL || lista==NULL){
        printf("\nArquivo(s) nulo(s). --atualizarIndices");
    }
    else{
        while(fread(&tamanhoBuffer, sizeof(int), 1, lista) > 0){
            fread(&buffer, sizeof(char), tamanhoBuffer, lista);
            buffer[tamanhoBuffer]='\0';

            strcpy(idAluno, strtok(buffer, "#"));
            idAluno[3]='\0';
            strcpy(indiceS[*tamIndiceS].idAluno, idAluno);
            fwrite(&idAluno, sizeof(char), 4, arqPrimario);

            strcpy(siglaDisc, strtok(NULL, "#"));
            siglaDisc[3]='\0';
            strcpy(indiceS[*tamIndiceS].siglaDisc, siglaDisc);
            fwrite(&siglaDisc, sizeof(char), 4, arqPrimario);

            strcpy(nomes[tamNomes], strtok(NULL, "#"));
            strcpy(indiceS[*tamIndiceS].nome, nomes[tamNomes]);

            indiceS[*tamIndiceS].offsetAnterior= 0;
            
            //todo: indiceS[*tamIndiceS].offsetRegistro= offset;
            fwrite(&offset, sizeof(int), 1, arqPrimario);

            (*tamIndiceS)++;
            tamNomes++;

            offset += tamanhoBuffer+sizeof(int); //tamanho do registro + bytes para tamanho (soma -> saber o offset)
            //indiceP = idAluno + siglaDisc + offsetDoRegistro 
        }
        printf("\nLista de indice primario atualizada.");
    }

    fclose(arqPrimario);
    fclose(lista);
}

int inserirLista(char *lista, char *insert, int quantidade){
    FILE *arq, *listaInsert;
    int offset=0, tamanho=0, offsetNovo=0;
    char buffer[250];
    int retorno=0;

    arq= fopen(lista, "r+b");
	listaInsert= fopen(insert, "r+b");

    if(arq==NULL || listaInsert==NULL){
        printf("\nArquivo(s) nulo(s). -- inserirLista");
        fclose(listaInsert);
        fclose(arq);
        return 0;
    }
    else{
        fseek(arq, 0, SEEK_END);
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
                else{
                    //printf("\nErro ao ler registro.");
                    fclose(listaInsert);
                    fclose(arq);
                    return 0;
                }
            }
            else{
                //printf("\nErro ao ler tamanho do registro.");
                fclose(listaInsert);
                fclose(arq);
                return 0;
            }
        }
        fseek(listaInsert, 0, 0);
        fwrite(&offsetNovo, sizeof(int), 1, listaInsert);
        printf("\nRegistro(s) inserido(s).");
    }

    fclose(listaInsert);
	fclose(arq);
    return 1;
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

void printIndicePrimario(INDICE_P *indice, int tamanho){
    printf("\nIndice primario carregado para memoria:\n");
    for(int i=0; i<tamanho; i++){
        printf("\n%s - %s - %d", indice[i].idAluno, indice[i].siglaDisc, indice[i].offset);
    }
}

INDICE_P * carregarIndicePrimario(char *nomeArqIndice, int *tamanhoIndiceP){
    INDICE_P *indiceP;
    FILE *arq;
    int offset, contador=0;
    char idAluno[4], siglaDisc[4];

    indiceP = (INDICE_P *) malloc(sizeof(INDICE_P) * 100);

    arq= fopen(nomeArqIndice, "r+b");

    if(arq==NULL){
        printf("\nArquivo nulo.");
    }
    else{
        if(indiceP==NULL){
            printf("\nErro ao alocar memória.");
        }
        else{
            while(fread(&idAluno, sizeof(char), 4, arq) > 0){
                fread(&siglaDisc, sizeof(char), 4, arq);
                fread(&offset, sizeof(int), 1, arq);
                
                strcpy(indiceP[contador].idAluno, idAluno);
                strcpy(indiceP[contador].siglaDisc, siglaDisc);
                indiceP[contador].offset= offset;

                contador++;
            }
            *tamanhoIndiceP= contador;
        }
    }
    fclose(arq);

    mergeSort(indiceP, 0 , contador-1);

    printf("\nIndice primario carregado para memoria.");

    return indiceP;
}

void carregarIndiceSecundario(INDICE_S *indiceS, char nomes[][50], int *offsetNomes,
int *tamIndiceSecundario, int *tamNomes){
    FILE *arqNomes, *arqListaEncadeada;
    char buffer[50]; //os nomes podem ter no max 50 bytes + 1 byte de marca + 4 bytes do offset
    int contador=0, tamBuffer=0, aux=0, offset;
    char idAluno[4], siglaDisc[4];

    arqNomes= fopen("indiceSecundarioNomes.bin", "r+b");
    arqListaEncadeada= fopen("indiceSecundarioListaEncadeada.bin", "r+b");

    if(arqNomes!=NULL && arqListaEncadeada!=NULL){
        //carrega o vetor de nomes sem repetição
        while(fread(&tamBuffer, sizeof(int), 1, arqNomes) > 0){
            strcpy(nomes[contador], "");
            
            fread(buffer, tamBuffer, 1, arqNomes);
            buffer[tamBuffer]='\0';
            fread(&aux, sizeof(int), 1, arqNomes);

            strcpy(nomes[contador], buffer);
            offsetNomes[contador++]= aux;
        }
        *tamNomes=contador;

        //carrega o vetor de lista encadeada inversa
        contador=0;
        while(fread(idAluno, sizeof(char), 4, arqListaEncadeada) > 0){
            fread(siglaDisc, sizeof(char), 4, arqListaEncadeada);
            fread(&offset, sizeof(int), 1, arqListaEncadeada);

            strcpy(indiceS[contador].idAluno, idAluno);
            strcpy(indiceS[contador].siglaDisc, siglaDisc);
            indiceS[contador++].offsetAnterior=offset;
        }
        *tamIndiceSecundario= contador;

        for(int i=0; i<*tamNomes; i++){ //copia os nomes aos seus respectivos registros
            int pos=offsetNomes[i]/12;
            do{
                strcpy(indiceS[pos].nome, nomes[i]);
                offset= indiceS[pos].offsetAnterior;
                pos= indiceS[pos].offsetAnterior/12;
            }while(offset>-1);
        }

        /*for(int i=0; i<*tamIndiceSecundario; i++){
            printf("\n%s - %s - %d", indiceS[i].idAluno, indiceS[i].siglaDisc, indiceS[i].offsetAnterior);
        }*/

       printf("\nIndice secundario carregado para memoria (nomes e lista invertida).");
    }
    else{
        printf("\nErro ao criar arquivo(s).");
    }

    fclose(arqNomes);
    fclose(arqListaEncadeada);
    
}

int buscarOffsetIndicePrimario(INDICE_P * indiceP, int tamanho, char idAluno[4], char siglaDisc[4]){
    int left = 0, right = tamanho - 1;

    if(indiceP == NULL){
        return -2;
    }
    else{
        while (left <= right) {
            int middle = left + (right - left) / 2;

            // Verifica se o elemento alvo está no meio
            if((strcmp(indiceP[middle].idAluno, idAluno) == 0) && (strcmp(indiceP[middle].siglaDisc, siglaDisc) == 0)){
                return indiceP[middle].offset;
            }
            else{//se não for o elemento no meio do vetor, compara
                if(strcmp(indiceP[middle].idAluno, idAluno) == 0){  
                    //se o id for igual, entao a disciplina é diferente
                    if (atoi(indiceP[middle].siglaDisc) < atoi(siglaDisc)){
                        //se a sigla procurada for menor, então está mais à esquerda
                        left = middle + 1;
                    }
                    else //se a sigla procurada for maior, então está mais à direita
                        right = middle - 1;
                }
                else{
                    if (atoi(indiceP[middle].idAluno) < atoi(idAluno)){
                        //se o id procurado for menor, então está mais à esquerda
                        left = middle + 1;
                    }
                    else //se o id procurado for maior, então está mais à direita
                        right = middle - 1;
                }
            }
        }
        // Retorna -1 se o alvo não for encontrado
        return -1;
    }
}

void buscarRegistroIndicePrimario(INDICE_P * indiceP, int tamIndicePrimario, char idAluno[4], char siglaDisc[4]){
    int offset=0, tamanhoBuffer;
    FILE *arq;
    char buffer[250], *pch;

    offset= buscarOffsetIndicePrimario(indiceP, tamIndicePrimario, idAluno, siglaDisc);

    if(offset == -1){  
        printf("\nRegistro %s - %s não encontrado.", idAluno, siglaDisc);
    }
    else{
        if(offset >= 0){
            arq= fopen("lista.bin", "r+b");
            if(arq==NULL){
                printf("\nErro ao ler o arquivo.");
            }
            else{
                printf("\n");
                fseek(arq, offset, 0);
                fread(&tamanhoBuffer, sizeof(int), 1, arq);
                fread(buffer, sizeof(char), tamanhoBuffer, arq);
                buffer[tamanhoBuffer]='\0';
                pch= strtok(buffer, "#");
                while (pch != NULL){
                    printf("%s ", pch);
                    pch = strtok(NULL,"#");
                }
                fclose(arq);
            }
        }
        else
            printf("\nO indice não foi carregado para memória, favor verificar.");
    }
}

int removerDuplicatas(char nomes[][50], int tamanho){
    int novoTamanho=0, flagNomeIgual=0, i, j;
    char nomesSemRepeticao[tamanho][50];

    for (i = 0; i < tamanho; i++){
        if(i==0){
            strcpy(nomesSemRepeticao[i], nomes[i]);
            novoTamanho++;
        }
        else{
            for(j=0; j < i; j++){
                if(strcmp(nomesSemRepeticao[j], nomes[i]) == 0){
                    flagNomeIgual=1;
                    break;
                }
            }
            if(!flagNomeIgual){
                strcpy(nomesSemRepeticao[novoTamanho], nomes[i]);
                novoTamanho++;
            }
        }
        flagNomeIgual=0;
    }

    for(int i=0; i < (novoTamanho); i++){
        strcpy(nomes[i], nomesSemRepeticao[i]);
    }

    return novoTamanho;
}

void salvarIndiceSecundario(INDICE_S *indiceS, char nomes[][50], int *offsetNomes,
int tamIndiceSecundario, int tamanhoNomes){
    FILE *arqNomes, *arqListaEncadeada;
    char separador='#';
    int tam=0;

    arqNomes= fopen("indiceSecundarioNomes.bin", "w+b");
    arqListaEncadeada= fopen("indiceSecundarioListaEncadeada.bin", "w+b");
    if(arqNomes!=NULL && arqListaEncadeada!=NULL){
        for(int i=0; i < tamanhoNomes; i++){
            //printf("\n%s - %d", nomes[i], offsetNomes[i]);
            tam=strlen(nomes[i]);
            fwrite(&tam, sizeof(int), 1, arqNomes);
            fwrite(nomes[i], (int) strlen(nomes[i]), 1, arqNomes);
            fwrite(&offsetNomes[i], sizeof(int), 1, arqNomes);
        }
        for(int i=0; i<tamIndiceSecundario; i++){
            fwrite(indiceS[i].idAluno, sizeof(char), 4, arqListaEncadeada);
            fwrite(indiceS[i].siglaDisc, sizeof(char), 4, arqListaEncadeada);
            fwrite(&indiceS[i].offsetAnterior, sizeof(int), 1, arqListaEncadeada);
            //fwrite(&indiceS[i].offsetRegistro, sizeof(int), 1, arqListaEncadeada);
        }
    }
    else{
        printf("\nErro ao criar arquivo(s).");
    }
    fclose(arqNomes);
    fclose(arqListaEncadeada);
}

void calcularOffsetsIndiceSecundario(INDICE_S *indiceS, char nomes[][50], int *offsetNomes,
int tamIndiceSecundario, int tamanhoNomes){
    //cria uma lista encadeada dos registros (com os que tem mesmo nome)
    int aux;

    for(int i=0; i<tamanhoNomes; i++){
        aux=-1;
        for(int j=0; j<tamIndiceSecundario; j++){
            if(strcmp(indiceS[j].nome, nomes[i]) == 0){
                indiceS[j].offsetAnterior= aux;
                aux=j*12; //insere a posição do registro de acordo com o tanto de iterações sem encontrar outro com o mesmo nome
                offsetNomes[i]=aux;
            }
        }
    }
    //salva os dois arquivos de indice secundario
    salvarIndiceSecundario(indiceS, nomes, offsetNomes, tamIndiceSecundario, tamanhoNomes);
}

void buscarRegistroIndiceSecundario(int posicaoVetorNome, INDICE_S *indiceS, INDICE_P * indiceP,
int *offsetNomes, int tamIndicePrimario){
    int offset= offsetNomes[posicaoVetorNome];
    int pos=offset/12;

    printf("\nRegistros encontrados: ");
    do{
        buscarRegistroIndicePrimario(indiceP, tamIndicePrimario, indiceS[pos].idAluno, indiceS[pos].siglaDisc);
        //printf("\nAgora: %d - %s - %s - %s - ", pos, indiceS[pos].nome, indiceS[pos].idAluno, indiceS[pos].siglaDisc);
        offset= indiceS[pos].offsetAnterior;
        pos= indiceS[pos].offsetAnterior/12;
        //printf("offset %d", offset);
    }while(offset>-1);
    printf("\n");
}

int preencherBuscaSecundaria(int *posicao, char nomes[][50], int tamNomes){
    //acha a posição do nome a ser pesquisado no vetor de nomes
    FILE *arq;
    int offset, tamanho;
    char nome[50];
    *posicao=-1;

    arq= fopen("buscaSec.bin", "r+b");

    if(arq==NULL){
        printf("\nFalha ao abrir arquivo.");
        fclose(arq);
        return 0;
    }
    else{
        fread(&offset, sizeof(int), 1, arq);     

        if(offset>-1)
            fseek(arq, offset, 0);
        else
            offset=4;
        
        if(fread(&tamanho, sizeof(int), 1, arq) > 0){
            if(fread(nome, sizeof(char), tamanho, arq)>0){
                nome[tamanho]='\0';
                offset+= 4 + tamanho; //4 bytes de tamanho + tamanho do nome
                printf("\nPesquisando o nome: %s", nome);

                for(int i=0; i < tamNomes; i++){
                    if(strcmp(nomes[i], nome) == 0){
                        *posicao=i;
                        break;
                    }
                }

                fseek(arq, 0, 0);
                fwrite(&offset, sizeof(int), 1, arq);
                fclose(arq);

                if(*posicao>-1)
                    return 1;
                else{
                    printf("\nNome não encontrado.\n");
                    return 0;
                }
            }
        }
        printf("\nLimite máixmo de pesquisas atingido");
        return 0;
    }
}

int preencherBuscaPrimaria(char *idAluno, char *siglaDisc){
    FILE *arq;
    int offset;

    arq= fopen("buscaPrim.bin", "r+b");

    if(arq==NULL){
        printf("\nFalha ao abrir arquivo.");
        fclose(arq);
        return 0;
    }
    else{
        fread(&offset, sizeof(int), 1, arq);
        
        if(offset>-1)
            fseek(arq, offset, 0);
        else
            offset=4;
        
        if(fread(idAluno, sizeof(char), 4, arq)>0 && fread(siglaDisc, sizeof(char), 4, arq)>0){

            offset+=8; //4 bytes p cada
            fseek(arq, 0, 0);
            fwrite(&offset, sizeof(int), 1, arq);
            fclose(arq);
            return 1;
        }
        else{
            printf("\nLimite máixmo de pesquisas atingido");
            return 0;
        }
    }
}

int main(){
//considerar o offset desde a posição 0 nos arquivos
    int qtd=0,op=-1, tamIndicePrimario=0, tamNomes=0, tamIndiceSecundario=0, posicao=-1;
    int offsetNomes[100];
    INDICE_P *indiceP;
    INDICE_S indiceS[100];
    char idAluno[4], siglaDisc[4], nome[50], nomes[100][50];

	printf("\n================================\n");
	printf("\tProjeto 2 - ED2");
	printf("\n    Manipulação de Arquivos");
	printf("\n================================\n");
	printf("\n1) Carregar Arquivos (lista, busca primaria e secundaria).");
	printf("\n2) Inserir registro(s).");
	printf("\n3) Busca por chave primaria.");
	printf("\n4) Busca por chave secundaria.");
    printf("\n5) Carregar indice primário para memória.");
    printf("\n6) Carregar indice secundário para memória.");
	printf("\n0) Sair.");
	do{
		printf("\n\n================================\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);
        fflush(stdin);

		switch(op){
			case 0:
				printf("\nRealizado por: Otto Jacometo e Thiago Uliame.\n");
				break;
			case 1: //formatação dos arquivos
				carregarHistorico("insere.bin", "insereRegistros.bin");
                carregarBuscaPrim("busca_p.bin", "buscaPrim.bin");
                carregarBuscaSec("busca_s.bin", "buscaSec.bin");
                indiceP = NULL;
                tamIndicePrimario=0;
                tamNomes=0;
				break;
			case 2: //inserção, ordenação e carregamento do indice primario
                printf("Deseja inserir quantos registros? ");
                scanf("%d", &qtd);
                if(qtd>0){
                    if(inserirLista("lista.bin", "insereRegistros.bin", qtd) == 1){
                        atualizarIndices("indicePrimario.bin", "lista.bin", indiceS, &tamIndiceSecundario, nomes);
                        indiceP= carregarIndicePrimario("indicePrimario.bin", &tamIndicePrimario);
                        tamNomes = removerDuplicatas(nomes, tamIndicePrimario);
                        calcularOffsetsIndiceSecundario(indiceS, nomes, offsetNomes, tamIndiceSecundario, tamNomes);
                    }
                    else
                        printf("\nNão foi possivel realizar a inserção.");
                }
                else{
                    printf("\nQuantidade invalida.");
                }
                break;
			case 3: //busca indice primario  
                printf("Deseja pesquisar quantos registros da lista de busca por indice primario? ");
                scanf("%d", &qtd);
                if(qtd>0){
                    for(int i=0; i<qtd; i++){
                        if(preencherBuscaPrimaria(idAluno, siglaDisc)){
                            printf("\nPesquisando registro %s - %s", idAluno, siglaDisc);
                            buscarRegistroIndicePrimario(indiceP, tamIndicePrimario, idAluno, siglaDisc);
                            printf("\n");
                        } 
                    }
                }
                //implementacao sem o uso dos arquivos secundarios para busca
                /*printf("\nQual id deseja procurar? ");
                fflush(stdin);
                scanf("%s", idAluno);
                printf("E a sigla? ");
                fflush(stdin);
                scanf("%s", siglaDisc);
                buscarRegistroIndicePrimario(indiceP, tamIndicePrimario, idAluno, siglaDisc);*/

				break;
			case 4: //busca indice secundario
                printf("Deseja pesquisar quantos registros da lista de busca por indice secundario? ");
                scanf("%d", &qtd);
                if(qtd>0){
                    for(int i=0; i<qtd; i++){
                        if(preencherBuscaSecundaria(&posicao, nomes, tamNomes))
                            buscarRegistroIndiceSecundario(posicao, indiceS, indiceP, offsetNomes, tamIndicePrimario);
                    }
                }

                //implementacao sem o uso dos arquivos secundarios para busca
                /*printf("\nQual nome deseja procurar? ");
                for(int i=0; i<tamNomes; i++){
                    printf("\n%d - %s", i+1, nomes[i]);
                }
                printf("\nEscolha um dos indices => ");
                scanf("%d", &escolha);
                escolha--;
                if(escolha<tamNomes && escolha>=0)
                    buscarRegistroIndiceSecundario(escolha, indiceS, indiceP, nomes, offsetNomes, tamIndicePrimario);
				else
                    printf("\nIndice indisponivel.");*/
                break;
            case 5: //carregamento do indice primario
                indiceP= carregarIndicePrimario("indicePrimario.bin", &tamIndicePrimario);
                if(tamIndicePrimario == 0){
                    indiceP=NULL;
                    printf("\nSem registros inseridos.");
                }
                break;
            case 6: //carregamento do indice secundario
                carregarIndiceSecundario(indiceS, nomes, offsetNomes, &tamIndiceSecundario, &tamNomes);
                if(tamIndiceSecundario == 0){
                    printf("\nSem registros inseridos.");
                }
                break;
			default:
				printf("Opcao invalida.");
		}
		getchar();
	}while(op!=0);
}