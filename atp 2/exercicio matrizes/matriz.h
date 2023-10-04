/*
Nome:                     | RA:
---------------------------------------
Otto Jacometo             | 231150903
Rodrigo Tedeschi Rampazzo | 231153244
*/


//Matriz armazenada em ponteiro duplo
typedef struct
{
    int lin, col; //linhas e colunas
    float **data; //dados
} mtz;

mtz new_mtz(int lin, int col, float init);
void free_mtz(mtz *m);
void mtz_read(mtz m);
void mtz_print(mtz m);
mtz soma_mtz(mtz A, mtz B);
mtz ppscalar_mtz(mtz A, int esc);
mtz mul_mtz(mtz A, mtz B);
mtz transposta_mtz(mtz B);