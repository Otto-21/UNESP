#define lin 3
#define col 3
#include<iostream>
using namespace std;
int main(){
	int m[lin][col],a[lin],t[col][lin],arrayInferior[lin*lin/2];
	int i,j,k=0,anterior;
	bool repetido=false,crescente=true;
	
	//leitura
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			cout<<"Digite o elemento "<<i<<" "<<j<<endl;
			cin>>m[i][j];
		}
	}
	
	//vetor com os numeros da diagonal
	for(i=0;i<lin;i++){
		a[i]=m[i][i];
	}
	
	//verificar se ha numeros repetidos na diagonal principal
	for(i=0;i<lin;i++){
		for(j=0;i<lin;j++){
			if(m[i][i]==a[j] && i!=j)
				repetido=true;
				break;
		}
		if(repetido)
			break;
	}
	cout<<(repetido?"Existem numeros repetidos na diagonal principal da matriz":"Nao existem numeros repetidos na diagonal principal da matriz")<<endl;
	
	//verificar se a diagonal secundaria esta em ordem cresc
	anterior=m[lin-1][0];
	for(i=1;i<lin;i++){
		if(anterior>m[lin-1-i][i])
			crescente=false;
		anterior=m[i][i];
	}
	cout<<(crescente?"A diagional secundaria esta em ordem crescente":"A diagional secundaria nao esta em ordem crescente")<<endl;
	
	
	//matriz transposta
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			t[i][j]=m[j][i];
		}
	}
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//estudar mais
	
	//gerar array com elementos impares da parte inferior da diagonal secundaria da matriz
	for(i=1;i<lin;i++){
		for(j=lin-i;j<lin;j++){
			if(m[i][j]%2==1){
				arrayInferior[k]=m[j][i];
				k++;
			}
		}
	}
	for(i=0;i<k;i++){
		cout<<arrayInferior[i]<<" ";
	}
	return 0;
}
