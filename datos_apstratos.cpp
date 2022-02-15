#include <iostream>
using namespace std;

struct Punto{
	int x;
	int y;
};

void mostrarPunto (Punto p){
	cout<<"Punto "<<" ("<< p.x <<", "<< p.y <<")"<<endl;
}

void cuadrante (Punto p){
	if (p.x > 0 && p.y > 0)
		cout<<"Esta en el cuadrante 1"<<endl;
	
	else if (p.x < 0 && p.y > 0)
		cout<<"Esta en el cuadrante 2"<<endl;
	
	else if (p.x > 0 && p.y < 0)
		cout<<"Esta en el cuadrante 4"<<endl;
	
	else if (p.x > 0 && p.y > 0)
		cout<<"Esta en el cuadrante 3"<<endl;
}

/*void ejex (Punto p){
	if (p.x == 0)
	cout<<"eje x"<<endl;		
}
*/

bool ejex (Punto p){
	if (p.x == 0)
		return true;
	else 
		return false;
}

/*void ejey (Punto p){
	if(p.y == 0)
	cout<<"eje y"<<endl;
}
*/

bool ejey(Punto p){
	if (p.y == 0)
		return true;
	else 
		return false;
}

/*void origen (Punto p){
	
	if(p.x == 0 && p.y == 0)
	cout<<"origen"<<endl;
}
*/

bool origen (Punto p){
	if (p.x == 0 && p.y == 0)
		return true;
	else 
		return false;
}

int main(){
	
	Punto a;
	
	int z;
	
	a.x = 89;
	a.y = 54;
	
	//cout<<a<<endl;
	cout<<a.x<<endl;
	cout<<a.y<<endl;
	
	Punto b;
	cout<<"ingrese el valor de x para punto b: "<<endl;
	cin>>z;
	b.x=z;

	cout<<"ingrese el valor de y para punto b: "<<endl;
	cin>>z;
	b.y=z;
	
	cout<<"Punto a ("<<a.x<<", "<<a.y<<")"<<endl;
		
	cout<<"Punto b ("<<b.x<<", "<<b.y<<")"<<endl;
	
	
	Punto c;
	cout<<"ingrese el valor de x para punto c: "<<endl;
	cin>>c.x;

	cout<<"ingrese el valor de y para punto c: "<<endl;
	cin>>c.y;
	
	//cout<<"Punto c ("<<c.x<<", "<<c.y<<")"<<endl;
	
	/*

	mostrarPunto(a);
	mostrarPunto(b);
	*/
	mostrarPunto(c);
	
	// --------------------------------------------
	
	/*
	
	cuadrante(a);
	cuadrante(b);
	cuadrante(c);
	
	*/
	
	// --------------------------------------------
	
	/*
	
	cuadrante(c);
	ejex(c);
	ejey(c);
	origen(c);
	
	*/
	
	// --------------------------------------------
	
	if (origen(c) == true)
		cout<<"Origen"<<endl;
	else if(ejex(c) == true)
		cout<<"Eje x"<<endl;
		
	else if(ejey(c) == true)
		cout<<"Eje y"<<endl;
	else
		cuadrante(c);
			
	return 0;
}
