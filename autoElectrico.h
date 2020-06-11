#ifndef AUTOELECTRICO_H
#define AUTOELECTRICO_H
#include "auto.h"
#include "motorElectrico.h"
#include <string.h>
#include <sstream>
using namespace std;

class AutoElectrico : public Auto {
  private:
  int autonomia;
  float tiempoDeRecarga;
  MotorElectrico motor;
  public:
  AutoElectrico();
  AutoElectrico(double price,int iD, string ,string ,int ,int,float ,string ,string  , string ,string ,string , float , float,string,int,string,int,float );

  int getAutonomia();
  float getTiempoDeRecarga();
  MotorElectrico getMotorElectrico();

  string toString();

};
AutoElectrico :: AutoElectrico(): Auto (),motor(){
    autonomia = 0;
    tiempoDeRecarga = 0.0;

}
AutoElectrico :: AutoElectrico(double price,int iD, string modm, string marm,int cDF,int tor,float tDA,string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac,int aut,float tDR) : Auto(price,iD, mod ,mar,col,tran,tdc,ren,cap,dir,pue,trac), motor(modm,marm,cDF,tor,tDA)
{
    autonomia = aut;
    tiempoDeRecarga = tDR;
}

int AutoElectrico :: getAutonomia(){
    return autonomia;
}
float AutoElectrico :: getTiempoDeRecarga(){
    return tiempoDeRecarga;
}
MotorElectrico AutoElectrico :: getMotorElectrico(){
    return motor;
}
string AutoElectrico :: toString(){
  stringstream aux;
  aux << "-----------------------------------"<<endl;
  aux << "------------Auto#"<<getId()<<"-----------------------"<<endl;
  aux << "-----------------------------------"<<endl;
  aux << "Atributos de el Motor(Electrico)"<<endl;
  aux << "-----------------------------------"<<endl;
  aux <<"Modelo: " <<getMotorElectrico().getModelo()<<endl;
  aux <<"Marca: " <<getMotorElectrico().getMarca()<<endl;
  aux <<"Caballos de fuerza: " << getMotorElectrico().getCaballosDeFuerza()<<endl;
  aux <<"Torque: " <<getMotorElectrico().getTorque()<<endl;
  aux <<"Tiempo de aceleracion: " <<getMotorElectrico().getTiempoDeAceleracion()<<"segundos de 0 a 100km/h"<<endl;
  aux << "-----------------------------------"<<endl;
  aux << "Atributos de el auto"<<endl;
  aux << "-----------------------------------"<<endl;
  aux <<"Precio:"<<getPrecio()<<endl;
  aux <<"Id del Auto:"<<getId()<<endl;
  aux <<"Marca:" <<getMarca()<<endl;
  aux << "Color:"<<getColor()<<endl;
  aux << "Modelo:"<<getModelo()<<endl;
  aux <<"Tipo de Combustible:" <<getTipoDeCombustible()<<endl;
  aux <<"Transmision:" <<getTransmision()<<endl;
  aux << "Precio:"<<getPrecio()<<endl;
  aux << "Rendimeinto:"<<getRendimiento()<<"km/L"<<endl;
  aux <<"Capacidad:" <<getCapacidadAl()<<"kWh"<<endl;
  aux <<"Direccion: " <<getDireccion()<<endl;
  aux <<"Numero de Puertas:" <<getPuertas()<<endl;
  aux <<"Traccion:" <<getTraccion()<<endl;
  aux << "-----------------------------------"<<endl;
  return aux.str();
}
#endif