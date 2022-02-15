#include <iostream>
using namespace std;

struct Rombo{

    int diagonalMay;
    int diagonalMen;

};

void calcularArea(Rombo q){
    int resultado;

    resultado = (q.diagonalMay * q.diagonalMen)/2;
    cout<<"El area del resultado es : "<<resultado<<endl;
}

int calcularArea_2(Rombo q){
    int resultado;

    resultado = (q.diagonalMay * q.diagonalMen)/2;
    return resultado;
}


void compararAreas(Rombo q, Rombo p){
    if (calcularArea_2(q) > calcularArea_2(p))
        cout<<"Es mas grande";
    else if (calcularArea_2(q) < calcularArea_2(p))
        cout<<"Es mas grande";
}

int main(){

    Rombo a;
    Rombo b; 

    // ingrese las variables
    cout<<"Ingrese la diagonal mayor: ";
    cin >> a.diagonalMay;

    cout<<"Ingrese la diagonal menor: ";
    cin >> a.diagonalMen;

    cout<<"Ingrese la diagonal mayor: ";
    cin >> b.diagonalMay;

    cout<<"Ingrese la diagonal menor: ";
    cin >> b.diagonalMen;

    calcularArea(a);
}
