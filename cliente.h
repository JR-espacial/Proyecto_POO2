#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

using namespace std;

class Cliente{
	private:
	string nombre;
	int edad;
	long long int telefono;
	string correoElectronico;
	string rfc;
	string domicilio;
	public:
	Cliente ();
  Cliente(string nom,int ed, long long int tel, string cE, string r, string dom);

  void setEdad(int nuevaEdad);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setRfc(string nuevoRfc);
	void setDomicilio(string nuevoDomicilio);
	void imprimeDatos();

	string getNombre();
	int  getEdad();
	long long int getTelefono();
	string getCorreoElectronico();
	string getRfc();
	string getDomicilio();

};
Cliente :: Cliente(){
    nombre = "undefined";
    edad = 0;
    telefono = 0;
    correoElectronico = "undefined";
    rfc = "undefined";
    domicilio = "undefined";

}

Cliente :: Cliente(string nom,int ed, long long int tel, string cE, string r, string dom){
    nombre = nom;
    edad = ed;
    telefono = tel;
    correoElectronico = cE;
    rfc = r;
    domicilio = dom;
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
void  Cliente :: imprimeDatos(){
    cout<<"Nombre: " << getNombre()<<endl;
    cout<<"Edad: "<< getEdad()<<endl;
    cout<<"Telefono: "<< getTelefono()<<endl;
    cout<<"Correo elecrtonico: "<< getCorreoElectronico()<<endl;
    cout<<"RFC: "<< getRfc()<<endl;
    cout<<"Domicilio :"<< getDomicilio()<<endl;
}

#endif