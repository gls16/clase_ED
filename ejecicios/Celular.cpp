# include<iostream>
using namespace std;
struct celular {
	string marca;
	int id;
	celular* sig;
};

void insertar (celular*& cab, string marca, int id){
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
	
	imprimir (cab);
	
	  cout << "Ingrese la marca del celular "<< endl;
	  cin>> marca;
	  cout << "Ingrese el id del celular "<< endl;
	  cin >> id;
	  
	cout<<"Ingrese el celular a buscar: "<<endl;
	cin>>b;
	
	insertarenelmedio (cab, marca, id, b);
	imprimir(cab);
	
	return 0;
}
