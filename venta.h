#ifndef VENTAS_H
#define VENTAS_H
#include <string>
#include "seguro.h"

class Venta{
  private:
  int idAuto;
  int idCliente;
  Seguro seguro;
  string fechaVenta;
  float totalEntrante;
  public:
  Venta();
  Venta(int au, int cl,string fV, float tE);
};
Venta :: Venta():idAuto(0),idCliente(0),fechaVenta("undefined"),totalEntrante(0.0){}
Venta :: Venta(int au, int cl,string fV, float tE):idAuto(au),idCliente(cl),fechaVenta(fV),totalEntrante(tE){}

#endif