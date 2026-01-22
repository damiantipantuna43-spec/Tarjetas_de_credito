#include "archivos.h"
#include <fstream>
#include <iostream>
using namespace std;

void Archivos::guardarClientes(const vector<Cliente*>& clientes) {
    ofstream archivo("clientes.csv");
    
    if (!archivo.is_open()) {
        cout << "Error al crear archivo" << endl;
        return;
    }
    
    archivo << "id,nombre,ingresos" << endl;

    for (Cliente* cliente : clientes) {
        archivo << cliente->getId() << ","
                << cliente->getNombre() << ","
                << cliente->getIngresos() << endl;
    }
    
    archivo.close();
    cout << "Clientes guardados en clientes.csv" << endl;
}

vector<Cliente*> Archivos::cargarClientes() {
    vector<Cliente*> clientes;
    ifstream archivo("clientes.csv");
    
    if (!archivo.is_open()) {
        cout << "No hay archivo previo, empezando nuevo." << endl;
        return clientes;  // Vector vacío
    }
    
    string linea;
    getline(archivo, linea);  // Saltar encabezado "id,nombre,ingresos"
    
    while (getline(archivo, linea)) {
        // Parsear línea CSV simple: id,nombre,ingresos
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            string id = linea.substr(0, pos1);
            string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            double ingresos = stod(linea.substr(pos2 + 1));
            
            // Crear cliente
            Cliente* nuevoCliente = new Cliente(id, nombre, ingresos);
            clientes.push_back(nuevoCliente);
        }
    }
    
    archivo.close();
    cout << "✓ " << clientes.size() << " clientes cargados." << endl;
    return clientes;
}