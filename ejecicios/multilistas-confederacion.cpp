#include <iostream>
using namespace std;

struct seleccion{   //Struct para las sublistas
	string nombre;
	int copas;
	seleccion * sig;
};

struct confederacion{  //Se crea el struct para la lista principal de todas las demas sublistas.
	string nombre;
	confederacion * sig;
	seleccion * sub;
};

void insertarConf(confederacion *&cab, string n){
	confederacion * nuevo = new confederacion;
	nuevo->nombre = n;
	nuevo->sub = NULL;
	
	if(cab!=NULL){
	    nuevo->sig= cab;
	}
    else{
	    nuevo->sig=NULL;
	}
	cab = nuevo;
}

void mostrarConf(confederacion* cab){
	confederacion * aux = cab;

	while(aux!=NULL){
    	cout<<"Confederacion: "<<aux->nombre<<endl;
    	aux= aux->sig;
	}
	cout<<endl;

}

void insertarSelec(seleccion*& cab, string n, int c){
	seleccion * nuevo = new seleccion;
	nuevo->nombre = n;
	nuevo->copas=c;

	if(cab!=NULL){
		nuevo->sig= cab;
	}
    else{
		nuevo->sig=NULL;
	}
	cab = nuevo;
}

void eliminarseleccioncab(seleccion* &cab){
	seleccion* aux=cab;
	cab=aux->sig;
	delete aux; 
}
void eliminarmedio(seleccion* cab,string n){
	seleccion* aux1=cab;
	seleccion* aux2;

	while(aux1->nombre!=n ){
    	aux2=aux1;
    	aux1=aux1->sig;
	}
	aux2->sig=aux1->sig;
    delete aux1;
	
}

void consultarConfederacion(confederacion* aux){
	seleccion* aux1= aux->sub;
	while(aux1!=NULL){
	    cout<<aux1->nombre<<endl;
	    aux1=aux1->sig; 
	} 
}

confederacion* buscarConf(confederacion* cab, string n){
	confederacion* aux=cab;
	
	while(aux->nombre!=n){
		aux=aux->sig;	 
	}
	return aux;
}

void mostrarTodo(confederacion * cab){
	confederacion * aux1 = cab;
	seleccion* aux2;
	while(aux1!=NULL){
		cout<<"Confederacion: "<<aux1->nombre<<endl;
		aux2 =aux1->sub;
		while(aux2!=NULL){
			cout<<aux2->nombre<<" copas "<<aux2->copas<<endl;
			aux2 = aux2->sig;cout<<endl;
		}
		aux1 =aux1->sig;
		cout<<endl;
	}
}
int contarselecciones(seleccion*cab){
int contador=0;
seleccion* aux=cab;
while(aux!=NULL){
contador++;
aux=aux->sig; 
}
return contador;
}

int totalCopas(confederacion* cab){
	confederacion * aux1 = cab;
	seleccion* aux2;
	int total=0;
	while(aux1!=NULL){
		aux2 =aux1->sub;
		while(aux2!=NULL){
			total=total+aux2->copas;
			aux2 = aux2->sig;
		}
		aux1 =aux1->sig;
		
	}
	return total;
}

string mayorConf(seleccion* cab){
	int mayor=-1;
	seleccion* aux=cab,* aux2;
	while(aux!=NULL){
		if(aux->copas>mayor){
			mayor=aux->copas;
			aux2=aux;
			}
		aux=aux->sig;		
	}
	return aux2->nombre;
}

seleccion* buscarSelec(confederacion* cab, string nom){
	confederacion * aux1 = cab;
	seleccion* aux2;
	while(aux1!=NULL){
		aux2 =aux1->sub;
		while(aux2!=NULL){
			if(aux2->nombre==nom){
				return aux2;
			}
			aux2=aux2->sig;	
		}
		aux1 =aux1->sig;		
	}	
    
}

void menu(){
	cout<<"Seleccione una opcion"<<endl;
	cout<<"0.Salir"<<endl;
	cout<<"1.Mostrar todas la selecciones"<<endl;
	cout<<"2.Mostrar la selecciones de una confederacion"<<endl;
	cout<<"3.Eliminar una seleccion"<<endl;
	cout<<"4.Contar la cantidad de selecciones de una confederacion"<<endl;
	cout<<"5.Contar todas las copas"<<endl;
	cout<<"6.Mostrar la seleccion que mas copas ha ganada en una confederaci�n seleccionada"<<endl;
	cout<<"7.Asignar titulo a una seleccion (sumar una copa)"<<endl;
}


int main(){
	setlocale(LC_ALL, "");
	confederacion * cab = NULL;
	confederacion * aux;
	seleccion* aux2;
	string n;
	int cont,c,op=1;
	
	string conf[6]={"UEFA","CONCACAF","CONMEBOL","AFC","OFC","CAF"};
	
	for(int i=0;i<=5;i++){
		insertarConf(cab, conf[i]);
	}
	mostrarConf(cab);
	aux = cab;
	
	for(int i=1;i<=6;i++){
		cout<<"Cuantas selecciones estan en "<<aux->nombre<<endl;
		cin>>cont;
		for(int j = 1; j<=cont;j++){
		cout<<"Ingrese el nombre de la seleccion: "<<endl;
		cin>>n;
		cout<<"Ingrese la cantidad de copas de la seleccion: "<<endl;
		cin>>c;
		insertarSelec(aux->sub, n,c);
	}
	aux =aux->sig;
	}
	mostrarTodo(cab);
	
	while(op!=0){
		menu();
		cin>>op;
		switch(op) {
			
			case 0:
				cout<<"Fin del programa"<<endl;
				break;
			case 1:
				mostrarTodo(cab);
				break;
			case 2:
				cout<<"escriba el nombre de la confederacion a buscar"<<endl;
				cin>>n;
				aux=buscarConf(cab,n);
				consultarConfederacion(aux);	
				break;
			case 3:
				cout<<"escriba el nombre de la confederacion a buscar"<<endl;
				cin>>n;
				aux=buscarConf(cab,n);
				cout<<"seleccione la seleccion que quiere eliminar"<<endl;
				consultarConfederacion(aux);
				cin>>n;	
				if(aux->sub->nombre==n){
					eliminarseleccioncab(aux->sub);
				}else{
					eliminarmedio(aux->sub,n);					
				}
				break;
			case 4:
				cout<<"escriba el nombre de la confederacion a buscar"<<endl;
				cin>>n;
				aux=buscarConf(cab,n);
				cout<<"cantidad de selcciones "<<contarselecciones(aux->sub)<<endl;				
				break;
			case 5:
				cout<<"Total de copas "<<totalCopas(cab)<<endl;
				break;	
			case 6:
				cout<<"escriba el nombre de la confederacion a buscar"<<endl;
				cin>>n;
				aux=buscarConf(cab,n);
				cout<<"la seleccion con mas copas es "<<mayorConf(aux->sub)<<endl;			
				break;
			case 7:
				cout<<"escriba el nombre de la seleccion"<<endl;
				cin>>n;
				aux2=buscarSelec(cab,n);
				aux2->copas++;
				
				break;
			
			default:
				cout<<"Opcion equivocada"<<endl;
	}
		
}	
	return 0;
	
}
