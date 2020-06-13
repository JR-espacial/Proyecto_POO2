#ifndef AUTOGASOLINA_H
#define AUTOGASOLINA_H
#include "auto.h"
#include <iostream>

using namespace std;

class AutoGasolinaRegular : public Auto {
    private:

		MotorGasolina motor;
    public:
		AutoGasolinaRegular();
    AutoGasolinaRegular(double price,int iD, string ,string ,int ,int , float ,  bool  ,int ,string ,string  , string ,string ,string , float , float,string,int,string  );

		MotorGasolina getMotorGasolina();
		string toString();

};
AutoGasolinaRegular :: AutoGasolinaRegular(): Auto(),motor(){

}
AutoGasolinaRegular :: AutoGasolinaRegular(double price,int iD, string modm, string marm,int cDF,int tor,float ac,bool tur,int cil,string mar , string mod,string col , string tran,string tdc, float ren, float cap,string dir,int pue,string trac ) : Auto(price,iD,mod ,mar,col,tran,tdc,ren,cap,dir,pue,trac) ,motor(modm,marm,cDF,tor,ac,tur,cil)
{

}

MotorGasolina AutoGasolinaRegular :: getMotorGasolina(){
    return motor;
}


string AutoGasolinaRegular :: toString(){
  stringstream aux;
    aux << "-----------------------------------"<<endl;
    aux << "------------Auto#"<<getId()<<"-----------------------"<<endl;
    aux << "-----------------------------------"<<endl;
    aux << "Atributos de el Motor(Gasolina)"<<endl;
    aux << "-----------------------------------"<<endl;
    aux <<"Modelo: " <<getMotorGasolina().getModelo()<<endl;
    aux <<"Marca: " <<getMotorGasolina().getMarca()<<endl;
    aux <<"Caballos de fuerza: " << getMotorGasolina().getCaballosDeFuerza()<<endl;
    aux <<"Cilindros: " <<getMotorGasolina().getCilindros()<<endl;
    aux <<"Turbo: " <<getMotorGasolina().getTurbo()<<endl;
    aux <<"Torque: " <<getMotorGasolina().getTorque()<<endl;
    aux <<"Acilidrada: " <<getMotorGasolina().getAcilindrada()<<endl;
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
    aux << "Rendimiento:"<<getRendimiento()<<"km/L"<<endl;
    aux <<"Capacidad:" <<getCapacidadAl()<<"L"<<endl;
    aux <<"Direccion: " <<getDireccion()<<endl;
    aux <<"Numero de Puertas:" <<getPuertas()<<endl;
    aux <<"Traccion:" <<getTraccion()<<endl;
    aux << "-----------------------------------"<<endl;
  return aux.str();
}

#endif