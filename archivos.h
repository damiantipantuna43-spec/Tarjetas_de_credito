#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "clientes.h"
#include <vector>
using namespace std;

class Archivos {
public:
    static void guardarClientes(const vector<Cliente*>& clientes);
    static void guardarTarjetas(const vector<Cliente*>& clientes); 
    static vector<Cliente*> cargarClientes();
    static void cargarTarjetas(vector<Cliente*>& clientes);
    static void guardarTodo(const Sistema& sistema);
    static Sistema cargarTodo();
};

#endif