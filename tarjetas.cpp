/* Aqui estan ya las funciones y procedimientos que van a manejar las tarjetas de credito
estas funciones usan las variables locales que se definieron en la clase tarjetas.h
*/
#include "tarjetas.h"
#include <cmath>
#include <iostream>
using namespace std;
// Constructor anteriormente mencionado en tarjetas.h
/*inicializamos variables locales dandoles valores para usarlos en las siguientes funciones o procedimientos*/
TarjetaCredito::TarjetaCredito(string  num,string tit, double ingresoMensual){
numero = num;
titular = tit;
/*Calculo del CupoMaximo con el ingreso del usuario
El calculo basico es: ingresoMensual * 0.35, redondeado hacia arriba a multiplos de 50*/
double cupoCalculado = ingresoMensual * 0.35;
cupoMaximo = ceil(cupoCalculado/50) * 50;

if(cupoMaximo < 300){
cupoMaximo = 300;
}

saldoActual = 0;
estado = "ACTIVA";

cout << "Tarjeta de credito creada para el titular: " << titular << endl;
}

double TarjetaCredito::getSaldo() const {
    return saldoActual;
}

double TarjetaCredito::getCupoDisponible() const{
    return cupoMaximo - saldoActual;
}

string TarjetaCredito::getNumero() const{
    return numero;
}

string TarjetaCredito::getEstado() const{
    return estado;
}

void TarjetaCredito::bloquearTarjeta(){
    estado = "BLOQUEADA";
    cout << "Tarjeta bloqueada Exitosamente." << endl;
}

void TarjetaCredito::desbloquearTarjeta(){
    estado = "ACTIVA";
    cout << "Tarjeta Activada Exitosamente." << endl;
}

double TarjetaCredito::calcularPagoMinimo() const {
    double pagoMinimo = saldoActual * 0.05;
    if (pagoMinimo < 25){
        pagoMinimo = 25;
    }
    return pagoMinimo;
}

bool TarjetaCredito::comprar(double monto, string categoria){
    if(estado != "ACTIVA"){
        cout << "La compra no puede ralizarse. La tarjeta esta bloqueada." << endl;
        return false;
    }

     if(categoria == "ENTRETENIMIENTO"){
            monto = monto * 0.95;
        }if(categoria == "COMIDA"){
            monto = monto *0.9;
        }if (categoria == "SALUD"){
            monto = monto * 0.85;
        }if (categoria == "EDUCACION"){
            monto = monto *0.8;
        }
     if (monto > getCupoDisponible()){
        cout << "La compra no puede ralizarse. Cupo insuficiente." << endl;
        return false;
     }
        saldoActual += monto;
        cout << "Compra realizada por un monto de $" << monto << ". Saldo actual: $" << saldoActual << endl;
        return true;
}
    
void TarjetaCredito::mostrarInformacion() const {
    cout <<"Numero de Tarjeta: " << numero << endl;
    cout << "Titular: " << titular << endl;
    cout << "Cupo Maximo: $" << cupoMaximo << endl;
    cout << "Saldo Actual: $" << saldoActual << endl;
    cout << "Cupo Disponible: $" << getCupoDisponible() << endl;
    cout << "Estado: " << estado << endl;
    cout << "Pago Minimo Requerido $: " << calcularPagoMinimo() << endl;
}
   