#include<iostream>
using namespace std;

int main(){
	char tipo;
	cout<<"Informe o tipo sanguineo (A,B,O,Z)\n";
	cin>>tipo;
	if(tipo=='A' || tipo=='a')
		cout<<"Paciente aceita doacoes dos tipos A e O.";
	else if(tipo=='B' || tipo=='b')
		cout<<"Paciente aceita doacoes dos tipos B e O.";
	else if(tipo=='O' || tipo=='o')
		cout<<"Paciente aceita doacoes do tipo O.";
	else if(tipo=='Z' || tipo=='z')
		cout<<"Paciente aceita doacoes dos tipos A, B, AB e O.";
	else
		cout<<"Opcao invalida";
	return 0;
}
