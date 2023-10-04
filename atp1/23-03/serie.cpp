#include <iostream>
#include <cmath>
using namespace std;
int main(){
	float num,soma=0;
	int i=1;
	while(i<=10){
		num=1/(pow(3,i));
		i+=1;
		soma+=num;
		cout<<"1/"<<pow(3,i)<<" = "<<num<<"\n";
	}
	cout<<"Soma = "<<soma;
	
	return 0;
}
