#ifndef AUTO_H
#define AUTO_H
#include <string>
using namespace std;

class Auto{
    private:
    double precio;
    int id;
    string estado;
		string marca;
		string modelo;
		string color;
		string transmision;
		string tipoDeCombustible;
		float rendimiento;
		float capacidadAl;
		string direccion;
    int puertas;
    string traccion;
    public:
		Auto ();
		Auto(double price,int iD,string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac);
    double getPrecio();
    int getId();
		string getEstado();
		string getMarca();
		string getColor();
		string getModelo();
		string getTransmision();
		float getRendimiento();
		float getCapacidadAl();
		string getTipoDeCombustible();
		string getDireccion();
		int getPuertas();
		string getTraccion();
  	void setPrecio(double nuevoPrecio);
		void setEstado(string nuevoEstado);
		virtual string toString() =0;
};
Auto :: Auto(){
  estado = "Disponible";
	marca = "undefined";
	modelo = "undefined";
	color = "undefined";
	transmision = "undefined";
  puertas=0;
  traccion ="undefined";
  direccion = "undefined";
  tipoDeCombustible ="undefined";
  rendimiento=0;
  capacidadAl=0;
  precio=0;
  id=0;
}
Auto:: Auto(double price,int iD, string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac){

    estado = "Disponible";
    marca = mar;
    modelo = mod;
    color = col;
    transmision = tran;
    direccion = dir;
    puertas = pue;
    traccion = trac;
    tipoDeCombustible =tdc;
    rendimiento = ren;
    capacidadAl= cap;
    direccion = dir;
    puertas = pue;
    precio= price;
    id=iD;

}
double Auto :: getPrecio(){
    return precio;
}
int Auto :: getId(){
  return id;
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

string Auto :: getDireccion(){
    return direccion;
}
int Auto :: getPuertas(){
    return puertas;
}
string Auto :: getTraccion(){
    return traccion;
}
void Auto :: setPrecio(double nuevoPrecio){
    precio = nuevoPrecio;
}
void Auto :: setEstado (string nuevoEstado)
{
    estado = nuevoEstado;
}
#endif