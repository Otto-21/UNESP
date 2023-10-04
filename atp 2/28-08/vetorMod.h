typedef struct
{
    float *data; //dados do vetor
    int n; //tamanho do vetor
} vetor;

vetor newVetor(float *data, int n);
float somaVetor(vetor v);
void imprimeVetor(vetor v);
void ordena(vetor v, int (*compara)(float, float));
void troca(vetor v, int i, int j);
int maior(float x, float y);
int menor(float x, float y);