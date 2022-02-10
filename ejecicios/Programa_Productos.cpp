#include <iostream>

using namespace std;

struct Producto{
	string nom;
	float pre;
};

void mostrarProducto( Producto p){
	cout<<p.nom<<endl;
	cout<<p.pre<<endl;
	
}

void comparar( Producto p, Producto q){
	if (p.pre > q.pre)
		cout<<"El producto: "<<p.nom<<" es mas caro que" <<q.nom<<endl;
	else if (p.pre < q.pre)
		cout<<"El producto: "<<q.nom<<" es mas caro que "<<p.nom<<endl;
	else
		cout<<"El precio de los productos son iguales";
}

string comparar_2(Producto p, Producto q){
	if (p.pre > q.pre)
		return p.nom;
	else if (p.pre < q.pre)
		return q.nom;
	else
		cout<<"El precio de los productos son iguales";
}

void descuento ( Producto p){
	p.pre = p.pre - (p.pre * 0.15);
	cout<< p.nom <<" ahora vale con el descuento: "<<p.pre<<endl;
}

void iva ( Producto &p){
	p.pre = p.pre + (p.pre * 0.19);
	cout<< p.nom <<" ahora vale con el iva: "<<p.pre<<endl;
}

float iva_2 ( Producto &p){
	p.pre = p.pre + (p.pre * 0.19);
	return p.pre;
}

Producto comparador_menor( Producto &p, Producto &q){
	if (p.pre > q.pre)
		return q;
	else if (p.pre < q.pre)
		return p;
	else
		cout<<"El precio de los productos son iguales";
}



int main(){
	
	Producto pr1;
	Producto pr2;
	Producto aux;
	Producto *v;
	
	v = &pr1;
	
	pr1.nom = "papa";
	pr1.pre = 3000;
	
	pr2.nom = "Arroz";
	pr2.pre = 5000;
	

	mostrarProducto(pr1);
	
	comparar(pr1, pr2);	
	
	cout<<"el mas caro es "<<comparar_2(pr1, pr2)<<endl;
	
	descuento(pr1);
	iva_2(pr1);
	
	descuento(pr2);
	iva_2(pr2);
	
	mostrarProducto(pr1);
	mostrarProducto(pr2);

	aux = comparador_menor(pr1, pr2);
	mostrarProducto(aux);
	
	cout<<v->nom<<endl;

// [ -> ] : 1operador de acceso

	Producto*v2=new Producto;
	cout<<v2->pre;
	
	return 0;
}
