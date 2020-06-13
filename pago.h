#ifndef PAGO_H
#define PAGO_H
#include <string>

using namespace std;

class Pago{
  protected:
    int id;
    string tipo;
    double monto;
    
	public:
    Pago();
    Pago( double m , int iD, string t);

    int  getId();
    string getTipo();
    double getMonto();

    void setId(int newId);
    void setMonto(double newMonto);
    virtual void pagar()= 0;
    virtual string toString()=0;
};
Pago :: Pago (){
	monto = 0;
	id = 0;
}
Pago :: Pago (double m , int iD,string t):monto(m),id(iD),tipo(t){}

int Pago :: getId(){
  return id;
}
string Pago :: getTipo(){
  return tipo;
}
double Pago :: getMonto(){
  return monto;
}

void Pago :: setId( int newId){
  id = newId;
}
void Pago :: setMonto(double newMonto){
  monto = newMonto;
}


#endif