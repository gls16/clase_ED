# include<iostream>
using namespace std;

struct votacion{
	string nompuesto;
	int nummesa;
	
	votacion* sig;// Con esto iniciamos el enlace de los nodos
	
};

void crear(votacion* &cab, int n, string p){
	votacion* nuevo= new votacion;
	nuevo->nummesa=n;
	nuevo->nompuesto=p;
	
	nuevo->sig=NULL;
	cab=nuevo;
	
}
void insertar(votacion* &cab, int n,string p){
	votacion* nuevo= new votacion;
	nuevo->nummesa=n;
	nuevo->nompuesto=p;
	
	nuevo->sig=cab;
	cab=nuevo;
	
}

void insertaf(votacion* &fin, int n, string p){
	
	votacion* nuevo= new votacion;
	nuevo->nummesa=n;
	nuevo->nompuesto=p;
	nuevo->sig=NULL;
	fin->sig=nuevo;
	fin=nuevo;
}

void imprimir(votacion*cab){
	votacion* aux=cab;
	while(aux!=NULL){
		cout<<"Puesto = "<<aux->nompuesto<<endl;
		cout<<"Mesa = "<<aux->nummesa<<endl;
		cout<<"----------------------------------"<<endl;
		
		aux=aux->sig;
	}
}
void mesasxpuestos(votacion* cab,string p){
	votacion* aux=cab;
	while(aux!=NULL){
	 if(aux->nompuesto==p){ 
	 cout<<aux->nummesa<<endl;
}
	aux=aux->sig;
	}
	
	}
int contadorMesas(votacion* cab, string m){
	votacion* aux=cab;
	int contador=0;
		while(aux!=NULL){
	 if(aux->nompuesto==m){
	 contador++;
	}
	aux=aux->sig;
	}
	return contador;
}

int totalMesas(votacion* cab){
	votacion * aux=cab;
	int nummesa = 0;
		while (aux!=NULL){	
		nummesa = nummesa + 1;
		aux=aux->sig;
	}
	return nummesa;
}

int main(){

	votacion* cab=NULL;	
	string puesto;
	int nump;
	votacion* fin;
	
	cout<<"Ingrese el puesto de votacion = "<<endl;
	cin>>puesto;
	
	cout<<"Ingrese el numero de puesto de votacion = "<<endl;
	cin>>nump;
	
	crear(cab,nump,puesto);
	fin=cab;
	for(int i=0;i<=4;i++){
	cout<<"Ingrese el puesto de votacion ="<<endl;
	cin>>puesto;
	
	cout<<"Ingrese el numero de puesto de votacion ="<<endl;
	cin>>nump;
	insertar(cab,nump,puesto);
	
	}
	imprimir(cab);
	cout<<"Ingrese el puesto de votacion = "<<endl;
	cin>>puesto;
	
	cout<<"Ingrese el numero de puesto de votacion = "<<endl;
	cin>>nump;
	
	insertaf(fin,nump,puesto);
	imprimir(cab);
	cout<<"Escriba el puesto a buscar: "<<endl;
	cin>>puesto;
	mesasxpuestos(cab,puesto);
	cout<<"Escriba el puesto a buscar: "<<endl;
	cin>>puesto;
	cout<<"Cantidad de mesas en: "<<puesto<<" es "<<contadorMesas(cab,puesto)<<endl;
	
	cout<<"Total mesas:"<<totalMesas(cab)<<endl;
	
	return 0;
}
