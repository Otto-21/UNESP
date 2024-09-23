//Otto Jacometo
//Thiago Uliame 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


typedef struct{
	char idAluno[4]; //4 bytes
	char siglaDisc[4]; //4 bytes
	char nomeAluno[50]; //maximo 50 bytes
	char nomeDisc[50]; //maximo 50 bytes
	float media; //4 bytes
	float frequecia; //4 bytes
} HISTORICO; 

typedef struct{
    char id_aluno[4];
    char sigla_disc[4];
} REMOVE;

/*offset e um inteiro que indica a distancia (deslocamento) entre o comeco do objeto e um dado
elemento ou ponto, presumivelmente dentro do mesmo objeto*/

void carregarHistorico(char *nomeArquivoInsert, char *nomeArquivoNovo){
	FILE *insere;
	HISTORICO h;
	FILE *novo;
	char registro[100];
	int tam, offset=-1;
	
	insere = fopen(nomeArquivoInsert, "r+b");
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

void insere(char *lista, char *insert, int quantidade){
	FILE *arq, *listaInsert;
	int ultimoInserido, offset, oldOffset, proxOffset, novoOffset, tamDisp, tamBuffer, dif=0, contador=0;
	char buffer[150], verificacao, marca='*';

	//abertura de arquivos
	arq= fopen(lista, "r+b");
	listaInsert= fopen(insert, "r+b");

	fseek(arq, 0, 0);

	if(listaInsert == NULL){
		printf("\nLista de inserção inválida.");
		return;
	}

	for(int i=0; i < quantidade; i++){
		contador=0;
		if(fread(&ultimoInserido, sizeof(int), 1, listaInsert) <= 0){
			printf("\nLista de inserção sem header");
			return;
		}

		//se posiciona no ultimo registro inserido
		if(ultimoInserido>-1) 
			fseek(listaInsert, ultimoInserido, SEEK_CUR); 
				//carrega o tamanho do registro que será inserido

		if(fread(&tamBuffer, sizeof(int), 1, listaInsert) <= 0){ 
			printf("\nErro ao ler tamanho do registro.");
			return;
		}
		printf("\nTmB: %d",tamBuffer);

		//carrega o registro
		if(fread(&buffer, tamBuffer, 1, listaInsert) <= 0){
			printf("\nErro ao ler registro.");
			return;
		}

		buffer[tamBuffer]='\0';
		
		while(fread(&offset, sizeof(int), 1, arq) > 0){
			if(offset > -1){ //se houverem registros removidos
				
				fseek(arq, offset + sizeof(int), 0);

				//carrega o tamanho disponivel	
				if(fread(&tamDisp, sizeof(int), 1, arq) > 0){
					//carrega para verificar a marca de exclusao (*)
					if(fread(&verificacao, sizeof(char), 1, arq) > 0){
						if(verificacao=='*'){
							//carrega proximo offset
							if(fread(&proxOffset, sizeof(int), 1, arq) <= 0){
								printf("\nErro ao carregar proximo offset.");
								return;
							}
							/*ponteiro estará em:
							etc(tamanho)*(proxOffset)lixo(tamanho)etc
							   			^			 ^
							   			|			 |
								precisa voltar		aqui
									para ca
							*/
							if(tamDisp==tamBuffer){
								//salva o offset proximo no antigo
								//printf("\nEntrou aqui, offset:%d, contador: %d, oldOffset: %d, prox: %d",offset,contador,oldOffset, proxOffset);
								
								if(contador > 0){
									//printf("\nInserindo %d em: %d",proxOffset, oldOffset + 2*sizeof(int)+sizeof(char));
									//printf("\nRelativo: %d",oldOffset + 2*sizeof(int)+sizeof(char));
									fseek(arq, oldOffset + 2*sizeof(int)+sizeof(char), 0); 
									fwrite(&proxOffset, sizeof(int), 1, arq);
								}
								else{
									fseek(arq, 0, 0);
									fwrite(&proxOffset, sizeof(int), 1, arq);
								}
							}	
							else if(tamDisp>tamBuffer){ 
							
								dif=tamDisp-tamBuffer-sizeof(int);
								
								if(dif >= sizeof(int)+sizeof(char)){ //sizeof(int) + sizeof(char)
									// '*' (char) proxOffset (int)
								/*se houver fragmentação interna e não houver espaço suficiente 
								para escrever (dif)*(proxOffset), ele pulará para o fim do arquivo, para 
								evitar que haja lixo no registro que será inserido (nao consegui pensar
								numa forma de tratar)*/
									novoOffset=offset + tamBuffer + sizeof(int); //calcula o novo offset
									fseek(arq, novoOffset+sizeof(int), 0);	
									
									fwrite(&dif, sizeof(int), 1, arq);
									fwrite(&marca, sizeof(char), 1, arq);
									fwrite(&proxOffset, sizeof(int), 1, arq);

									if(contador==0){	//nao passou por nenhum registro
										fseek(arq, 0, 0); //vai para o começo do arquivo
										fwrite(&novoOffset, sizeof(int), 1, arq);//salva o novo offset no header
									}
									else{//ja passou por outro registro, precisa voltar para ele
									//para apontar para esse novo offset da diferença
										fseek(arq, oldOffset + 2*sizeof(int) + sizeof(char), 0); 
										fwrite(&novoOffset, sizeof(int), 1, arq);
									}
								}	
								else{
									printf("\nEntra aqui");
									fseek(arq, -sizeof(int), SEEK_CUR);
									oldOffset=offset;
									contador++;
									continue;
								}
							}
							else{
								//printf("\nTamanho não disponivel\t Prox offset em: %d",offset + sizeof(int) + sizeof(char));
								fseek(arq, -sizeof(int), SEEK_CUR);
								oldOffset=offset;
								contador++;
								continue;
							}

							//atualiza o offset da lista de insert
														
							if(ultimoInserido>-1)
								ultimoInserido += tamBuffer + sizeof(int);
							else
								ultimoInserido = tamBuffer + sizeof(int); 

							fseek(listaInsert, 0, 0);	
							fwrite(&ultimoInserido, sizeof(int), 1, listaInsert);
							fseek(listaInsert, 0, 0);	
							printf("\nUltimo: %d", ultimoInserido);
							
							//escreve o registro
							fseek(arq, offset + sizeof(int), 0);
							fwrite(&tamBuffer, sizeof(int), 1, arq); 	//escreve o tamanho do registro
							fwrite(buffer, tamBuffer, 1, arq); 			//escreve o registro
							printf("\nRegistro inserido");
							break;
						}
					}
					else{
						printf("\nErro no arquivo. Registro não salvo (leitura marca).\tOffset: %d\n",offset);
					}
				}
				else{
					printf("\nErro no arquivo. Registro não salvo (leitura tamanho disponivel).\tOffset: %d\n",offset);
				}

				//nao conseguiu salvar, entao aumenta o contador de tentativas e atualiza o offset
				oldOffset=offset;
				contador++;

			} //offset diferente de -1
			else{ 							//se nao tiver offset, vai para o fim do arquivo salvar

				//atualiza o header da lista de inseridos
				if(ultimoInserido>-1)
					ultimoInserido += tamBuffer+4;
				else
					ultimoInserido = tamBuffer+4; 

				fseek(listaInsert, 0, 0);		//posiciona ponteiro para inicio
				fwrite(&ultimoInserido, sizeof(int), 1, listaInsert);	//escreve header
				fseek(listaInsert, 0, 0);	//retorna o ponteiro para o inicio para ler novamente, caso necessario

				fseek(arq, 0, SEEK_END); //posiciona o ponteiro do arquivo no fim dele				
				fwrite(&tamBuffer, sizeof(int), 1, arq); //escreve o tamanho do registro
				fwrite(&buffer, tamBuffer, 1, arq); 		//escreve o registro
				printf("\nRegistro inserido");
				continue;
			}
		}//while
		fseek(arq, 0, 0);
	}
	fclose(listaInsert);
	fclose(arq);
}

void ler(char nomearq[100]){
	FILE *arq;
	arq=fopen(nomearq, "rb");
	char *pch, leitura[150];
	int tam, offset;
	
	if(arq != NULL){
		fread(&offset, sizeof(int), 1, arq);
		printf("\nHeader: %d\n",offset);
		while(fread(&tam, sizeof(int), 1, arq) > 0){
			leitura[tam]='\0';
			fread(&leitura, 1 , tam, arq);
			if(leitura[0]=='*')
				continue;
			else{
				pch = strtok(leitura,"#");
				while (pch != NULL){
				printf("%s ",pch);
				pch = strtok(NULL,"#");
				}
				printf("\n");
			}
	    }
	}
	fclose(arq);
}

void carregarDelete(char *nomeArquivoBase, char *listaNova){ 
	//altera o arquivo remove.bin, inserindo um offset para mostrar qual a ultima chave usada para remocao
	FILE *arq=fopen(nomeArquivoBase, "r+b");
	FILE *temp=fopen(listaNova, "w+b");

	int offset=-1;;
	char siglaDisc[4], idAluno[4];

	fwrite(&offset, sizeof(int), 1, temp);

	while(fread(&idAluno, sizeof(idAluno),1,arq) > 0 && fread(&siglaDisc, sizeof(siglaDisc),1,arq) > 0 ){
			fwrite(&idAluno, sizeof(idAluno), 1, temp);
			fwrite(&siglaDisc, sizeof(siglaDisc), 1, temp);
			//printf("\n%s - %s",idAluno,siglaDisc);
	}
	printf("\nArquivo carregado.");
	fclose(arq);
	fclose(temp);
}

void deletar(char *historico, char *listaRemocao, int quantidade){//chama-se a função após colocar um offset no header do arquivo
	FILE *arq= fopen(historico, "r+b");
	FILE *deletes= fopen(listaRemocao, "r+b");
	
	int offsetArquivoD, flag=0;
	char id[4], sigla[4],
	buffer[150], *pch, marca='*';
	int tam, offsetDelete=0, oldOffset;

	if(arq!=NULL && arq!=NULL){
		fread(&offsetArquivoD, sizeof(int), 1, deletes);

		if(offsetArquivoD>-1)
			fseek(deletes, offsetArquivoD, SEEK_CUR);

		fread(&oldOffset, sizeof(int), 1, arq);
		//posiciona o ponteiro para depois do header e pega o offset antigo
		
		for(int i=0; i<quantidade; i++){
			if(fread(&id, sizeof(char), 4, deletes)>0 && fread(&sigla, sizeof(char), 4, deletes)>0){
				
				if(offsetArquivoD==-1)
					offsetArquivoD=8;	//se for -1, passará a apontar para o segundo reigstro 
					//(onde deverá começar, da próxima vez)
				else		
					offsetArquivoD+=8;	//se não, aponta para o próximo (cada registro possui 8 bytes)

				while(fread(&tam,sizeof(int), 1, arq) > 0){
					fread(&buffer, tam, 1, arq);		//bufferiza o registro 
					buffer[tam]='\0';
					//ponteiro do arquivo estará no próximo registro

					if(buffer[0]=='*'){					//registro já deletado
						offsetDelete+=tam+4;
						continue;
					}
					else{
						pch= strtok(buffer, "#");			//pega o id aluno
						if(strcmp(pch, id)==0){				//compara ids	
							pch= strtok(NULL, "#");			//pega a sigla disc (ids ja sao iguais)
							if(strcmp(pch, sigla)==0){		//compara as silgas
								fseek(deletes, 0, 0);
								fwrite(&offsetArquivoD, sizeof(int), 1, deletes); 
								//salva qual dos registros da lista de delete ja foi lido
								//ponteiro aponta para depois do header
								fseek(deletes, offsetArquivoD, SEEK_CUR);
								//agora, para a prox chave do registro a ser deletado
								
								fseek(arq, -tam, SEEK_CUR);//volta para depois do tamanho do registro a ser excluido
								fwrite(&marca, sizeof(char), 1, arq); //escreve '*'
								fwrite(&oldOffset, sizeof(int), 1, arq); //escreve o antigo offset

								fseek(arq, 0, 0);
								fwrite(&offsetDelete, sizeof(int), 1, arq);//atualiza o header

								oldOffset=offsetDelete;
								//atualiza o offset que se torna velho, caso haja mais deleções

								flag=1;
								printf("\nRegistro %s - %s deletado.",id, sigla);
								break;
							}
						}
					}//else, caso nao esteja deletado

					offsetDelete+=tam+4;
				}
				if(!flag)
					printf("\nRegistro %s - %s nao encontrado.", id, sigla);

				fseek(arq, sizeof(int), 0);
				flag=0;
			}
			offsetDelete=0;
		}
	}
	else{
		printf("\nListas invalidas.");
	}
	fclose(deletes);
	fclose(arq);
	printf("\n");
}

void compactar(char *lista){
	int offset, tam;
	char buffer[150];
	
	FILE *arq= fopen(lista, "rb");
	FILE *novo= fopen("temp.bin", "w+b");

	if(arq!=NULL && novo!=NULL){
		if(fread(&offset, sizeof(int), 1, arq)>0){
			offset=-1;
			fseek(novo, 0, 0);
			fwrite(&offset, sizeof(int), 1, novo);
			while(fread(&tam, sizeof(int), 1, arq) > 0){
				if(fread(&buffer, tam, 1, arq) > 0){
					if(buffer[0]!='*'){
						buffer[tam]='\0';
						fwrite(&tam, sizeof(int), 1, novo);
						fwrite(buffer, tam, 1, novo);
						//printf("\nInserido: %d - %s",tam, buffer);
					}
				}
				else{
					printf("\nErro ao ler registro.");
					break;
				}
			}
			printf("\nArquivo compactado.");
			rename("temp.bin", lista);
		}
		else
			printf("\nErro ao ler offset.");
	}
	else{
		printf("\nLista(s) invalida(s)");
	}
	fclose(arq);
	fclose(novo);
}


int main(){
	int qtd=0,op=-1;
	printf("\n================================\n");
	printf("\tProjeto 1 - ED2");
	printf("\n    Manipulação de Arquivos");
	printf("\n================================\n");
	printf("\n1) Carregar Arquivos (lista, insert e delete).");
	printf("\n2) Inserir registro(s).");
	printf("\n3) Excluir registro(s).");
	printf("\n4) Ler a lista de registros.");
	printf("\n5) Compactar a lista de registros.");
	printf("\n0) Sair.");
	do{
		printf("\n\n================================\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("\nRealizado por: Otto Jacometo e Thiago Uliame\nAté mais!\n");
				break;
			case 1:
				carregarHistorico("insere.bin", "lista.bin");
				carregarHistorico("insereNovo.bin", "listaInsercao.bin");
				carregarDelete("remove.bin", "listaRemocao.bin");
				break;
			case 2:
				printf("Quantos registros deseja inserir? ");
				do{
					scanf("%d",&qtd);
					if(qtd<=0)
						printf("Favor inserir um número válido.");
				}while(qtd<=0);
				insere("lista.bin", "listaInsercao.bin", qtd);
				break;
			case 3:
				printf("Quantos registros deseja remover? ");
				do{
					scanf("%d",&qtd);
					if(qtd<=0)
						printf("Favor inserir um número válido.");
				}while(qtd<=0);
				deletar("lista.bin", "listaRemocao.bin", qtd);
				break;
			case 4:
				ler("lista.bin"); 
				break;
			case 5:
				compactar("lista.bin"); 
				break;
			default:
				printf("Opcao invalida.");
		}
		getchar();
	}while(op!=0);
}
