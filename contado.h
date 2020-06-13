#ifndef CONTADO_H
#define CONTADO_H
#include "pago.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Contado : public Pago{
	private:
    float descuento;
  public:
    Contado();
    Contado( float d);

    float getDescuento();

    float montoP();
    float cDescuento();
    void pagar();
    void setDescuento(float nuevoDescuento);
    string toString();
};
Contado:: Contado() : Pago(0.0,0,"Contado"),descuento(0.0){}
Contado:: Contado (float d) : Pago(0,0,"Contado"),descuento(d){}

float  Contado :: getDescuento(){
  return descuento;
}

float Contado :: montoP(){
  return(monto-(monto*descuento));
}
float Contado :: cDescuento(){
  return(monto*descuento);
}
void Contado :: setDescuento(float nuevoDescuento){
  descuento = nuevoDescuento;
}
void  Contado :: pagar(){
  cout<<"contado"<<endl;
}
string Contado :: toString(){
  stringstream aux;
  aux << "-----------------------------------"<<endl;
  aux << "------------Metodo de pago#"<<id<<"-----------------------"<<endl;
  aux<<"--------------------------------------"<<endl;
  aux<<"Pago de contado"<<endl;
  aux<<"Descuento: "<<descuento*100<<"%"<<endl;
  return aux.str();
}


#endif