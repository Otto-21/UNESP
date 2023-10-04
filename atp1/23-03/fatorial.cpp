#include <iostream>
using namespace std;

int main(){
	int n,i=1,fat=1;
	cout<<"Digite um numero para calcular seu fatorial.\n";
	cin>>n;
	while(i<=n){
		fat*=i;
		i+=1;
	}
	cout<<fat;
	return 0;
}
