#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
	Nodo *ant;
};

void crear (Nodo *&cab, int d){
	Nodo* nuevo = new Nodo;
	nuevo->dato = d;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	cab = nuevo;
}

void insertarInicio(Nodo * &cab, int d){
	Nodo * nuevo = new Nodo;
	nuevo->dato = d;
	nuevo->sig = cab;
	cab->ant = nuevo;
	nuevo->ant = NULL;
	cab=nuevo;
}

void insertarFin(Nodo * &fin, int d){
	Nodo *nuevo = new Nodo;
	nuevo->dato = d;
	nuevo->sig = NULL;
	nuevo->ant = fin;
	fin->sig = nuevo;
	fin = nuevo;
}

void insetrarenmedio( Nodo * cab, int n, int dato){
	Nodo* aux =cab;
	Nodo * nuevo=new Nodo;
	nuevo->dato=dato;
	
	for(int i = 0; i <= n; i++){
		aux =aux->sig;
	}
	nuevo->sig = aux->sig;
	aux->sig->ant=nuevo;
	nuevo->ant=aux;
	aux->sig=nuevo;
}


void imprimir(Nodo * cab){
	Nodo * aux = cab;
	
	while(aux!=NULL){
		cout<<aux->dato<<"-->";
		aux = aux->sig;
	}
	cout<<endl;
}

void imprimir2(Nodo * cab){
	Nodo * aux = cab;
	
	while(aux!=NULL){
		cout<<aux->dato<<"-->";
		aux = aux->ant;
	}
	cout<<endl;
}

void eliminarInicio(Nodo * &cab){
	Nodo*aux = cab;
	cab = cab->sig;
	cab->ant=NULL;
	delete aux;
}

void eliminarMedio(Nodo * &cab, int d){
	Nodo*aux = cab;
	
	for(int i=0; i<=d ; i++){
		aux=aux->sig;
	}
	
	aux->sig->ant=aux->ant;
	aux->ant->sig=aux->sig;
	delete aux;
}

int main(){
	Nodo* cab = NULL;
	Nodo* fin = NULL;
	int d;
	
	for(int i = 0; i<= 3; i++){
		if (cab == NULL){
			crear(cab,i);
			fin = cab;
		}
		else{
			insertarInicio(cab,i);
		}
	}
	imprimir(cab);
	imprimir2(fin);
	
	cout<<"\n\n\n";
	
	
	for(int i = 10; i<= 20; i++){
		insertarFin(fin,i);
	}
	imprimir(cab);
	imprimir2(fin);
	
	cout<<"\n\n\n";
	
	insetrarenmedio(cab,5,70);
	
	eliminarInicio(cab);
	imprimir(cab);
	imprimir2(fin);
	
	
	
	
	return 0;
}
