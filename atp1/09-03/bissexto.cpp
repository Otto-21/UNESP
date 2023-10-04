#include<iostream>
using namespace std;

int main(){
	int ano;
	cout<<"Digite um numero: ";
	cin>>ano;
	if((ano%400==0) || (ano%4==0 and !(ano%100==0))){
		cout<<"Ano bissexto";
	}
	else{
		cout<<"Nao bissexto";
	}
	
	return 0;
}
