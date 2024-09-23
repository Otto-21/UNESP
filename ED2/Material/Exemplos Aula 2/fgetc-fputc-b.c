#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
  char ch;
  FILE *in, *out;
  int x;

  if ((in = fopen("entradaT.txt","w+b")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }
  if ((out = fopen("saidaT.txt","w+b")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }

  x=10;
  fwrite(&x,sizeof(x),1,in);
  x=-1;
  fwrite(&x,sizeof(x),1,in);
  x=20;
  fwrite(&x,sizeof(x),1,in);
  rewind(in);//fseek(in,0,0)

  while ((ch = fgetc(in)) != EOF)//escreve byte a byte
   {
	 fputc(ch,out);
	 printf("passou\n");
   }
   
/*  fread(&x,sizeof(x),1,in);
  while (!feof(in))
    {	  
      fwrite(&x,sizeof(x),1,out);
      fread(&x,sizeof(x),1,in); 
    } */

 // while (fread(&x,sizeof(x),1,in))
	// fwrite(&x,sizeof(x),1,out);
 	
  fseek(out,0,0);
  while (fread(&x,sizeof(x),1,out))
	 printf("%d , ",x);

  fclose(in);
  fclose(out);

  getch();
}
