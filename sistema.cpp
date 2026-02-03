#include "sistema.h"
#include "tarjetas.h"
#include "clientes.h"
#include "archivos.h"
#include <iostream>
#include <vector>

using namespace std;

void Sistema::ejecutar(){
setlocale(LC_ALL, "spanish");
int opcion;
int opcionMenu;
int contrasena=12345;
do{
    cout<<"============================================"<<endl;
    cout<<"           BIENVENIDO AL SISTEMA            "<<endl;
    cout<<"         Tarjetas de credito plus           "<<endl;
    cout<<"============================================"<<endl;
    cout<<""<<endl;
    cout<<"1. Modo Cliente"<<endl;
    cout<<"2. Modo Administrativo"<<endl;
    cout<<"3. Salir del sistema"<<endl;
    cin>>opcionMenu;
switch (opcionMenu){
case 1:
do{
    cout << "\t===BIENVENIDO AL SISTEMA DE TARJETAS DE CREDITO===\t"<<endl;
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
    realizarPago();
    break;

    case 5:
    mostrarInformacionCliente();
    break;

    case 6:
    cout <<"Saliendo..."<<endl;
    break;
    default:
    cout <<"Opcion Invalida"<<endl;
    break;
}
}while(opcion !=6);
break;
case 2:
//aqui todo xd
int contrasenausu;
int opcionadmin;
cout<<"Bienvenido al sistema administrativo"<<endl;
cout<<"Ingrese la contraseña para continuar:"<<endl;
cin>>contrasenausu;
if(contrasenausu == contrasena){
do{
cout<<"===Bienvenido al sistema administrativo==="<<endl;
cout<<"1. Ver datos de clientes."<<endl;
cout<<"2. Bloquear Tarjeta."<<endl;
cout<<"3. Desbloquear Tarjeta."<<endl;
cout<<"4. Eliminar Cliente."<<endl;
cout<<"5. Eliminar Tarjeta."<<endl;
cout<<"6. Salir"<<endl;
cin>>opcionadmin;

switch (opcionadmin){
case 1:
mostrarInformacionCliente();
break;

case 2:
bloquearTarjeta();
break;


case 3:
desbloquearTarjeta();
break;

case 4:
eliminarCliente();
break;

case 5:
eliminarTarjeta();
break;

case 6:
cout<<"Saliendo..."<<endl;
break;


default:
cout<<"Opcion Invalida vuelva a intentarlo";
    break;
}}while (opcionadmin!=6);}
break;

case 3:
cout<<"Saliendo del sistema..."<<endl;
break;

default:
cout<<"Opcion invalida. Ingrese de nuevo la opcion del menu.";
break;
}

}while(opcionMenu!=3);
}

void Sistema::crearCliente(){
string id, nombre;
double ingresos;

cout <<"\t== Registrarse como Cliente==\t"<<endl;
cout << "Cedula del cliente: "<<endl;
cin >> id;

cout << "Nombre Completo: "<<endl;
cin.ignore();
getline(cin,nombre);

cout <<"Ingresos Mensuales $: "<<endl;
cin >> ingresos;

Cliente* nuevoCliente = new Cliente(id,nombre,ingresos);
clientes.push_back(nuevoCliente);


cout << "\t===Registro exitoso===\t"<<endl;
cout << "ID: "<<id<<endl<<"Nombre:"<<nombre<<endl;
cout<<"==============================================="<<endl;
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
        cout<<i+1<<". Cedula: "<<clientes[i]->getId()<<" Nombre: "<<clientes[i]->getNombre()<<endl;
    }
    int opcion;
    cout << "Seleccione cliente (1-" << clientes.size() << "): ";
    cin >> opcion;
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "opcion inválida. Use números." << endl;
    return;
}

    if (opcion < 1 || opcion > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcion-1];

    if (opcion < 1 || opcion > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }

    cout<<"Numero de Tarjeta: "<<endl;
    cin.ignore();
    getline(cin, numero);
    
     TarjetaCredito* nuevaTarjeta = new TarjetaCredito(
        numero, 
        cliente->getNombre(),
        cliente->getIngresos()
    );

    cliente->agregarTarjeta(nuevaTarjeta);
    
    cout << "¡Tarjeta creada exitosamente para " 
     << cliente->getNombre() << "!" << endl;
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
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opcion inválida. Use números." << endl;
    return;
}
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
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opcion inválida. Use números." << endl;
    return;
}
 if (opcionTarjeta < 1 || opcionTarjeta > cliente->getTarjetas().size()) {
    cout << "Opción inválida" << endl;
    return;
}

TarjetaCredito* tarjeta = cliente->getTarjetas()[opcionTarjeta-1];

double monto;
string categoria;

cout<< "Ingrese el Monto de la compra $: "<<endl;
cin>>monto;
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Monto inválido. Use números." << endl;
    return;
}
cout<<"ingrese la categoria de las siguientes opciones: "<<endl;
cout<<"ENTRETENIMIENTO/COMIDA/SALUD/EDUCACION/OTRO"<<endl,
cin >>categoria;
bool exito = tarjeta->comprar(monto, categoria);

if(true){
cout<<"Compra Realizada con exito: "<<endl;
}else{
cout<<"La compra no se pudo realizar: "<<endl;
}

}

void Sistema::realizarPago(){

if(clientes.empty()){
cout<<"No hay clientes registrados. "<<endl;
return;
}

cout << "\n=== CLIENTES ===" << endl;
for(int i=0;i<clientes.size();i++){
cout << i+1 << ". " << clientes[i]->getNombre() << endl;
}

int opcion;
cout << "Ingrese el digito que corresponde al cliente: " << endl;
cin >> opcion;
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "opcion inválida. Use números." << endl;
    return;
}
  if (opcion < 1 || opcion > clientes.size()) {
    cout << "Opción inválida" << endl;
    return;
}

Cliente* cliente = clientes[opcion-1];

 if (cliente->getTarjetas().empty()) {
        cout << "Este cliente no tiene tarjetas." << endl;
        return;
    }

  cout << "\n=== TARJETAS DE " << cliente->getNombre() << " ===" << endl;
    for (int i = 0; i < cliente->getTarjetas().size(); i++) {
        cout << i+1 << ". " << cliente->getTarjetas()[i]->getNumero()
             << " (Saldo: $" << cliente->getTarjetas()[i]->getSaldo() << ")" << endl;
    }

    int opcionTarjeta;
    cout << "Seleccione tarjeta: ";
    cin >> opcionTarjeta;

    if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opcion inválida. Use números." << endl;
    return;
}
    if (opcionTarjeta < 1 || opcionTarjeta > cliente->getTarjetas().size()) {
        cout << "Opción inválida" << endl;
        return;
    }
    
    TarjetaCredito* tarjeta = cliente->getTarjetas()[opcionTarjeta-1];

    double monto;
    cout << "Monto a pagar: $";
    cin >> monto;
    if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Monto inválido. Use números." << endl;
    return;
}
    tarjeta->pagar(monto);
}

void Sistema::mostrarInformacionCliente(){
if(clientes.empty()){
cout<<"No hay clientes registrados. "<<endl;
return;
}

cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
for (int i = 0; i < clientes.size(); i++) {
    cout << i+1 << ". " << clientes[i]->getNombre() 
             << " (ID: " << clientes[i]->getId() << ")" << endl;
}

  int opcion;
    cout << "Seleccione cliente: ";
    cin >> opcion;
    
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opcion inválida. Use números." << endl;
    return;
}

    if (opcion < 1 || opcion > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcion-1];

    cout << "\n========================================" << endl;
    cout << "       INFORMACIÓN COMPLETA DEL CLIENTE" << endl;
    cout << "========================================" << endl;

cout << "   DATOS PERSONALES:" << endl;
cout << "   Nombre: " << cliente->getNombre() << endl;
cout << "   Cedula: " << cliente->getId() << endl;
cout << "   Ingresos mensuales: $" << cliente->getIngresos() << endl;
cout << "   Número de tarjetas: " << cliente->getTarjetas().size() << endl;

if (!cliente->getTarjetas().empty()) {
        double totalSaldo = 0;
        double totalCupo = 0;
        double totalDisponible = 0;
        cout << "\n TARJETAS DE CRÉDITO:" << endl;
        for (int i = 0; i < cliente->getTarjetas().size(); i++) {
            TarjetaCredito* tarjeta = cliente->getTarjetas()[i];
            
            cout << "\n   Tarjeta #" << i+1 << ":" << endl;
            cout << "   Número: " << tarjeta->getNumero() << endl;
            cout << "   Estado: " << tarjeta->getEstado() << endl;
            cout << "   Cupo máximo: $" << tarjeta->getCupoMaximo()<< endl;
            cout << "   Saldo actual: $" << tarjeta->getSaldo() << endl;
            cout << "   Cupo disponible: $" << tarjeta->getCupoDisponible() << endl;
            cout << "   Pago mínimo: $" << tarjeta->calcularPagoMinimo() << endl;
            totalSaldo += tarjeta->getSaldo();
            totalCupo += tarjeta->getCupoMaximo();
            totalDisponible += tarjeta->getCupoDisponible();
}
        cout << "\n RESUMEN FINANCIERO:" << endl;
        cout << "   Cupo total: $" << totalCupo << endl;
        cout << "   Saldo total: $" << totalSaldo << endl;
        cout << "   Cupo disponible total: $" << totalDisponible << endl;
        if (totalCupo > 0) {
            double porcentajeUso = (totalSaldo / totalCupo) * 100;
            cout << "   Porcentaje de uso: " << porcentajeUso << "%" << endl;
        }
}
    cout << "\n========================================" << endl;
}

void Sistema::cargarClientesDesdeArchivo() {
    vector<Cliente*> cargados = Archivos::cargarClientes();
    clientes.insert(clientes.end(), cargados.begin(), cargados.end());
}


void Sistema::bloquearTarjeta(){
   if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    // Esto muestra los clientes (del vector el cual se ayuda de archivos csv)
    cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << i+1 << ". " << clientes[i]->getNombre() 
             << " (ID: " << clientes[i]->getId() << ")" 
             << " - Tarjetas: " << clientes[i]->getTarjetas().size() << endl;
    }
    
    // Aqui seleccionamos el cliente
    int opcionCliente;
    cout << "\nSeleccione cliente (1-" << clientes.size() << "): ";
    cin >> opcionCliente;
    
    if (opcionCliente < 1 || opcionCliente > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    Cliente* cliente = clientes[opcionCliente - 1];
    vector<TarjetaCredito*>& tarjetas = cliente->getTarjetas();
    
    if (tarjetas.empty()) {
        cout << "Este cliente no tiene tarjetas." << endl;
        return;
    }
    
    // Mostrar tarjetas del cliente
    cout << "\n=== TARJETAS DE " << cliente->getNombre() << " ===" << endl;
    for (int i = 0; i < tarjetas.size(); i++) {
        cout << i+1 << ". " << tarjetas[i]->getNumero()
             << " - Estado: " << tarjetas[i]->getEstado()
             << " - Saldo: $" << tarjetas[i]->getSaldo() << endl;
    }
    
    // Seleccionar tarjeta
    int opcionTarjeta;
    cout << "\nSeleccione tarjeta a BLOQUEAR (1-" << tarjetas.size() << "): ";
    cin >> opcionTarjeta;
    
    if (opcionTarjeta < 1 || opcionTarjeta > tarjetas.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    TarjetaCredito* tarjeta = tarjetas[opcionTarjeta - 1];
    
    // Verificar si ya está bloqueada
    if (tarjeta->getEstado() == "BLOQUEADA") {
        cout << "La tarjeta ya está bloqueada." << endl;
        return;
    }
    
    // Bloquear la tarjeta
    tarjeta->bloquearTarjeta();
    cout << " Tarjeta " << tarjeta->getNumero() << " ha sido BLOQUEADA exitosamente." << endl;
}

void Sistema::desbloquearTarjeta(){
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    
    // Mostrar clientes
    cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << i+1 << ". " << clientes[i]->getNombre() 
             << " (ID: " << clientes[i]->getId() << ")" 
             << " - Tarjetas: " << clientes[i]->getTarjetas().size() << endl;
    }
    
    // Seleccionar cliente
    int opcionCliente;
    cout << "\nSeleccione cliente (1-" << clientes.size() << "): ";
    cin >> opcionCliente;
    
    if (opcionCliente < 1 || opcionCliente > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    Cliente* cliente = clientes[opcionCliente - 1];
    vector<TarjetaCredito*>& tarjetas = cliente->getTarjetas();
    
    if (tarjetas.empty()) {
        cout << "Este cliente no tiene tarjetas." << endl;
        return;
    }
    
    // Mostrar tarjetas del cliente
    cout << "\n=== TARJETAS DE " << cliente->getNombre() << " ===" << endl;
    for (int i = 0; i < tarjetas.size(); i++) {
        cout << i+1 << ". " << tarjetas[i]->getNumero()
             << " - Estado: " << tarjetas[i]->getEstado()
             << " - Saldo: $" << tarjetas[i]->getSaldo() << endl;
    }
    
    // Seleccionar tarjeta
    int opcionTarjeta;
    cout << "\nSeleccione tarjeta a DESBLOQUEAR (1-" << tarjetas.size() << "): ";
    cin >> opcionTarjeta;
    
    if (opcionTarjeta < 1 || opcionTarjeta > tarjetas.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    TarjetaCredito* tarjeta = tarjetas[opcionTarjeta - 1];
    
    // Verificar si ya está activa
    if (tarjeta->getEstado() == "ACTIVA") {
        cout << "La tarjeta ya está activa." << endl;
        return;
    }
    
    // Desbloquear la tarjeta
    tarjeta->desbloquearTarjeta();
    cout << "✓ Tarjeta " << tarjeta->getNumero() << " ha sido ACTIVADA exitosamente." << endl;
}

void Sistema::eliminarTarjeta() {
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    
    // Mostrar clientes
    cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << i+1 << ". " << clientes[i]->getNombre() 
             << " (ID: " << clientes[i]->getId() << ")" 
             << " - Tarjetas: " << clientes[i]->getTarjetas().size() << endl;
    }
    
    // Seleccionar cliente
    int opcionCliente;
    cout << "\nSeleccione cliente (1-" << clientes.size() << "): ";
    cin >> opcionCliente;
    
    if (opcionCliente < 1 || opcionCliente > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    Cliente* cliente = clientes[opcionCliente - 1];
    vector<TarjetaCredito*>& tarjetas = cliente->getTarjetas();
    
    if (tarjetas.empty()) {
        cout << "Este cliente no tiene tarjetas para eliminar." << endl;
        return;
    }
    
    // Mostrar tarjetas del cliente
    cout << "\n=== TARJETAS DE " << cliente->getNombre() << " ===" << endl;
    for (int i = 0; i < tarjetas.size(); i++) {
        cout << i+1 << ". " << tarjetas[i]->getNumero()
             << " - Estado: " << tarjetas[i]->getEstado()
             << " - Saldo: $" << tarjetas[i]->getSaldo() << endl;
    }
    
    // Seleccionar tarjeta
    int opcionTarjeta;
    cout << "\nSeleccione tarjeta a ELIMINAR (1-" << tarjetas.size() << "): ";
    cin >> opcionTarjeta;
    
    if (opcionTarjeta < 1 || opcionTarjeta > tarjetas.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    TarjetaCredito* tarjetaAEliminar = tarjetas[opcionTarjeta - 1];
    string numeroTarjeta = tarjetaAEliminar->getNumero();
    
    // Confirmar eliminación
    char confirmar;
    cout << "\n ADVERTENCIA: Esta acción no se puede deshacer." << endl;
    cout << "¿Está seguro que desea eliminar la tarjeta " << numeroTarjeta << "? (s/n): ";
    cin >> confirmar;
    
    if (confirmar == 's' || confirmar == 'S') {
        // Eliminar la tarjeta del vector
        tarjetas.erase(tarjetas.begin() + (opcionTarjeta - 1));
        
        // Liberar la memoria
        delete tarjetaAEliminar;
        
        cout << "✓ Tarjeta " << numeroTarjeta << " eliminada exitosamente." << endl;
        cout << "El cliente ahora tiene " << tarjetas.size() << " tarjeta(s)." << endl;
    } else {
        cout << "Eliminación cancelada." << endl;
    }
}

void Sistema::eliminarCliente() {
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    
    // Mostrar clientes
    cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        Cliente* cliente = clientes[i];
        cout << i+1 << ". " << cliente->getNombre() 
             << " (ID: " << cliente->getId() << ")" 
             << " - Tarjetas: " << cliente->getTarjetas().size()
             << " - Ingresos: $" << cliente->getIngresos() << endl;
    }
    
    // Seleccionar cliente
    int opcionCliente;
    cout << "\nSeleccione cliente a ELIMINAR (1-" << clientes.size() << "): ";
    cin >> opcionCliente;
    
    if (opcionCliente < 1 || opcionCliente > clientes.size()) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    Cliente* clienteAEliminar = clientes[opcionCliente - 1];
    string nombreCliente = clienteAEliminar->getNombre();
    int numTarjetas = clienteAEliminar->getTarjetas().size();
    
    // Confirmar eliminación
    cout << "\n   ADVERTENCIA CRÍTICA   " << endl;
    cout << "Va a eliminar al cliente: " << nombreCliente << endl;
    cout << "Esta acción también eliminará sus " << numTarjetas << " tarjeta(s)." << endl;
    cout << "Esta acción NO SE PUEDE DESHACER." << endl;
    
    char confirmar;
    cout << "\n ¿Está ABSOLUTAMENTE seguro? (escriba 'SI' para confirmar): ";
    string confirmacion;
    cin >> confirmacion;
    
    if (confirmacion == "SI" || confirmacion == "si") {
        // Primero eliminar todas las tarjetas del cliente
        vector<TarjetaCredito*>& tarjetas = clienteAEliminar->getTarjetas();
        for (TarjetaCredito* tarjeta : tarjetas) {
            delete tarjeta;
        }
        tarjetas.clear();
        
        // Eliminar el cliente del vector
        clientes.erase(clientes.begin() + (opcionCliente - 1));
        
        // Liberar la memoria del cliente
        delete clienteAEliminar;
        
        cout << "\n Cliente " << nombreCliente << " eliminado exitosamente." << endl;
        cout << "" << numTarjetas << " tarjeta(s) también fueron eliminadas." << endl;
        cout << "Quedan " << clientes.size() << " cliente(s) en el sistema." << endl;
    } else {
        cout << "Eliminación cancelada." << endl;
    }
}