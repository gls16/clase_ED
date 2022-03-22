#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *ant;
};


void imprimir1(Nodo* cab){
    Nodo* aux=cab;
    do{
    cout<<aux->dato<<"->";
    aux=aux->sig;
    } while(aux!=cab);
}

void imprmir2(Nodo *cab){
    Nodo * aux = cab->ant;
    do
    {
        cout<<aux->dato<<"->";
        aux=aux->ant;   
    } while (aux != cab->ant);
    
}

void imprmir3(Nodo * cab, int n){
    Nodo * aux1 = cab;
    Nodo * aux2;

    for (int i ; i<=n; i++){
        aux1=aux1->sig;
    }
    aux2 = aux1;
    
    do
    {
        cout<<aux2->dato<<"->";
        aux2=aux2->sig;
    } while (aux1 != aux2);
    
}

void imprmir4(Nodo * cab, int d){
    Nodo*aux1=cab;
	Nodo*aux2;
	
	for(int i=1;i<=d;i++){
		aux1=aux1->sig;
	}
	aux2=aux1;
	do {
	cout<<aux2->dato<<"->";
	aux2=aux2->ant;
	}while(aux2!=aux1);
}

void crear(Nodo * &cab, int d ){
    Nodo * nuevo = new Nodo;
    nuevo->dato = d;
    nuevo->sig = nuevo;
    nuevo->ant = nuevo;
    cab = nuevo;
}

void insertar(Nodo * cab, int d){
    Nodo *nuevo = new Nodo;
    Nodo * fin = cab->ant;
    nuevo->dato = d;
    nuevo->sig = cab;
    cab->ant= nuevo;
    cab = nuevo;
    cab->ant = fin;
    fin->sig = cab;
}

void insertarFinal(Nodo * cab, int d){
    Nodo *fin = cab->ant;
    Nodo *nuevo = new Nodo;
    nuevo->dato = d;
    fin->sig = nuevo;
    nuevo->ant = fin;
    nuevo->sig = cab;
    cab->ant=nuevo;
}

int main(){
    Nodo * cab = NULL;

    for(int i = 0; i<= 5 ; i++){
        if( cab == NULL){
            crear(cab,i);
        }
        else{
            insertar(cab,i);
        }
    }

    imprimir1(cab);
    
    cout<<endl;
    
    imprmir2(cab);
    
    cout<<endl;

    imprmir3(cab,2);
    
    cout<<endl;

    imprmir4(cab,3);

    for(int i=100; i<=110; i++){
        insertarFinal(cab,i);
    }

    cout<<endl;

    imprimir1(cab);

    return 0;
}
