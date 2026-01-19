#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
using namespace std;
class TarjetaCredito;
class Cliente;


class Sistema{
private:
    vector <Cliente*> clientes;

public:
    void ejecutar();
    void crearCliente();
    void crearTarjeta();
};
#endif