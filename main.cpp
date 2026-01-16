#include <iostream>
#include "tarjetas.h"
#include <locale.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    cout << "=== PRUEBA DEL SISTEMA ===\n" << endl;
    
    // Crear tarjeta - CORRECTO: número, nombre, ingreso (número)
    TarjetaCredito miTarjeta("1914012717", "Damian Tipantuña", 1000.0);
    
    cout << "\nPrueba completada!" << endl;
    return 0;
}