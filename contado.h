#ifndef CONTADO_H
#define CONTADO_H
#include "pago.h"
#include <string>
#include <iostream>

using namespace std;

class Contado : public Pago{
	private:
	float descuento;
	public:
	Contado();
	Contado(double m, float d);
	float montoP();
	float cDescuento();
  void pagar();	
};
Contado:: Contado() : Pago(0.0,"contado"),descuento(0.0){}
Contado:: Contado (double m, float d) : Pago(m,"contado"),descuento(d){}

float Contado :: montoP(){
  return(monto-(monto*descuento));
}
float Contado :: cDescuento(){
  return(monto*descuento);
}
void  Contado :: pagar(){
  cout<<"contado"<<endl;
}


#endif