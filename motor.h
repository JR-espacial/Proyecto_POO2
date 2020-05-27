#ifndef MOTOR_H
#define MOTOR_H
#include <string>
using namespace std;

class  Motor{
    private:
    string modelo;
    string marca;
    int caballosDeFuerza;
	int torque;	
    public:
	Motor();
    Motor(string,string,int,int);

    string getModelo();
    string getMarca();
    int getCaballosDeFuerza();
    int getTorque();

};
Motor :: Motor (){
	modelo = "undefined";
	marca = "undefined";
	caballosDeFuerza = 0;
	torque = 0;
}
Motor :: Motor( string mod ,string mar ,int cDF,int tor){
    modelo = mod;
    marca = mar;
    caballosDeFuerza = cDF;
    torque = tor;
}
string Motor :: getModelo(){
    return modelo;
}
string Motor :: getMarca(){
    return marca;
}
int Motor :: getCaballosDeFuerza(){
    return caballosDeFuerza;
}

int Motor :: getTorque(){
	return torque;
}

#endif