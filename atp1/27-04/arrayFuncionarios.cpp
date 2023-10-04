#include <iostream>
using namespace std;
int main(){
	int n;
	cout<<"Digite o tamanho da lista.\n";
	cin>>n;
	float salario[n], comissao[n],media=0;
	int tempo[n],i,maiorTempo=0,iMaiorTempo;
	
	for(i=0; i<n;i++){
		cout<<"Digite o salario, tempo de servico e a comissao.\n";
		cin>>salario[i]>>tempo[i]>>comissao[i];
	}
	for(i=0;i<n;i++){
		media+=salario[i];
		if(tempo[i]>maiorTempo){
			iMaiorTempo=i;
			maiorTempo=tempo[i];
		}
	}
	cout<<"Media de salarios:"<<media/n<<"\nComissao do funcionario + antigo:"<<comissao[iMaiorTempo];	
	return 0;
}
