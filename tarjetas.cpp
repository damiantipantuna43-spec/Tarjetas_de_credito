#include "tarjetas.h"
#include <cmath>
#include <iostream>
using namespace std;

TarjetaCredito::TarjetaCredito(string  num,string tit, double ingresoMensual){
numero = num;
titular = tit;

double cupoCalculado = ingresoMensual * 0.35;
cupoMaximo = ceil(cupoCalculado/50) * 50;

if(cupoMaximo < 300){
cupoMaximo = 300;
}

saldoActual = 0;
estado = "Activa";

cout << "Tarjeta de credito creada para el titular: " << titular << endl;
}

