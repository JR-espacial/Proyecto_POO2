#ifndef MOTORELECTRICO_H
#define MOTORELECTRICO_H
#include "motor.h"
#include <string>

using namespace std;

class MotorElectrico: public Motor{
    private:
         float tiempoDeAceleracion;

    public:
        MotorElectrico ();
        MotorElectrico(string,string,int,int,float);
        float getTiempoDeAceleracion();

};
MotorElectrico :: MotorElectrico ():Motor(){
    tiempoDeAceleracion = 0.0;
}
MotorElectrico :: MotorElectrico(string mod ,string mar ,int cDF,int tor,float tDA): Motor (mod,mar,cDF,tor){

    tiempoDeAceleracion = tDA;

}
float MotorElectrico :: getTiempoDeAceleracion(){
    return tiempoDeAceleracion;
}
#endif