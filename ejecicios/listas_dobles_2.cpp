#include <iostream>
using namespace std;

struct Producto{
	string nombre;
	float precio;
	Producto * sig;
	Producto * ant;
};

void insertar (Producto* &cab, string n, float p){
	Producto * nuevo = new Producto;
	nuevo->nombre=n;
	nuevo->precio=p;
	
	if (cab == NULL){
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
	
	else{
		nuevo->sig = cab;
		cab->ant = nuevo;
		nuevo->ant = NULL;
	}
	
	cab = nuevo;
}

void imprimir (Producto * cab){
	Producto* aux = cab;
	
	while (aux != NULL){
		cout<<"precio del producto: "<< aux->precio<<endl;
		cout<<"precio del producto: "<< aux->nombre<<endl;
		cout<<"-------------"<<endl;
		aux = aux->sig;
	}
}

float promedio (Producto * cab){
	float sumatoria = 0;
	int contador = 0;
	
	Producto * aux = cab;
	
	while (aux != NULL){
		contador++;
		sumatoria = sumatoria + aux->precio;
		aux = aux->sig;
	}
	return sumatoria/contador;
}

float mayor (Producto * cab){
	float auxiliar;
	
	Producto *aux = cab;
	while ( aux != NULL){
		if (aux->precio > auxiliar ){
			auxiliar = aux->precio;
		}
		aux = aux->sig;
	}
	return auxiliar;
}

void rango (Producto * cab, float n){
	Producto *aux = cab;
	while ( aux != NULL){
		if (aux->precio <= n ){
			cout <<"precio:\n"<< aux->precio<<"nombre:"<<aux->nombre; 
		}
		aux = aux->sig;
	}
}

void lista(Producto * cab){
	Producto * aux = cab;
	int contador = 0;
	while (aux != NULL){
		cout << contador <<"  "<<  aux->nombre << endl;
		contador ++;
		aux= aux->sig;
	}
	
}

Producto* buscar( Producto *cab, int n){
	Producto *aux = cab;
	for(int i = 1; i <= n; i++ ){
		aux = aux->sig;
	}
	return aux;
}

int main(){
	Producto * cab = NULL;
	Producto * fin;
	Producto *aux;
	float p;
	string n;
	int d;
	
	cout<<"cuantos productos, desea ingreesar: ";cin>>d;
	cout<<endl;
	
	for( int i = 0; i<=d ; i++){
		
		cout<<"ingrese el nombre del producto: \n";cin>>n;
		cout<<"ingrese el precio del producto: \n";cin>>p;
		cout<<"\n\n";
		insertar(cab, n, p);
	}
	
	imprimir(cab);
	
	cout<<"\n";
	cout<<"El promedio del precio de los productos es de: \n"<<promedio(cab)<<endl;
	cout<<"\n";
	cout<<"El mayor producto es: \n"<<mayor(cab)<<endl;
	
	cout<<"ingrese el rango del prducto: \n";cin>>p;
	rango(cab,p);
	
	cout<<"\n\n";
	
	lista(cab);
	
	cout<<"seleccione el producto :\n";cin>>d;
	aux = buscar(cab, d);
	
	return 0;
}
