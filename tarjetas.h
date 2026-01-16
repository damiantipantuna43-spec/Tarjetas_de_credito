#ifndef TARJETAS_H
#define TARJETAS_H
#include <string>


class TarjetaCredito {
private:
    std::string numero;
    std::string titular;
    double cupoMaximo;
    double saldoActual;
    std::string estado;

public:
//constructor
TarjetaCredito(std::string num,std::string tit,double ingresoMensual);

//metodos mas usados
bool comprar(double monto,std::string categoria);
void pagar(double monto);
void mostrarInformacion() const;

//Cuidado de los usuarios
double getSaldo() const;
double getCupoDisponible() const;
std::string getNumero() const;
std::string getEstado() const;

//control de estados 
void bloquearTarjeta();
void desbloquearTarjeta();

//calculos

double calcularPagoMinimo() const;

};
#endif