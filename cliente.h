#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Cliente{
	private:
  int id;
	string nombre;
	int edad;
	long long int telefono;
	string correoElectronico;
	string rfc;
	string domicilio;
	public:
	Cliente ();
  Cliente(int iD,string nom,int ed, long long int tel, string cE, string r, string dom);

	int getId();
  string getNombre();
	int  getEdad();
	long long int getTelefono();
	string getCorreoElectronico();
	string getRfc();
	string getDomicilio();

  void setEdad(int nuevaEdad);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setRfc(string nuevoRfc);
	void setDomicilio(string nuevoDomicilio);
  void setId(int nuevaId);
	string toString();



};
Cliente :: Cliente(){
    id = 0;
    nombre = "undefined";
    edad = 0;
    telefono = 0;
    correoElectronico = "undefined";
    rfc = "undefined";
    domicilio = "undefined";

}

Cliente :: Cliente(int iD, string nom,int ed, long long int tel, string cE, string r, string dom){
    id=iD;
    nombre = nom;
    edad = ed;
    telefono = tel;
    correoElectronico = cE;
    rfc = r;
    domicilio = dom;
}
int Cliente :: getId(){
  return id;
}
string Cliente :: getNombre(){
  return nombre;
}
int Cliente :: getEdad(){
 return edad;
}
long long int Cliente :: getTelefono(){
 return telefono;
}
string Cliente :: getCorreoElectronico(){
 return correoElectronico;
}
string Cliente :: getRfc(){
 return rfc;
}
string Cliente :: getDomicilio(){
return domicilio;
}

void Cliente :: setEdad(int nuevaEdad){
    edad = nuevaEdad;
}
void Cliente :: setTelefono(long long int nuevoTelefono){
    telefono = nuevoTelefono;
}
void Cliente :: setCorreoElectronico(string nuevoCorreoElectronico){
    correoElectronico = nuevoCorreoElectronico;
}
void Cliente :: setRfc(string nuevoRfc){
    rfc = nuevoRfc;
}
void Cliente :: setDomicilio(string nuevoDomicilio){
    domicilio = nuevoDomicilio;
}
void Cliente :: setId(int nuevaId){
    id = nuevaId;
}
string  Cliente :: toString(){
  stringstream aux;
    aux << "-----------------------------------"<<endl;
    aux << "------------Cliente#"<<getId()<<"-----------------------"<<endl;
    aux << "-----------------------------------"<<endl;
    aux<<"Nombre: " << getNombre()<<endl;
    aux<<"Edad: "<< getEdad()<<endl;
    aux<<"Telefono: "<< getTelefono()<<endl;
    aux<<"Correo elecrtonico: "<< getCorreoElectronico()<<endl;
    aux<<"RFC: "<< getRfc()<<endl;
    aux<<"Domicilio :"<< getDomicilio()<<endl;
    return aux.str();
}

#endif