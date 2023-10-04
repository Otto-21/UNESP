#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n1=0, n2=1, aux,i=2;
	cout<<n1<<"\n"<<n2<<"\n";
	while(i<10){
		aux=n2;
		n2+=n1;
		n1=aux;
		cout<<n2<<"\n";
		i++;
	}
	
	return 0;
}
