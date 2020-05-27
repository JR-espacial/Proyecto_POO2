#ifndef AGENCIA_H
#define AGENCIA_H
#include <string>
#include "auto.h"
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
	Auto autos[100];

	public:
	Agencia ();
    Agencia(string nom, long long int tel, string cE, string dom,int cap,int au);

    void setNombre(string nuevoNombre);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setDomicilio(string nuevoDomicilio);
	void setCapacidadAl(int nuevaCapacidadAl);
	void imprimeDatos();
	void agregaAuto(Auto a);
	void busca(float precioI,float precioF);
	void busca(string marca);

	string getNombre();
	long long int getTelefono();
	string getCorreoElectronico();
	string getDomicilio();
	int getCapacidadAl();
	int getAutosActuales();
};
Agencia :: Agencia (){
	nombre = "";
	telefono = 0;
	correoElectronico = "";
	domicilio = "";
	capacidadAl = 0 ;
	autosActuales = 0;
}
Agencia:: Agencia (string nom, long long int tel, string cE, string dom,int cap,int au){
    nombre = nom;
    telefono = tel;
    correoElectronico = cE;
    domicilio = dom;
    capacidadAl = cap;
    autosActuales = au;
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
int Agencia :: getCapacidadAl(){
return capacidadAl;
}
int Agencia :: getAutosActuales(){
return autosActuales;
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
	cout << "Autos en stock:          "<<getAutosActuales()<<endl;
}
void  Agencia :: agregaAuto(Auto  a){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = a;
        autosActuales++;
    }

}
void Agencia :: busca(float precioI,float precioF){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i].getPrecio()>= precioI && autos[i].getPrecio() < precioF ) {
           cout << "Modelo " << autos[i].getModelo() << "Nombre: " << autos[i].getMarca()<<endl;
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
       if (autos[i].getModelo()== modelo ) {
           cout << "Modelo " << autos[i].getModelo() << "Nombre: " << autos[i].getMarca()<<endl;
           c++;
       }
   }
   if (c == 0)
      cout << " No hay autos con las caracteristicas buscadas"<< endl;
}
#endif