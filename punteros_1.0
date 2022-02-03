// parte 1

#include <iostream>
using namespace std;

int main(){
	int a,b;
	
	int *c, *d;
	a = 23;
	b = 67;
	
	//d apunta a a
	
	d = &a;
	
	cout<<*d<<endl;	

	c = &b;
	cout<<*c<<endl;
	 
	*d+=1;
	cout<<a;
	
	//susmame  a b en el valor de b y a
	
	*d = *c + *d;
	cout<< "Nuevo valor de a ="<<a<<endl;
}

// parte 2

#include <iostream>
using namespace std;

int main(){
	int a,b;
	int *c, *d;
	int **e, **f;
	
	a = 45;
	c = &a;
	e = &c;
	b = *c+1;
	d = &b;
	
	cout<< *d <<endl;
	
	cout<< "valor de e = "<< e <<endl;
	cout<< "Dir de e = "<< &e <<endl;
	cout<< "inDir de e = "<< *e <<endl;
	cout<< "Doble inDir de e = "<< **e <<endl;
	**e = **e*2;
	cout << **e;
}
