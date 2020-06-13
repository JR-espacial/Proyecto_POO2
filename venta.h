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
    string fechaVenta;
    double totalEntrante;
    Seguro seguro;

  public:
    Venta();
    Venta(int au, int cl,string fV, double tE);
    Venta(int au, int cl,string fV, double tE,Seguro &s);

    int getIdAuto();
    int getIdCliente();
    bool getSeguroFlag();
    string  getFechaVenta();
    double  getTotalEntrante();

    string toString();
};
Venta :: Venta():idAuto(0),idCliente(0),fechaVenta("undefined"),totalEntrante(0.0),seguroFlag(0),seguro(){}
Venta :: Venta(int au, int cl,string fV, double tE):idAuto(au),idCliente(cl),fechaVenta(fV),totalEntrante(tE),seguroFlag(0),seguro(){}
Venta :: Venta(int au, int cl,string fV, double tE,Seguro &s):idAuto(au),idCliente(cl),fechaVenta(fV),totalEntrante(tE),seguroFlag(1),seguro(s){}

int Venta :: getIdAuto(){
  return idAuto;
}
int Venta :: getIdCliente(){
  return idCliente;
}
bool Venta :: getSeguroFlag(){
  return seguroFlag;
}
string Venta :: getFechaVenta(){
  return fechaVenta;
}
double Venta :: getTotalEntrante(){
  return totalEntrante;
}

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