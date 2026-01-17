#ifndef TARJETAS_H
#define TARJETAS_H
#include <string>

// Plan con uso de clases son el fin de modular mejor el codigo y encapsular datos, de este modo la libreria es mucho mas limpia
//ordenada y facil de mantener.
class TarjetaCredito {
    // estos datos son los que van a manejar las tarjetas de credito
private:
    std::string numero;
    std::string titular;
    double cupoMaximo;
    double saldoActual;
    std::string estado;

public:
//constructor o tambien llamado funcion iniciadora para que se entienda mejor es solo guardar los datos iniciales
// en variables locales para usarlos en todas las funciones siguientes ejemplo num se guardo en numero en tarjetas.cpp

TarjetaCredito(std::string num,std::string tit,double ingresoMensual);

//metodos mas usados
// son los que voy a usar a futuro cuando haga un menu de interaccion solo necesito la libreria

bool comprar(double monto,std::string categoria);
void pagar(double monto);
void mostrarInformacion() const;

//Cuidado de los usuarios
//Son datos de la tarjeta de los usuarios estos no se modifican ya que solo returnan valores 
// para estan los demas metodos que usan variables locales que estas funciones usan para 
// ver como varian los datos
double getSaldo() const;
double getCupoDisponible() const;
std::string getNumero() const;
std::string getEstado() const;

//Control de estados
// procedimientos que cambian el estado de la tarjeta estas se encargan de dar acceso a las funciones
//anteriores unicialmente empieza siempre la tarjeta ACTIVADA
void bloquearTarjeta();
void desbloquearTarjeta();

//calculos
//solo es un calculo matematico del saldo que se va a ir acumulando

double calcularPagoMinimo() const;

};
#endif