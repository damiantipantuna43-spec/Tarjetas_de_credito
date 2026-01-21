#include <iostream>
#include "tarjetas.h"
#include <locale.h>
#include "clientes.h"
#include "sistema.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");
    cout << "=== PRUEBA DEL SISTEMA ===\n" << endl;
    Sistema sistema;
    sistema.ejecutar();
    return 0;
}