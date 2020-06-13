#ifndef CREDITO_H
#define CREDITO_H
#include "pago.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Credito : public Pago{
  private:
    float tazaI;
    float tazaM;
    int plazo;
    float enganche;
    float multa;

  public:
    Credito();
    Credito(float tI,float tM, int p,float e,float mul);

    float getTazaI();
    float getTazaM();
    int  getPlazo();
    float getEnganche();
    float getMulta();

    float mensualidad();
    void pagar();
    string toString();
};
Credito :: Credito():Pago(0.0,0,"Credito"),tazaI(0),tazaM(0),plazo(0),enganche(0),multa(0){}
Credito :: Credito(float tI,float tM, int p,float e,float mul)
: Pago(0,0,"Credito"),tazaI(tI),tazaM(tM),plazo(p),enganche(e),multa(mul){}

float Credito :: getTazaI(){
  return tazaI;
}
float Credito :: getTazaM(){
  return tazaM;
}
int Credito :: getPlazo(){
  return plazo;
}
float Credito :: getEnganche(){
  return enganche;
}
float  Credito :: getMulta(){
  return multa;
}

float Credito :: mensualidad(){
  return (monto/12)+(tazaI*monto);
}
void  Credito :: pagar(){
  enganche = enganche * monto;
}
string Credito :: toString(){
  stringstream aux;
  aux << "-----------------------------------"<<endl;
  aux << "------------Metodo de pago#"<<id<<"-----------------------"<<endl;
  aux<<"--------------------------------------"<<endl;
  aux<<"Pago con credito"<<endl;
  aux<<"Taza de Interes:"<<tazaI*100<<"%"<<endl;
  aux<<"Taza Moratoria: "<<tazaM*100<<"%"<<endl;
  aux<<"Plazo(meses):"<<plazo<<endl;
  aux<<"Enganche:"<<enganche*100<<"%"<<endl;
  aux<<"Multa:"<<multa*100<<"%"<<endl;

  return aux.str();
}

#endif