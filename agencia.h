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
	void agregaAuto(double price,int iD,string ,string ,int ,int , float ,  bool  ,int ,string ,string  , string ,string ,string , float , float,string,int,string);
  void agregaAuto(double price,int iD,string ,string ,int ,int,float ,string ,string  , string ,string ,string , float , float,string,int,string,int,float,int );
  void agregaAuto(AutoElectrico &ae);
  void agregaAuto(AutoGasolinaRegular &agr);
  void agregaCliente(Cliente &c);
  void agregaMetodoP(double m,float tI,float tM, int p,float e,float mul);
  void agregaMetodoP(double m, float d);
	void busca(float precioI,float precioF);
	void busca(string marca);

	string getNombre();
	long long int getTelefono();
	string getCorreoElectronico();
	string getDomicilio();
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
  formasP = new Pago *[formasPMax];
  ventasAct = 0;
  ventasMax = TAM;
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
  for (int i=0; i < formasPAct; i++){
    aux<<formasP[i]->toString()<<endl;
  }
  for (int i=0; i < autosActuales; i++){
    aux<<autos[i]->toString()<<endl;
  }
  return aux.str();
}
void  Agencia :: agregaAuto(double price,int iD,string modm, string marm,int cDF,int tor,float ac,bool tur,int cil,string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac ){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = new AutoGasolinaRegular(price,iD,modm, marm,cDF,tor,ac,tur, cil,mar ,mod,col ,tran,tdc,ren,cap,dir,pue,trac);
        autosActuales++;
    }

}
void  Agencia :: agregaAuto(double price,int iD,string modm, string marm,int cDF,int tor,float tDA,string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac,int aut,float tDR,int AE){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = new AutoElectrico(price,iD,modm,marm,cDF,tor,tDA,mar ,mod,col ,tran,tdc,ren,cap,dir,pue,trac,aut,tDR);
        autosActuales++;
    }

}
void Agencia :: agregaAuto(AutoElectrico &ae){
  if (capacidadAl > autosActuales){
        autos[autosActuales] = &ae;
        autosActuales++;
    }
}
void Agencia :: agregaAuto(AutoGasolinaRegular &agr){
  if (capacidadAl > autosActuales){
        autos[autosActuales] = &agr;
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
void Agencia :: agregaMetodoP(double m,float tI,float tM, int p,float e,float mul){
   formasP[formasPAct]= new Credito(m,tI,tM,p,e,mul);
   formasPAct++;
}
void Agencia :: agregaMetodoP(double m, float d){
  formasP[formasPAct]= new Contado(m,d);
  formasPAct++;
}
void Agencia :: busca(float precioI,float precioF){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i]->getPrecio()>= precioI && autos[i]->getPrecio() < precioF ) {
           cout << "Modelo " << autos[i]->getModelo() << "Nombre: " << autos[i]->getMarca()<<endl;
           c++;
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
           cout << "Modelo " << autos[i]->getModelo() << "Nombre: " << autos[i]->getMarca()<<endl;
           c++;
       }
   }
   if (c == 0)
      cout << " No hay autos con las caracteristicas buscadas"<< endl;
}
#endif