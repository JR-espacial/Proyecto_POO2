#ifndef AGENCIA_H
#define AGENCIA_H
#include <string>
#include "auto.h"
#include "cliente.h"
#include "pago.h"
#include <iostream>

using namespace std;

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
  Pago *formasP[4];
  Auto *autos[100];
  Cliente clientes[100];

	public:
	Agencia ();
  Agencia(string nom, long long int tel, string cE, string dom,int cap, int cM);

  void setNombre(string nuevoNombre);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setDomicilio(string nuevoDomicilio);
	void setCapacidadAl(int nuevaCapacidadAl);
	void imprimeDatos();
	void agregaAutoG(string ,string ,int ,int , float ,  bool  ,int ,string ,string  , string ,string ,	float ,string , float , float,string,int,string);
  void agregaAutoE(string ,string ,int ,int,float ,string ,string  , string ,string ,	float ,string , float , float,string,int,string,int,float,int );
  void agregaCliente(Cliente c);
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
	capacidadAl = 100 ;
	autosActuales = 0;
  clientesActuales=0;
  clientesMaximos =100;
}
Agencia:: Agencia (string nom, long long int tel, string cE, string dom,int cap,int cM){
    nombre = nom;
    telefono = tel;
    correoElectronico = cE;
    domicilio = dom;
    capacidadAl = cap;
    autosActuales = 0;
    clientesActuales=0;
    clientesMaximos = cM;
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
void Agencia :: imprimeDatos(){
  cout <<"Nombre de la Agencia:     "<< getNombre()<<endl;
	cout << "Telefono:                 "<<getTelefono()<<endl;
	cout << "Correo Electronico:       "<<getCorreoElectronico()<<endl;
	cout << "Ubicacion de la Agencia:  "<<getDomicilio()<<endl;
	cout <<"Capacidad maxima:         "<<getCapacidadAl()<<" autos"<<endl;
	cout << "Autos en stock:           "<<getAutosActuales()<<endl;
  cout << "Clientes Actuales:        "<<getClientesActuales()<<endl;
}
void  Agencia :: agregaAutoG(string modm, string marm,int cDF,int tor,float ac,bool tur,int cil,string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac ){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = new AutoGasolinaRegular(modm, marm,cDF,tor,ac,tur, cil,mar ,mod,col ,tran,pr,tdc,ren,cap,dir,pue,trac);
        autosActuales++;
    }

}
void  Agencia :: agregaAutoE(string modm, string marm,int cDF,int tor,float tDA,string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac,int aut,float tDR,int AE){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = new AutoElectrico(modm,marm,cDF,tor,tDA,mar ,mod,col ,tran,pr,tdc,ren,cap,dir,pue,trac,aut,tDR);
        autosActuales++;
    }

}
void  Agencia:: agregaCliente(Cliente c){

    if (clientesActuales < clientesMaximos){
        clientes[clientesActuales] = c;
        clientesActuales++;
    }

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