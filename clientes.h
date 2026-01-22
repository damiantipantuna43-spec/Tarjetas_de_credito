#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include <vector>
#include "tarjetas.h"
#include "clientes.h"
#include "sistema.h"


class Cliente{
private:
    std::string id;
    std::string nombre;
    double ingresosMensuales;
    //tarjetas del cliente
    std::vector < TarjetaCredito* > tarjetas;
public:
    Cliente(std::string id, std::string nombre, double ingresosMensuales);
    void agregarTarjeta(TarjetaCredito* tarjetas);
    void mostrarInfo() const;
    double getIngresos() const;
    string getId() const;
    string getNombre() const;
    vector<TarjetaCredito*>& getTarjetas();
};
#endif