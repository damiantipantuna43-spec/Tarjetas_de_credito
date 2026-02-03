#include <iostream>
#include "tarjetas.h"
#include <locale.h>
#include "clientes.h"
#include "sistema.h"
#include "archivos.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    cout << "=== SISTEMA DE TARJETA DE CREDITO ===\n" << endl;
    Sistema sistema;
    sistema.cargarClientesDesdeArchivo();
    sistema.ejecutar();
    Archivos::guardarClientes(sistema.getClientes());
    Archivos::guardarTarjetas(sistema.getClientes());
    cout << "\n=== DATOS GUARDADOS EXITOSAMENTE :D ===" << endl;
    cout << "1. clientes.csv" << endl;
    cout << "2. tarjetas.csv" << endl;
    return 0;
}