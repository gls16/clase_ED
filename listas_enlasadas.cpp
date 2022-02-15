#include <iostream>
using namespace std;

struct Producto{
	
	string nom;
	float pre;
	Producto * sig;

};

void Crear(Producto * &cab, string n, float p){
	Producto* nuevo = new Producto;
	nuevo->nom=n;
	nuevo->pre=p; 
	nuevo->sig=NULL;
	cab=nuevo;
}

void InsertarInicio(Producto * &cab, string n, float p){
	Producto* nuevo = new Producto;
	nuevo->nom=n;
	nuevo->pre=p; 
	nuevo->sig=cab;
	cab=nuevo;
}

void imprimir(Producto * cab){
	Producto* aux=cab;
	while(aux!=NULL){
		cout<<"Prod "<<aux->nom<<" Valor "<<aux->pre<<endl;
		aux=aux->sig;
	}
}

int main(){
	
	Producto* cab =NULL;
	string n;
	float p;
	
	int op = 1;

	cout<<"ingrese el noombre del producto"<<endl;cin>>n;
	cout<<"ingrese el valor del producto"<<endl;cin>>p;
	
	Crear(cab,n,p);
	
	/*
	cout<<cab->nom<<endl;
	cout<<cab->pre<<endl;
	
	
	cout<<cab->nom<<endl;
	cout<<cab->pre<<endl;
	
	InsertarInicio(cab,n,p);
	*/
	
		while( op == 1){
		cout<<"ingrese el noombre del producto"<<endl;cin>>n;
		cout<<"ingrese el valor del producto"<<endl;cin>>p;
		InsertarInicio(cab,n,p);
		cout<<"ingrese 1 para otro producto"<<endl;cin>>op;
		}
		
		imprimir(cab);
		
	return 0;
}
