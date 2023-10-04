#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int i=0,n1=2;
	float soma=0,resul;
	bool neg=false;
	while(i<10){
		if(!neg){
			resul=n1/pow(2,i);
			cout<<n1<<"/"<<pow(2,i)<<" = ";
		}
		else{
			resul=-n1/pow(2,i);
			cout<<"-"<<n1<<"/"<<pow(2,i)<<" = ";
		}
		neg=!neg;
		n1++;
		i++;
		soma+=resul;
		cout<<resul<<"\n";
	}
	cout<<"Soma = "<<soma;
	return 0;
}
