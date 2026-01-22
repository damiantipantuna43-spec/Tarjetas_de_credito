#include "clientes.h"
#include <iostream>
#include <string>
#include <vector>
#include "tarjetas.h"
#include "sistema.h"
using namespace std;

Cliente::Cliente(string idCliente, string nombreCliente,double ingresosCliente){
id = idCliente;
nombre = nombreCliente;
ingresosMensuales = ingresosCliente;
}

void Cliente::agregarTarjeta(TarjetaCredito* misTarjetas){
tarjetas.push_back(misTarjetas);
}



void Cliente::mostrarInfo() const {
    cout << "=== Informacion del Cliente: ===" << endl;
    cout << "ID:" << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Ingresos Mensuales: $" << ingresosMensuales << endl;
    cout << "Tarjetas de Credito Asociadas: "<< tarjetas.size() << endl;

    if (tarjetas.size() > 0){
        cout << "== Tarjetas ==" << endl;
        for (int i=0; i < tarjetas.size();i++){
            cout << "Tarjeta #" << i+1 << endl;
            tarjetas[i]->mostrarInformacion();
        }
    }
}

double Cliente::getIngresos() const {
    return ingresosMensuales;
}
string Cliente::getId() const{
    return id;
}
string Cliente::getNombre() const{
    return nombre;
}

vector<TarjetaCredito*>& Cliente::getTarjetas() {
    return tarjetas;
}
