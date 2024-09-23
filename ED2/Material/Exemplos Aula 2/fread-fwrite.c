#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
  FILE *out;
  char ch[20]= "Teste Geral";
  int i, valor[10]={0,1,2,3,4,5,6,7,8,9};
  int teste_int = 100;
  char teste_char = 'X';

  if ((out = fopen("saidaB.bin","w+b")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }

  fwrite(ch,sizeof(ch),1,out);
  //fwrite(ch,sizeof(char),20,out);
  
  //fwrite(valor,sizeof(int),10,out);
  fwrite(valor,sizeof(valor),1,out);
  
  fwrite(&teste_int,sizeof(int),1,out);
  
  fwrite(&teste_char,sizeof(char),1,out);

  fseek(out,0,0);
  //fread(ch,sizeof(ch),1,out);
  fread(ch,sizeof(char),20,out);
  printf("%s\n",ch);
  
  fread(valor,sizeof(int),10,out);
  for (i=0; i < 10; i++)
	printf("%d ",valor[i]);

  fread(&teste_int,sizeof(int),10,out);
  printf("\n%d ",teste_int);
  
  fread(&teste_char,sizeof(char),10,out);  
  printf("\n%c ",teste_char);
  
  fclose(out);

  getch();
}
