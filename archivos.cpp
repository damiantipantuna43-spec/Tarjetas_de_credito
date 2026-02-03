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
    getline(archivo, linea);  // Salta el encabezado "id,nombre,ingresos" es decir no escribe ahi
    
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
    cargarTarjetas(clientes);
    
    cout << "✓ " << clientes.size() << " clientes y sus tarjetas cargados." << endl;

    return clientes;
}

void Archivos::guardarTarjetas(const vector<Cliente*>& clientes) {
    ofstream archivo("tarjetas.csv");
    
    if (!archivo.is_open()) {
        cout << "Error al crear archivo tarjetas.csv" << endl;
        return;
    }
    
    // Encabezado del archivo
    archivo << "Cedula ,numero,titular,cupoMaximo,saldoActual,estado" << endl;

    for (Cliente* cliente : clientes) {
        string cliente_id = cliente->getId();
        vector<TarjetaCredito*>& tarjetas = cliente->getTarjetas();
        
        for (TarjetaCredito* tarjeta : tarjetas) {
            archivo << cliente_id << ","
                    << tarjeta->getNumero() << ","
                    << cliente->getNombre() << ","
                    << tarjeta->getCupoMaximo() << ","
                    << tarjeta->getSaldo() << ","
                    << tarjeta->getEstado() << endl;
        }
    }
    
    archivo.close();
    cout << "Tarjetas guardadas en tarjetas.csv" << endl;
}

void Archivos::cargarTarjetas(vector<Cliente*>& clientes) {
    ifstream archivo("tarjetas.csv");
    
    if (!archivo.is_open()) {
        cout << "No hay archivo de tarjetas previo." << endl;
        return;
    }
    
    string linea;
    getline(archivo, linea);  // Saltar encabezado
    
    int tarjetasCargadas = 0;
    
    while (getline(archivo, linea)) {
        // Parsear línea: cliente_id,numero,titular,cupoMaximo,saldoActual,estado
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);
        size_t pos4 = linea.find(',', pos3 + 1);
        size_t pos5 = linea.find(',', pos4 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos && 
            pos3 != string::npos && pos4 != string::npos && pos5 != string::npos) {
            
            string cliente_id = linea.substr(0, pos1);
            string numero = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            string titular = linea.substr(pos2 + 1, pos3 - pos2 - 1);
            double cupoMaximo = stod(linea.substr(pos3 + 1, pos4 - pos3 - 1));
            double saldoActual = stod(linea.substr(pos4 + 1, pos5 - pos4 - 1));
            string estado = linea.substr(pos5 + 1);
            
            // Buscar el cliente por ID
            Cliente* clienteDestino = nullptr;
            for (Cliente* cliente : clientes) {
                if (cliente->getId() == cliente_id) {
                    clienteDestino = cliente;
                    break;
                }
            }
            
            if (clienteDestino) {
                // Crear la tarjeta (necesitamos modificar TarjetaCredito para aceptar estos parámetros)
                TarjetaCredito* tarjeta = new TarjetaCredito(numero, titular, cupoMaximo/0.35); // Estimamos ingresos
                // Ajustar saldo y estado (necesitamos setters)
                // Aquí necesitarás agregar setters en TarjetaCredito
                tarjeta->setSaldo(saldoActual);
                tarjeta->setEstado(estado);
                
                clienteDestino->agregarTarjeta(tarjeta);
                tarjetasCargadas++;
            }
        }
    }
    
    archivo.close();
    cout << "✓ " << tarjetasCargadas << " tarjetas cargadas." << endl;
}