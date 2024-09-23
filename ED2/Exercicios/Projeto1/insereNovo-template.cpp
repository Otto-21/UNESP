#include<stdio.h>

int main() {
    FILE *fd;
    
    //////////////////////////////
    struct hist {
        char id_aluno[4];
        char sigla_disc[4];
        char nome_aluno[50];
        char nome_disc[50];
        float media;
        float freq;
    } vet[6] = {{"004", "CCC", "Claudio Silva", "CCCCC", 7.3, 89.3},
                {"005", "JJJ", "C", "J", 4.5, 68.9},
                {"008", "CCC", "Raimundo Oliveira", "CCCCC", 6.0, 80.0},  
                {"009", "TTT", "Adoniran Barbosa", "TT", 2.8, 56.7},
                {"009", "HHH", "Adoniran Barbosa", "HHH", 9.2, 97.8},
                {"005", "AAA", "Tulio Mendonça", "AAA", 7.1, 92.7}};
       
    fd = fopen("insereNovo.bin", "w+b");
    fwrite(vet, sizeof(vet), 1, fd);
    fclose(fd);
    
    //////////////////////////////
	/*struct remove {
        char id_aluno[4];
        char sigla_disc[4];
    } vet_r[4] = {{"001","CCC"},
                  {"001","HHH"},
                  {"002","HHH"},
                  {"001","AAA"}};
       
    fd = fopen("remove.bin", "w+b");
    fwrite(vet_r, sizeof(vet_r), 1, fd);
    fclose(fd);*/
}

