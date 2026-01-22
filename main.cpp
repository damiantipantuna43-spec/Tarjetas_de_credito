#include <iostream>
#include "tarjetas.h"
#include <locale.h>
#include "clientes.h"
#include "sistema.h"
#include "archivos.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    cout << "=== PRUEBA DEL SISTEMA ===\n" << endl;
    Sistema sistema;
    sistema.cargarClientesDesdeArchivo();
    sistema.ejecutar();
    Archivos::guardarClientes(sistema.getClientes());
    return 0;
}