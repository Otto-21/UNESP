#include <stdbool.h>
typedef struct{
    float *coef;            //ponteiro p vetor de coefs
    int grau;               //grau do polinomio
}pol;


pol polFromFile(char *filename);
pol newPol(int grau);
void freePol(pol *p);
bool polIsNull(pol p);
float funcao(pol p, float z);
void printaPol(pol p);
void carregaPol(pol p, float *v); 


pol somaPol(pol p1, pol p2, bool sub);
pol prodPol(pol p1, pol p2);


pol derivaPol(pol p);
pol integraIndefPol(pol p, float c);
float integraDefPol(pol p, float sup, float inf);


float newtonRaphson(pol p, float xZero, int tmax, float e);