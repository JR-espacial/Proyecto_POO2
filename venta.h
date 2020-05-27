#ifndef VENTAS_H
#define VENTAS_H
#include <string>

class Venta{
  private:
  int idAgencia;
  int idAuto;
  int idCliente;
  string fechaVenta;
  float totalEntrante;
  public:
  Venta();
  Venta(int ag,int au, int cl,string fV, float tE);
};
Venta :: Venta():idAgencia(0),idAuto(0),idCliente(0),fechaVenta("undefined"),totalEntrante(0.0){}
Venta :: Venta(int ag,int au, int cl,string fV, float tE):idAgencia(ag),idAuto(au),idCliente(cl),fechaVenta(fV),totalEntrante(tE){}

#endif