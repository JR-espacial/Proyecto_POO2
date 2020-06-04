#ifndef AUTO_H
#define AUTO_H
#include <string>
using namespace std;

class Auto{
    private:
    string estado;
		string marca;
		string modelo;
		string color;
		string transmision;
		float precio;
		string tipoDeCombustible;
		float rendimiento;
		float capacidadAl;
		string direccion;
    int puertas;
    string traccion;
    public:
		Auto ();
		Auto(string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac);
		string getEstado();
		string getMarca();
		string getColor();
		string getModelo();
		string getTransmision();
		float getPrecio();
		float getRendimiento();
		float getCapacidadAl();
		string getTipoDeCombustible();
		string getDireccion();
		int getPuertas();
		string getTraccion();
  	void setPrecio(float nuevoPrecio);
		void setEstado(string nuevoEstado);
		//virtual void imprimeAtributos() =0;
};
Auto :: Auto(){
  estado = "Disponible";
	marca = "undefined";
	modelo = "undefined";
	color = "undefined";
	transmision = "undefined";
	precio = 0 ;
  puertas=0;
  traccion ="undefined";
  direccion = "undefined";
  tipoDeCombustible ="undefined";
  rendimiento=0;
  capacidadAl=0;
}
Auto:: Auto( string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac){

    estado = "Disponible";
    marca = mar;
    modelo = mod;
    color = col;
    transmision = tran;
    precio = pr;
    direccion = dir;
    puertas = pue;
    traccion = trac;
    tipoDeCombustible =tdc;
    rendimiento = ren;
    capacidadAl= cap;
    direccion = dir;
    puertas = pue;

}
string Auto :: getEstado(){
     return estado;
}
string Auto :: getMarca(){
    return marca;
}
string Auto :: getModelo(){
    return modelo;
}
string Auto :: getColor(){
    return color;
}

string Auto :: getTransmision(){
    return transmision;
}
float Auto :: getRendimiento(){
    return rendimiento;
}
float Auto :: getCapacidadAl(){
    return capacidadAl;
}
string Auto :: getTipoDeCombustible(){
    return tipoDeCombustible;
 }

float Auto :: getPrecio(){
    return precio;
}
string Auto :: getDireccion(){
    return direccion;
}
int Auto :: getPuertas(){
    return puertas;
}
string Auto :: getTraccion(){
    return traccion;
}
void Auto :: setPrecio(float nuevoPrecio){
    precio = nuevoPrecio;
}
void Auto :: setEstado (string nuevoEstado)
{
    estado = nuevoEstado;
}
#endif