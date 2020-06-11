#ifndef AGENCIA_H
#define AGENCIA_H
#include <string>
#include "auto.h"
#include "cliente.h"
#include "pago.h"
#include "credito.h"
#include "contado.h"
#include "venta.h"
#include "seguro.h"
#include <iostream>
#include <sstream>


using namespace std;
const int TAM=100;
const int FP = 4;

class Agencia {
	private:
	string nombre;
	long long int telefono;
	string correoElectronico;
	string domicilio;
	int autosActuales;
	int capacidadAl;
  int clientesActuales;
  int clientesMaximos;
  int formasPAct;
  int formasPMax;
  int ventasAct;
  int ventasMax;
  int segurosAct;
  int segurosMax;
  int contado;
  Pago **formasP;
  Auto **autos;
  Cliente *clientes;
  Venta *ventas;
  Seguro *seguros;

	public:
	Agencia ();
  Agencia(string nom, long long int tel, string cE, string dom,int cap, int cM,int fpM,int vM,int sM);

  void setNombre(string nuevoNombre);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setDomicilio(string nuevoDomicilio);
	void setCapacidadAl(int nuevaCapacidadAl);
	string toString();
  void agregaAuto(AutoElectrico &ae);
  void agregaAuto(AutoGasolinaRegular &agr);
  void agregaCliente(Cliente &c);
  void agregaMetodoP(Credito &cr);
  void agregaMetodoP(Contado &co);
  void agregaSeguro(Seguro &s);
  void agregaVenta(Venta &v);
  void modificaContado(float nevoDescuento);
  void estableceMontoP(int aIndex, int pIndex);
	void busca(float precioI,float precioF);
	void busca(string modelo);
  void busca( int id);
  string getNombreCliente(int i);
  string autosToString();
  string formasPToString();
  string ventasToString();
  string clientesToString();
  string segurosToString();
  string creditoToString();
  string calculosContado(); 

	string getNombre();
	long long int getTelefono();
	string getCorreoElectronico();
	string getDomicilio();
  int getContado();
	int getCapacidadAl();
	int getAutosActuales();
  int getClientesActuales();
  int getClientesMaximos();
};
Agencia :: Agencia (){
	nombre = "undefined";
	telefono = 0;
	correoElectronico = "undefined";
	domicilio = "undefined";
	capacidadAl = TAM ;
  autos = new Auto*[capacidadAl];
	autosActuales = 0;
  clientesActuales = 0;
  clientesMaximos = TAM;
  clientes = new Cliente[clientesMaximos];
  formasPAct =0;
  formasPMax = FP;
  contado = -1;
  formasP = new Pago *[formasPMax];
  ventasAct = 0;
  ventasMax = TAM;
  ventas = new Venta [ventasMax];
  segurosAct = 0;
  segurosMax = TAM;
  seguros = new Seguro [segurosMax];
}
Agencia:: Agencia (string nom, long long int tel, string cE, string dom,int cap,int cM,int fpM, int vM, int sM){
    nombre = nom;
    telefono = tel;
    correoElectronico = cE;
    domicilio = dom;
    capacidadAl = cap;
    autos = new Auto* [capacidadAl];
    autosActuales = 0;
    clientesActuales = 0;
    clientesMaximos = cM;
    clientes =new Cliente[clientesMaximos];
    formasPAct = 0;
    formasPMax= fpM;
    contado = -1;
    formasP = new Pago *[formasPMax];
    ventasAct = 0;
    ventasMax = vM;
    ventas = new Venta [ventasMax];
    segurosAct = 0;
    segurosMax = sM;
    seguros = new Seguro [segurosMax];
}
string Agencia :: getNombre(){
  return nombre;
}
long long int Agencia :: getTelefono(){
 return telefono;
}
string Agencia :: getCorreoElectronico(){
 return correoElectronico;
}

string Agencia :: getDomicilio(){
return domicilio;
}
int Agencia :: getContado(){
  return contado;
}
int Agencia :: getAutosActuales(){
return autosActuales;
}
int Agencia :: getClientesActuales(){
return clientesActuales;
}
int Agencia :: getCapacidadAl(){
return capacidadAl;
}
int Agencia :: getClientesMaximos(){
return clientesMaximos;
}
string Agencia :: getNombreCliente(int i){
  return clientes[i].getNombre();
}

void Agencia :: setNombre( string nuevoNombre){
    nombre = nuevoNombre;
}

void Agencia :: setTelefono(long long int nuevoTelefono){
    telefono = nuevoTelefono;
}
void Agencia :: setCorreoElectronico(string nuevoCorreoElectronico){
    correoElectronico = nuevoCorreoElectronico;
}
void Agencia :: setDomicilio(string nuevoDomicilio){
    domicilio = nuevoDomicilio;
}
void Agencia :: setCapacidadAl(int nuevaCapacidadAl){
    domicilio = nuevaCapacidadAl;
}
string Agencia :: toString(){
  stringstream aux;
  aux <<"Nombre de la Agencia:     "<< getNombre()<<endl;
	aux << "Telefono:                 "<<getTelefono()<<endl;
	aux << "Correo Electronico:       "<<getCorreoElectronico()<<endl;
	aux << "Ubicacion de la Agencia:  "<<getDomicilio()<<endl;
	aux <<"Capacidad maxima:         "<<getCapacidadAl()<<" autos"<<endl;
	aux << "Autos en stock:           "<<getAutosActuales()<<endl;
  aux << "Clientes Actuales:        "<<getClientesActuales()<<endl;
  aux <<"-------------------------------"<<endl;
  return aux.str();
}
string Agencia :: formasPToString(){
  stringstream aux;
  for (int i=0; i < formasPAct; i++){
    aux<<formasP[i]->toString()<<endl;
  }
  return aux.str();
}
string Agencia :: autosToString(){
  stringstream aux;
  for (int i=0; i < autosActuales; i++){
    aux<<autos[i]->toString()<<endl;
  }
  return aux.str();
}
string Agencia :: segurosToString() {
  stringstream aux;
  for (int i=0; i < segurosAct; i++){
    aux<<seguros[i].toString()<<endl;
  }
  return aux.str();
}
string Agencia :: ventasToString(){
  stringstream aux;
  for (int i=0; i < ventasAct; i++){
    aux<<ventas[i].toString()<<endl;
  }
  return aux.str();
}
string Agencia :: clientesToString(){
  stringstream aux;
  for (int i=0; i < clientesActuales; i++){
    aux<<clientes[i].toString()<<endl;
  }
  return aux.str();
}
string Agencia :: creditoToString(){
  stringstream aux;
  for (int i=0; i < formasPAct && i!=contado; i++){
    aux<<formasP[i]->toString()<<endl;
  }
  return aux.str();
}
string Agencia ::calculosContado(){
  stringstream aux;
  Contado *temp =  (Contado*)formasP[contado];
  aux << "El auto que escogio tiene un precio de:"<<temp->getMonto()<<endl;
  aux << "El descuento es de "<<temp->getDescuento()*100<<"% por pagar de contado"<<endl;
  aux << "Por lo tanto el descuento correspondiente seria de "<<temp->cDescuento()<<endl;
  aux << "El monto a pagar quedaria en "<<temp->montoP()<<endl;
  return aux.str();
}
void Agencia :: agregaAuto(AutoElectrico &ae){
  if (capacidadAl > autosActuales){
        autos[autosActuales] = &ae;
        autos[autosActuales]->setId(autosActuales);
        autosActuales++;
    }
}
void Agencia :: agregaAuto(AutoGasolinaRegular &agr){
  if (capacidadAl > autosActuales){
        autos[autosActuales] = &agr;
        autos[autosActuales]->setId(autosActuales);
        autosActuales++;
    }
}
void  Agencia:: agregaCliente(Cliente &c){

    if (clientesActuales < clientesMaximos){
        clientes[clientesActuales] = c;
        clientes[clientesActuales].setId(clientesActuales);
        clientesActuales++;
    }

}
void Agencia :: agregaMetodoP(Credito &cr){
   if (formasPAct < formasPMax ){
     formasP[formasPAct]= &cr;
     formasP[formasPAct]->setId(formasPAct);
     formasPAct++;  
   }
   
}
void Agencia :: agregaMetodoP(Contado &co){
  if(contado == -1){
    if (formasPAct < formasPMax ){
      formasP[formasPAct] = &co;
      formasP[formasPAct]->setId(formasPAct);
      contado = formasPAct;
      formasPAct++;
    }
  }
}
void Agencia :: agregaSeguro(Seguro &s){
  if(segurosAct < segurosMax){
    seguros[segurosAct] = s;
    segurosAct++;
  }
}
void Agencia :: agregaVenta(Venta &v){
  if(ventasAct < ventasMax){
    ventas[ventasAct] = v;
    ventasAct++;
  }
}
void  Agencia :: modificaContado(float nevoDescuento){
  Contado *aux =  (Contado*)formasP[contado];
  aux->setDescuento(nevoDescuento);
}
void Agencia :: estableceMontoP(int aIndex,int pIndex){
  double nuevoMonto = autos[aIndex]->getPrecio();
  formasP[pIndex]->setMonto(nuevoMonto);
}
void Agencia :: busca(float precioI,float precioF){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i]->getPrecio()>= precioI && autos[i]->getPrecio() < precioF ) {
           c++;
           if (c == 1){
             cout<<"------------------------------------------------------------------"<<endl;
             cout<<"Los Autos que cocidieron con su presupuesto fueron los siguientes:"<<endl;
           }
           cout << autos[i]->toString()<<endl;
           
       }
   }
   if (c == 0)
      cout << " No hay autos con las cacarteristicas buscadas"<< endl;

}

void Agencia :: busca(string modelo){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i]->getModelo()== modelo ) {
           cout << autos[i]->toString();
           c++;
       }
   }
   if (c == 0)
      cout << " No hay autos con las caracteristicas buscadas"<< endl;
}
void Agencia :: busca(int id){
  if (id<autosActuales){
    cout << autos[id]->toString();
  }
  else{
    cout <<"El auto que buscas no existe porfavor verifica el numero de auto y vuelve a buscarlo"<<endl;
  }

}
#endif