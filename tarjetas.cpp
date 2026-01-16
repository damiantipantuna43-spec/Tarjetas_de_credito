#include "tarjetas.h"
#include <cmath>
#include <iostream>
using namespace std;

TarjetaCredito::TarjetaCredito(string num,string tit, double ingresoMensual){
cout << "Ingrese el numero de la tarjeta: " << endl;
cin >> num;
cout << "Ingrese el titular de la tarjeta: " << endl;
cin >> tit;

cout << "Ingrese el ingreso mensual: " << endl;
cin >> ingresoMensual;
double cupoMaximo = ingresoMensual * 0.35;
double cupoRedondeado = ceil(cupoMaximo/50) * 50;
if(cupoRedondeado<300){
    cupoRedondeado = 300;
}

double saldoActual = 0;
cout << "Su estado inicial es: " << endl;
cout << "Activa" << endl;
cout << "Tarjeta creada para el titular: "<<tit<<endl;

}

int main(){
    int num;
    string tit;
    double ingresoMensual;
    TarjetaCredito(num, tit, ingresoMensual);


    return 0;
}

