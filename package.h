#ifndef PACKAGE_H
#define PACKAGE_H 
#include <iostream>


class Package{
  protected:
  string remitente;
  string destinatario;
  float peso;
  float costoK;
  private:
  Package (string r,string d, float p,float c);
  string getRemitente();
  string getDestinatario(); 
  virtual double calculateCost ();

};
Package :: Package(string r,string d, float p,float c):remitente(r),destinatario(d),peso(p),costoK(c) {}

string Package :: getDestinatario(){
  return destinatario;
}
string Package :: getRemitente(){
  return remitente;
}

double Package :: calculateCost(){
  return( peso * costoK);
}

#endif