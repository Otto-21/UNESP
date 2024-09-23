#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
  FILE *in, *out;
  float distancia, tempo, velocidade;

  if ((in = fopen("entradaF.txt","rt")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }
  if ((out = fopen("saidaF.txt","w+t")) == NULL)
	 {
		printf("Nao foi possivel abrir o arquivo");
		getch();
		return 0;
	 }

  while ((fscanf(in,"%f%f",&distancia,&tempo)) != EOF)
	{
	  velocidade = distancia/tempo;
	  fprintf(out,"Distancia percorrida: %.2f km\n",distancia);
	  fprintf(out,"Tempo decorrido: %.2f h\n",tempo);
	  fprintf(out,"Velocidade media: %.2f km/h\n",velocidade);
	}

  fclose(in);
  fclose(out);

  getch();
}
