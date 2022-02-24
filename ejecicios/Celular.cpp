# include<iostream>
using namespace std;

struct celular {
	string marca;
	int id;
	celular* sig;
};

void insertar (celular* &cab, string marca, int id){
 
 celular* nuevo= new celular; 
 nuevo->marca = marca;
 nuevo->id = id;
 
 if (cab == NULL ){
 	nuevo->sig = NULL;
 } else {
 	nuevo->sig = cab;
 }
 cab= nuevo;
}

void imprimir (celular* cab){
	celular* aux= cab;
	while (aux != NULL){
		cout << "ID: " << aux->id << endl << "Marca: " << aux->marca << endl;
		aux = aux -> sig;
	}

}

void insertarenelmedio (celular* cab, string marca, int id,int buscar){
	celular* aux = cab;
	while (aux->id!=buscar)
		aux=aux->sig;
 	celular*nuevo = new celular;
	 nuevo->marca=marca;
	 nuevo->id=id;
	 nuevo -> sig = aux -> sig;
	 aux -> sig = nuevo;	
}

void eliminar(celular* &cab){
	celular* aux = cab;
	cab = cab->sig;
	delete aux;
}

void eliminarElMedio(celular* cab, int b){
	celular* aux = cab;
	celular* ant = cab;
	while (aux->sig){
		aux = aux->sig;
	}
	while ( ant->sig!=aux){
		ant=ant->sig;
	}
	ant->sig=aux->sig;
	delete aux;
}

void eliminarElMedio_2(celular* cab, int b){
	celular* aux = cab;
	celular* ant = cab;
	while (aux->id!=b){
		aux = aux->sig;
		ant=aux->sig;
		
	}
	ant->sig=aux->sig;
	delete aux;
}

int main (){
	celular * cab = NULL;
	string marca;
	int id, b;
	int i=0;
	for (i=0; i<= 4; i++){
	  cout << "Ingrese la marca del celular "<< endl;
	  cin>> marca;
	  cout << "Ingrese el id del celular "<< endl;
	  cin >> id;
	  insertar(cab, marca, id);
	}
	
	cout<<endl<<"lista de celulares: "<<endl;
		
	imprimir (cab);
	
	/*
	  cout << "Ingrese la marca del celular "<< endl;
	  cin>> marca;
	  cout << "Ingrese el id del celular "<< endl;
	  cin >> id;
	  
	
	
	cout<<"Ingrese el id del celular a buscar: "<<endl;
	cin>>b;
	
	
	
	insertarenelmedio (cab, marca, id, b);
	imprimir(cab);
	
	*/
	
	cout<<"\n\n\n";
	
	/*
	eliminar(cab);
	imprimir(cab);
	*/
	
	cout<<"Ingrese el id del celular a eliminar: "<<endl;cin>>b;
	
	cout<<"\n\n\n";
	
	eliminarElMedio_2(cab,b);
	imprimir(cab);
	
	return 0;
}
