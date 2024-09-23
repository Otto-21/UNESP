#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
  char ch;
  FILE *in, *out;

  if ((in = fopen("entrada.txt","rt")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }
  if ((out = fopen("saida.txt","w+t")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }

/*  while (!feof(in))
    {
	  ch = fgetc(in);
      fputc(ch,out);
    }*/

  while ((ch = fgetc(in)) != EOF)
	 fputc(ch,out);
	 
  /*if (EOF == -1)	 
    printf("Fim de arquivo\n\n");*/

  fseek(out,0,0);
  while ((ch = fgetc(out)) != EOF)
	 printf("%c",ch);

  fclose(in);
  fclose(out);

  getch();
}
