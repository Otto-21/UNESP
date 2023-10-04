#include<iostream>
using namespace std;

int main(){
	int a,b;
	cout<<"Informe dois valores inteiros diferentes\n";
	cin>>a>>b;
	if(a>b){
		cout<<a<<">"<<b;
	}
	else{
		cout<<b<<">"<<a;
	}
	return 0;	
}
