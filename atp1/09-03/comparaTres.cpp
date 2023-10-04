#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cout<<"Informe tres valores diferentes\n";
	cin>>a>>b>>c;
	if(a>b && a>c)
		if(b>c)
			cout<<a<<">"<<b<<">"<<c;
		else
			cout<<a<<">"<<c<<">"<<b;
	else if(b>a && b>c)
			if(a>c)
				cout<<b<<">"<<a<<">"<<c;
			else
				cout<<b<<">"<<c<<">"<<a;
		else if(b>a)
				cout<<c<<">"<<b<<">"<<a;
			else
				cout<<c<<">"<<a<<">"<<b;
	return 0;
}
