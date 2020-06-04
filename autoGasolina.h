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
    AutoGasolinaRegular(string ,string ,int ,int , float ,  bool  ,int ,string ,string  , string ,string ,	float ,string , float , float,string,int,string  );

		MotorGasolina getMotorGasolina();
		void imprimeAtributos();

};
AutoGasolinaRegular :: AutoGasolinaRegular(): Auto(),motor(){

}
AutoGasolinaRegular :: AutoGasolinaRegular(string modm, string marm,int cDF,int tor,float ac,bool tur,int cil,string mar , string mod,string col , string tran,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac ) : Auto(mod ,mar,col,tran,pr,tdc,ren,cap,dir,pue,trac) ,motor(modm,marm,cDF,tor,ac,tur,cil)
{

}

MotorGasolina AutoGasolinaRegular :: getMotorGasolina(){
    return motor;
}


void AutoGasolinaRegular :: imprimeAtributos(){
    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Modelo: " <<getMotorGasolina().getModelo()<<endl;
    cout <<"Marca: " <<getMotorGasolina().getMarca()<<endl;
    cout <<"Caballos de fuerza: " << getMotorGasolina().getCaballosDeFuerza()<<endl;
    cout <<"Cilindros: " <<getMotorGasolina().getCilindros()<<endl;
    cout <<"Turbo: " <<getMotorGasolina().getTurbo()<<endl;
    cout <<"Torque: " <<getMotorGasolina().getTorque()<<endl;
    cout <<"Acilidrada: " <<getMotorGasolina().getAcilindrada()<<endl;
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
    cout <<"Capacidad:" <<getCapacidadAl()<<"L"<<endl;
    cout <<"Direccion: " <<getDireccion()<<endl;
    cout <<"Numero de Puertas:" <<getPuertas()<<endl;
    cout <<"Traccion:" <<getTraccion()<<endl;
    cout << "-----------------------------------"<<endl;
}

#endif