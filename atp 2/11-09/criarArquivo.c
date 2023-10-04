#include<stdio.h>
int main(){
    FILE *fp=fopen("clientes.txt","w");

    if(fp==NULL){
        printf("Nao foi possivel abrir o arquivo.");
    }
    else{
        printf("Digite o numero da conta, nome e saldo.\n");
        printf("Entre EOF para terminar a entrada");
        int acc;
        char name[30];
        float balance;
        scanf("%d%29s%f",&acc,name,&balance);

        while(!feof(stdin)){
            fprintf(fp,"%d %s %f\n",acc,name,balance);
            scanf("%d%29s%f",&acc,name,&balance);
        }

        fclose(fp);
    }


    return 0;
}