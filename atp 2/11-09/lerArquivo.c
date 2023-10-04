#include<stdio.h>
int main(){
    FILE *fp=fopen("clientes.txt","r");
    if(fp==NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{
        int acc;
        char name[30];
        float balance;
        fscanf(fp,"%d %s %f",&acc,name,&balance);
        while(!feof(fp)){
            printf("Conta: %d\tCliente: %s\tSaldo: %.2f\n",acc,name,balance);
            fscanf(fp,"%d %s %f",&acc,name,&balance);
        }
        fclose(fp);
    }

    return 0;
}