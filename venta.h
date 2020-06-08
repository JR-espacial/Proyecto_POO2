#ifndef VENTAS_H
#define VENTAS_H
#include <string>
#include <sstream>
#include "seguro.h"

using namespace std;

class Venta{
  private:
  int idAuto;
  int idCliente;
  bool seguroFlag;
  Seguro seguro;
  string fechaVenta;
  float totalEntrante;
  public:
  Venta();
  Venta(int au, int cl,string fV, float tE,bool sF,Seguro &s);
  string toString();
};
Venta :: Venta():idAuto(0),idCliente(0),fechaVenta("undefined"),totalEntrante(0.0),seguroFlag(0),seguro(){}
Venta :: Venta(int au, int cl,string fV, float tE,bool sF,Seguro &s):idAuto(au),idCliente(cl),fechaVenta(fV),totalEntrante(tE),seguroFlag(sF),seguro(s){}

string Venta :: toString(){
  stringstream aux;
  aux <<"Id del auto :      "<<idAuto<<endl;
  aux <<"Id del cliente :   "<<idCliente<<endl;
  aux <<"Fecha de venta :   "<<fechaVenta<<endl;
  aux <<"Total entrante :   "<<totalEntrante<<endl;
  if (seguroFlag == 1){
    aux <<"--------------------------"<<endl;
    aux <<"Datos del Seguro Comprado"<<endl;
    aux <<seguro.toString();
    aux <<"--------------------------"<<endl;
  }
  return aux.str();
}

#endif