#include<iostream>
using namespace std;

int main(){
	char tipo;
	cin>>tipo;
	switch(tipo){
		case 'A':
			cout<<"Sangue tipo A.";
			break;
		case 'B':
			cout<<"Sangue tipo B.";
			break;
		case 'O':
			cout<<"Sangue tipo O.";
			break;
		case 'Z':
			cout<<"Sangue tipo AB.";
			break;
		default:
			cout<<"Evita.";
	}
	return 0;
}
