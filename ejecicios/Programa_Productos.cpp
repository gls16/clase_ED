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

void descuento ( Producto &p){
	p.pre = p.pre - (p.pre * 0.15);
	cout<< p.nom <<" ahora vale: "<<p.pre<<endl;
}

string comparar_2(Producto p, Producto q){
	if (p.pre > q.pre)
		return p.nom;
	else if (p.pre < q.pre)
		return q.nom;
	else
		cout<<"El precio de los productos son iguales";
}
int main(){
	
	Producto pr1;
	Producto pr2;
	
	pr1.nom = "papa";
	pr1.pre = 3000;
	
	mostrarProducto(pr1);
	
	pr2.nom = "Arroz";
	pr2.pre = 5000;
	
	//comparar(pr1, pr2);	
	
	cout<<"el mas caro es "<<comparar_2(pr1, pr2)<<endl;
	
	descuento(pr1);
	descuento(pr2);
	mostrarProducto(pr1);
	mostrarProducto(pr2);
}
