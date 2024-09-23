#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
  char ch[1000];
  FILE *in, *out;

  if ((in = fopen("entrada.txt","rt")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getche();
		return 0;
	 }
  if ((out = fopen("saida.txt","w+t")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getche();
		return 0;
	 }

  while ((fgets(ch,1000,in)) != NULL)
	 fputs(ch,out);

  fseek(out,0,0);
  while ((fgets(ch,1000,out)) != NULL)
	 printf("%s",ch);

  fclose(in);
  fclose(out);

  getch();
}
