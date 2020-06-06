#ifndef PAGO_H
#define PAGO_H
#include <string>

using namespace std;

class Pago{
  protected:
	double monto;
	string nombre;
	public:
	Pago();
	Pago( double m , string n);
	virtual void pagar()= 0;
  virtual string toString()=0;
};
Pago :: Pago (){
	monto = 0;
	nombre ="vacio";
}
Pago :: Pago (double m , string n):monto(m),nombre(n){}


#endif