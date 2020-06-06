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
  Credito(double m,float tI,float tM, int p,float e,float mul);
  float mensualidad();
  void pagar();
  string toString();

};
Credito :: Credito():Pago(0.0,"Credito"),tazaI(0),tazaM(0),plazo(0),enganche(0),multa(0){}
Credito :: Credito(double m,float tI,float tM, int p,float e,float mul)
: Pago(m,"Credito"),tazaI(tI),tazaM(tM),plazo(p),enganche(e),multa(mul){

}
float Credito :: mensualidad(){
  return (monto/12)+(tazaI*monto);
}
void  Credito :: pagar(){
  cout<<"Credito"<<endl;
}
string Credito :: toString(){
  stringstream aux;
  aux<<"--------------------------------------"<<endl;
  aux<<"Pago con credito"<<endl;
  aux<<"Monto: "<<monto<<endl;
  aux<<"Taza de Interes:"<<tazaI<<endl;
  aux<<"Taza Moratoria: "<<tazaM<<endl;
  aux<<"Plazo(meses):"<<plazo<<endl;
  aux<<"Enganche:"<<enganche*100<<"%"<<endl;
  aux<<"Multa:"<<multa*100<<"%"<<endl;

  return aux.str();
}

#endif