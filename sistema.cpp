#include "sistema.h"
#include "tarjetas.h"
#include "clientes.h"
#include <iostream>
#include <vector>

using namespace std;

void Sistema::ejecutar(){
int opcion;
cout << "\t===BIENVENIDO AL SISTEMA DE TARJETAS DE CREDITO===\t"<<endl;
do{
    cout <<"1. Registrarse como cliente "<<endl;
    cout <<"2. Crear Tarjeta "<<endl;
    cout <<"3. Realizar Compra "<<endl;
    cout <<"4. Realizar Pago "<<endl;
    cout <<"5. Mostrar informacion cliente "<<endl;
    cout <<"6. Salir "<<endl;
    cout <<"Seleccione opcion:"<<endl;
    cin >> opcion;
switch (opcion){
    case 1:
    crearCliente();
    break;

    case 2:
    crearTarjeta();
    break;
   
    case 3:
    realizarCompra();
    break;

    case 4:
    
    break;

    case 5:
    
    break;

    case 6:
    cout <<"Saliendo..."<<endl;
    break;
    default:
    cout <<"Opcion Invalida"<<endl;
}
}while(opcion !=6);
}

void Sistema::crearCliente(){
string id, nombre;
double ingresos;

cout <<"\t== Registrarse como Cliente==\t"<<endl;
cout << "ID del cliente: "<<endl;
cin >> id;

cout << "Nombre Completo: "<<endl;
cin.ignore();
getline(cin,nombre);

cout <<"Ingresos Mensuales $: "<<endl;
cin >> ingresos;

Cliente* nuevoCliente = new Cliente(id,nombre,ingresos);
clientes.push_back(nuevoCliente);


cout << "\t==Registro exitoso==\t"<<endl;
cout << "ID: "<<id<<"Nombre:"<<nombre<<endl;
}
void Sistema::crearTarjeta(){
    if(clientes.empty()){
        cout <<"No hay clientes registrados: "<<endl;
        return;
    }
    string idCliente,numero;
    cout<< "\t==Crear Tarjeta==\t"<< endl;
    cout<<"Clientes disponibles: "<<endl;
    for(int i=0;i<clientes.size();i++){
        cout<<"ID: "<<clientes[i]->getId()<<" Nombre: "<<clientes[i]->getNombre()<<endl;
    }
    cout<<"ID del cliente: "<<endl;
    cin >> idCliente;
    cout<<"Numero de Tarjeta: "<<endl;
    cin>>numero;
    
    if (clientes.size()>0){
        Cliente* cliente = clientes[0];
        TarjetaCredito* nuevaTarjeta = new TarjetaCredito(numero,cliente->getNombre(),cliente->getIngresos());    
        cliente->agregarTarjeta(nuevaTarjeta);
        cout <<"Tarjeta de Credito creada exitosamente: "<<endl;
    }
}


void Sistema::realizarCompra(){
if(clientes.empty()){
cout<<"No hay clientes registrados. "<<endl;
return;
}

for(int i=0;i<clientes.size();i++){
cout << i+1 << ". " << clientes[i]->getNombre() << endl;
}

int opcion;
cout << "Ingrese el digito que corresponde al cliente: " << endl;
cin >> opcion;
  if (opcion < 1 || opcion > clientes.size()) {
    cout << "Opción inválida" << endl;
    return;
}
 Cliente* cliente = clientes[opcion-1]; 
if(cliente->getTarjetas().empty()){
cout <<"El cliente no tiene tarjetas registradas. "<<endl;
return;
}

cout << "Tarjetas del usuario: "<< cliente->getNombre()<< endl;
for(int i=0;i<cliente->getTarjetas().size();i++){
cout << i+1 << ". " << cliente->getTarjetas()[i]->getNumero() << endl;
}

int opcionTarjeta;
cout<<"Ingrese el digito de la tarjeta: "<<endl;
cin>>opcionTarjeta;

 if (opcionTarjeta < 1 || opcionTarjeta > cliente->getTarjetas().size()) {
    cout << "Opción inválida" << endl;
    return;
}

TarjetaCredito* tarjeta = cliente->getTarjetas()[opcionTarjeta-1];

double monto;
string categoria;

cout<< "Ingrese el Monto de la compra $: "<<endl;
cin>>monto;
cout<<"ingrese la categoria de las siguientes opciones: "<<endl;
cout<<"ENTRETENIMIENTO/COMIDA/SALUD/EDUCACION"<<endl,
cin >>categoria;
bool exito = tarjeta->comprar(monto, categoria);

if(true){
cout<<"Compra Realizada con exito: "<<endl;
}else{
cout<<"La compra no se pudo realizar: "<<endl;
}

}