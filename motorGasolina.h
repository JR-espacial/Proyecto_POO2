#ifndef MOTORGASOLINA_H
#define MOTORGASOLINA_H
#include "motor.h"


class MotorGasolina: public Motor{
    private:
      float acilidradrada;
      bool turbo;
      int cilindros;
    public:
      MotorGasolina ();
      MotorGasolina (string,string,int,int,float,bool,int);
      int getCilindros();
      bool getTurbo();
      float getAcilindrada();

};
MotorGasolina :: MotorGasolina ():Motor(){
acilidradrada = 0.0;
turbo = false;
cilindros  = 0;
}

MotorGasolina :: MotorGasolina (string mod ,string mar ,int cDF,int tor, float ac,  bool tur ,int cil)
: Motor(mod ,mar , cDF, tor){
     acilidradrada = ac;
     turbo = tur;
     cilindros = cil;
}
bool MotorGasolina :: getTurbo(){
	return turbo;
}
float MotorGasolina :: getAcilindrada(){
	return acilidradrada;
}
int MotorGasolina :: getCilindros(){
    return cilindros;
}

#endif