#include <iostream>
#define lin 2
#define col 3
using namespace std;
int main(){
	int q[lin][col];
	int a[lin];
	int i,j,soma=0, pares=0;
	bool flagPar=true;
	
	for(i=0;i<lin;i++){
	 	for(j=0;j<col;j++){
	 		cout<<"Digite o elemento "<<i<<" "<<j<<endl;
	 		cin>>q[i][j];
		 }
	}
	 
	for(i=0;i<lin;i++){
	 	soma+=q[i][1];
	}
	cout<<"Soma da 2a coluna= "<<soma<<endl;
	 
	for(i=0;i<col;i++){
	 	if(q[1][i]%2==0)
	 		pares++;
	}
	cout<<"Ao total, na 2a linha existem "<<pares<<" numeros pares"<<endl;
	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			if(q[i][j]<0)
				flagPar=false;
		}
	}
	cout<<(flagPar? 'S': 'N')<<endl;
	
	for(i=0;i<lin;i++){
		a[i]=q[i][0];
	}
	for(i=0;i<lin;i++){
		cout<<a[i]<<" ";
	}
	 
	return 0;
}
