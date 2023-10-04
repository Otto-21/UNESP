/* 
Gabriel dos Santos Severo
Marcus Vinicius de Oliveira Silva
Otto Jacometo
Ygor Ismael da Silva
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int primo_iter(int n){
    if(n%2==0 && n>2)               //verifica se e par, caso seja maior que 2
        return 0;
    for(int i=3;i<=sqrt(n);i+=2){ //nao sendo par, verifica se e divisivel por algum numero entre 3 e raiz de n
        if(n%i==0){
            return 0;           //caso seja, sai do for, retornando 0
            break;
        }
    }
    return 1;                   //caso saia do 'for' sem retornar 0 (falso), retorna 1, sinalizando que e primo
}

int primo_rec(int n,int d){
    if(d<sqrt(n)){                  //para o programa funcionar de 2 a raiz de n
        if(n%2==0 && n>2){          //verifica se e par, caso seja maior que 2
            return 0;
        }
        else if(n%d==0){            //caso nao seja par, verifica se e divisivel por algum outro numero
            return 0;
        }
            else
                primo_rec(n,d+2);   //como para chegar nessa parte não pode ser par, soma-se de 2 em 2 a partir de 3, apeas numeros impares
    }
    else
        return 1;
}

int main(){
    int n=0;
    while(n<=1){
        printf("Entre com um numero (maior que 1).");
        scanf("%d",&n);
    }

	if(primo_rec(n,3))                              //d é definido como 3 ao chamar a funcao
		printf("E primo. // por recursao\n");
	else
		printf("Nao e primo. // por recursao\n");
    
    if(primo_iter(n))
		printf("E primo. // por iteracao\n");
	else
		printf("Nao e primo. // por iteracao\n");
    return 0;
}
