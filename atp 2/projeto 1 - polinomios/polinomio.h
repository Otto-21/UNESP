typedef struct{
    float *coef;
    int grau;
}pol;

void free_pol(pol *p);
//pol new_pol(char *s);
pol newPol(int grau);
float funcao(pol *p, float z);
bool polIsNull(pol p);
pol somaPol(pol *p1, pol *p2);