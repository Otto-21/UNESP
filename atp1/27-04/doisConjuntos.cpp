#include <iostream>
using namespace std;
int main(){
	int n,m;
	
	cout<<"Digite qual sera o tamanho do conjunto 1 e 2.\n";
	cin>>n>>m;
	
	int cUm[n],cDois[m],i,j,contInter=0;
	
	cout<<"Digite o conjunto 1\n";
	for(i=0; i<n; i++){
		cin>>cUm[i];
	}
	
	cout<<"Digite o conjunto 2\n";
	for(i=0; i<m; i++){
		cin>>cDois[i];
	}
	
	bool fIntersec=false;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(cUm[i]==cDois[j]){
				fIntersec=true;
				//cout<<cUm[i]<<endl;
				contInter++;
			}
		}
	}
	
	int arrayInter[contInter],arrayUniao[n+m],k=0,aux=0;
	
	if(fIntersec){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(cUm[i]==cDois[j]){
					arrayInter[k]=cUm[i];
					k++;
				}
			}
		}	
	}
	
	//print intersecao 
	//cout<<"\n\n";
	/*while(i<contInter){
		cout<<arrayInter[i]<<",";
		i++;
	}*/
	
	for(i=0; i<n;i++){
		arrayUniao[i]=cUm[i];
		aux++;
	}
	bool check=true;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(cDois[i]==arrayUniao[j])
				check=false;
		}
		if(check){
			arrayUniao[aux]=cDois[i];
			aux++;
		}
		check=true;
	}
	

	i=0;

	//print uniao
	/*while(i<aux){
		cout<<arrayUniao[i]<<",";
		i++;
	}*/
	
	int arrayDiferenca[n-contInter];
	aux=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(cUm[i]==cDois[j])
				check=false;
		}
		if(check){
			arrayDiferenca[aux]=cUm[i];
			aux++;
		}
		check=true;
	}
	
	i=0;
	while(i<aux){
		cout<<arrayDiferenca[i]<<",";
		i++;
	}
	cout<<"\n"<<aux;
	
	

	return 0;	
}
