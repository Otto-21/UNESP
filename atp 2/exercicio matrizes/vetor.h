
typedef struct
{
    int *data;
    int n;
} vetor;

vetor new_vetor(int n, int init);
void free_vetor(vetor *v);
bool vetor_is_null(vetor v);

vetor soma_vetores(vetor u, vetor v);
void vetor_read(vetor v);
void vetor_print(vetor v);