#include <iostream>
#include"pago.h"
#include"contado.h"
#include"credito.h"
#include"venta.h"
#include "motor.h"
#include "motorGasolina.h"
#include "motorElectrico.h"
#include "auto.h"
#include "autoGasolina.h"
#include "autoElectrico.h"
#include "cliente.h"
#include "agencia.h"


using namespace std;

int main (){
 Motor m;
 cout<<m.getTorque()<<endl;
 cout<<m.getMarca()<<endl;
 MotorGasolina mg; 
 cout<<mg.getTorque()<<endl;
 cout<<mg.getMarca()<<endl;
 AutoGasolinaRegular ag;
 ag.imprimeAtributos();
 AutoElectrico ae;
 ae.imprimeAtributos();
 Cliente cl;
 cl.imprimeDatos();
	return 0;
}
