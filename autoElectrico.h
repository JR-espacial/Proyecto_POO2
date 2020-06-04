#ifndef AUTOELECTRICO_H
#define AUTOELECTRICO_H
#include "auto.h"
#include "motorElectrico.h"
#include <iostream>

class AutoElectrico : public Auto {
  private:
  int autonomia;
  float tiempoDeRecarga;
  MotorElectrico motor;
  public:
  AutoElectrico();
  AutoElectrico(string ,string ,int ,int,float ,string ,string  , string ,string ,	float ,string , float , float,string,int,string,int,float );

  int getAutonomia();
  float getTiempoDeRecarga();
  MotorElectrico getMotorElectrico();

  void imprimeAtributos();

};
AutoElectrico :: AutoElectrico(): Auto (),motor(){
    autonomia = 0;
    tiempoDeRecarga = 0.0;

}
AutoElectrico :: AutoElectrico(string modm, string marm,int cDF,int tor,float tDA,string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac,int aut,float tDR) : Auto( mod ,mar,col,tran,pr,tdc,ren,cap,dir,pue,trac), motor(modm,marm,cDF,tor,tDA)
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
void AutoElectrico :: imprimeAtributos(){
    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Modelo: " <<getMotorElectrico().getModelo()<<endl;
    cout <<"Marca: " <<getMotorElectrico().getMarca()<<endl;
    cout <<"Caballos de fuerza: " << getMotorElectrico().getCaballosDeFuerza()<<endl;
    cout <<"Torque: " <<getMotorElectrico().getTorque()<<endl;
    cout <<"Tiempo de aceleracion: " <<getMotorElectrico().getTiempoDeAceleracion()<<"segundos de 0 a 100km/h"<<endl;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Marca:" <<getMarca()<<endl;
    cout << "Color:"<<getColor()<<endl;
    cout << "Modelo:"<<getModelo()<<endl;
    cout <<"Tipo de Combustible:" <<getTipoDeCombustible()<<endl;
    cout <<"Transmision:" <<getTransmision()<<endl;
    cout << "Precio:"<<getPrecio()<<endl;
    cout << "Rendimeinto:"<<getRendimiento()<<"km/L"<<endl;
    cout <<"Capacidad:" <<getCapacidadAl()<<"kWh"<<endl;
    cout <<"Direccion: " <<getDireccion()<<endl;
    cout <<"Numero de Puertas:" <<getPuertas()<<endl;
    cout <<"Traccion:" <<getTraccion()<<endl;
    cout << "-----------------------------------"<<endl;
}
#endif