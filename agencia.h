/*----------------------------------
 *
 * Proyecto POO 2
 * Fecha: 13 Junio 2020
 * Autor: A001701350 Jorge Alan Ramirez Elias
 *
 -----------------------------------
 Descripcion de la fucionalidad de  la clase Agencia
 
 La clase agencia esta hecha para trabajar con objetos de todas las demas clases estos objetos los almacena
 en sus 4 arreglos dinamicos:
 
 autos -> es el atributo que permite el control de los objetos de las clases AutoElectrico y AutoGasolinaRegular
 este atributo es en realidad un apuntador al primer elemento de un areglo de apuntadores de la clase Auto la cual es un clase abstracta y es la clase padre de AutoGasolinaRegular y AutoElectrico

 formasP -> es el atributo que permite el control de los objetos de las clases Contado y Credito
 este atributo es en realidad un apuntador al primer elemento de un areglo de apuntadores de la clase Pago la cual es un clase abstracta y es la clase padre de Contado y Credito

 clientes -> es el atributo que permite el control de los objetos de la clase Cliente este atributo es en realidad un apuntador al primer elemento de un areglo de la clase Cliente 

 ventas -> es el atributo que permite el control de los objetos de la clase Venta este atributo es en realidad un apuntador al primer elemento de un areglo de la clase Venta

 seguros -> es el atributo que permite el control de los objetos de la clase Seguro este atributo es en realidad un apuntador al primer elemento de un areglo de la clase Seguro

 Esta clase es a la unica a la que se le hacen llamadas en el main y atravez de esta regulamos los calculos  requeridos apra la 
 operacion y administracion de la agencia asi como la agregacion de nuevos clientes , ventas ,seguros,formas de pago  y autos

 El resto de los atriubutos de la clase se utilizan como contadores y datos basicos de la agencia.
 Por cuestiones de seguridad casi ninguna operacion mas que los geters se conecta directamente a operaciones en el stringstream y en caso de ser asi se relizan diferentes validaciones AUN ESTANDO EN EL MODO ADMIN

 La mayoria de los metodos son metodos de impresion, getters ,agregacion de nuevos  clientes , ventas ,seguros,formas de pago  y autos o busquedas

 */

#ifndef AGENCIA_H
#define AGENCIA_H

#include "auto.h"
#include "cliente.h"
#include "pago.h"
#include "credito.h"
#include "contado.h"
#include "venta.h"
#include "seguro.h"

#include <string>
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
    ~Agencia();

    string getNombre();
    long long int getTelefono();
    string getCorreoElectronico();
    string getDomicilio();
    int getContado();
    int getCapacidadAl();
    int getAutosActuales();
    int getClientesActuales();
    int getClientesMaximos();
    int getFormasPAct(); 
    int getFormasPMax();
    int getVentasAct();
    int getVentasMax();
    int getSegurosAct();
    int getSegurosMax();

    void setNombre(string nuevoNombre);
    void setTelefono(long long int nuevoTelefono);
    void setCorreoElectronico(string nuevoCorreoElectronico);
    void setDomicilio(string nuevoDomicilio);
    void setCapacidadAl(int nuevaCapacidadAl);

    string toString();
    string getNombreCliente(int i);
    string autosToString();
    string formasPToString();
    string ventasToString();
    string clientesToString();
    string segurosToString();
    string creditoToString();
    string modelosActualesToString();

    string calculosContado();
    int estableceMontoP(int aIndex, int pIndex,string tipo); 

    void agregaAuto(AutoElectrico &ae);
    void agregaAuto(AutoGasolinaRegular &agr);
    void agregaCliente(Cliente &c);
    void agregaMetodoP(Credito &cr);
    void agregaMetodoP(Contado &co);
    void agregaSeguro(Seguro &s);
    void agregaVenta(Venta &v);

    void modificaContado(float nevoDescuento);

    string buscaAuto(float precioI,float precioF);
    string buscaAuto(string modelo);
    string buscaAuto( int id);

    void venderAuto(int idAuto,int idCliente,int idSeguro, int idPago);
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
Agencia :: ~Agencia(){
  delete [] autos;
  delete [] clientes;
  delete [] formasP;
  delete [] ventas;
  delete [] seguros;
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
int Agencia ::  getFormasPAct(){
  return formasPAct;
}
int Agencia :: getFormasPMax(){
  return formasPMax;
}
int Agencia :: getVentasAct(){
  return ventasAct;
}
int Agencia :: getVentasMax(){
  return ventasMax;
}
int Agencia :: getSegurosAct(){
  return segurosAct;
}
int Agencia :: getSegurosMax(){
  return segurosMax;
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
string Agencia :: modelosActualesToString(){
  stringstream aux;
  aux <<"Los modelos disponibles son:\n";
  for (int i=0; i < autosActuales;i++){
    aux <<i<<"-  "<<autos[i]->getModelo()<<endl;
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
int Agencia :: estableceMontoP(int aIndex,int pIndex,string tipo){
 
  if (tipo == "Credito"){
    if(pIndex < formasPAct && pIndex != contado){
      double nuevoMonto = autos[aIndex]->getPrecio();
      formasP[pIndex]->setMonto(nuevoMonto);
      return 1;
    }
    else if (pIndex == contado){
      return 2;
    }
    else{
      return 0;
    }
  }
  else{
    double nuevoMonto = autos[aIndex]->getPrecio();
    formasP[pIndex]->setMonto(nuevoMonto);
    return 1;
  }
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
    seguros[segurosAct].setId(segurosAct);
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

string Agencia :: buscaAuto(float precioI,float precioF){
   int i,c=0;
   stringstream aux;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i]->getPrecio()>= precioI && autos[i]->getPrecio() < precioF ) {
           c++;
           if (c == 1){
             cout<<"------------------------------------------------------------------"<<endl;
             cout<<"Los Autos que cocindieron con su presupuesto fueron los siguientes:"<<endl;
           }
           aux << autos[i]->toString()<<endl;
           
       }
   }
   if (c == 0)
      aux << " No hay autos con las cacarteristicas buscadas"<< endl;

  return aux.str();
}

string Agencia :: buscaAuto(string modelo){
   int i,c=0;
   stringstream aux;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i]->getModelo()== modelo ) {
           aux << autos[i]->toString();
           c++;
       }
   }
   if (c == 0){
      aux << "No hay autos con las caracteristicas buscadas"<< endl;
   }
   else{
      aux <<"Estos son lo autos que coincidieron con tu busqueda"<<endl;
    }
  return aux.str();  
}
string Agencia :: buscaAuto(int id){
  stringstream aux;
  if (id<autosActuales){
    aux << autos[id]->toString();
  }
  else{
    aux <<"El auto que buscas no existe porfavor verifica el numero de auto y vuelve a buscarlo"<<endl;
  }
  return aux.str();
}

void Agencia :: venderAuto(int idAuto, int idCliente,int idSeguro,int idPago){
  Venta *v;
  double totalEntrante;
  if(idPago == contado){
     Contado *aux = (Contado*)formasP[contado];
    totalEntrante = aux->montoP();
  }
  else{
    Credito *aux =(Credito*)formasP[idPago];
    totalEntrante = aux->getEnganche();
  }
  if (idSeguro == -9){
    v = new Venta(idAuto, idCliente,"Hoy", totalEntrante);
  }
  else{
    totalEntrante += seguros[idSeguro].getCosto();
    v = new Venta(idAuto,idCliente,"Hoy",totalEntrante,seguros[idSeguro]);
  }
  agregaVenta(*v);
}
#endif