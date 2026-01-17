#include <iostream>
#include "tarjetas.h"
#include <locale.h>
#include "clientes.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    cout << "=== PRUEBA DEL SISTEMA ===\n" << endl;
    // Crear Cliente
    Cliente cliente("001", "Hola soy el cliente XD", 200.0);
    // Crear tarjeta - CORRECTO: número, nombre, ingreso (número)
    TarjetaCredito tarjeta1("2846 3647 5843 4353", "El Cliente XDD", 1000.0);
    //Tarjeta al cliente
    cliente.agregarTarjeta(&tarjeta1);
    // mostrar info cliente
    cliente.mostrarInfo();
    return 0;
}