#include <iostream>
using namespace std;
int main(){
	char stream;
	cout<<"Informe o servico de streaming \nN- Netflix\nP- Prime Video\nH- HBO Max\n";
	cin>>stream;
	
	float preco;
	switch(stream){
		case 'n': cout<<"Upper case";
		case 'N':
			preco=55.90;
			break;
		case 'p': cout<<"Upper case";
		case 'P':
			preco=14.90;
			break;
		case 'h': cout<<"Upper case";
		case 'H':
			preco=16.90;
			break;
		default:
			preco=-1.0;
	}
	cout<<endl<<preco;
	return 0;
}
