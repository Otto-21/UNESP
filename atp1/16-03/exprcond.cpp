/*
condicional - senten�a = N�O resulta num valor

condicional - express�o = resulta num valor

*/
#include <iostream>
using namespace std;
int main(){
	int a;
	
	if(3>2)
		a=10;
	else
		a=7;
	int b;
	b= 3>2 ? 10 : 7;
	//operador tern�rio: condi��o (true ou false) ? valor (se true) : valor (se false)
	
	cout<<b;
	return 0;
}
