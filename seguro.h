#ifndef SEGURO_H
#define SEGURO_H
#include <string.h>
#include <sstream>

using namespace std;

class Seguro{
  private:
    int id;
    float deducible;
    float sumaAsegurada;
    double costo;
    float respCiv;

  public:
    Seguro();
    Seguro(float d,float s,double c ,float r);
    Seguro( Seguro &s);

    int getId();
    float getDeducible();
    float getSumaAsegurada();
    double getCosto();
    float  getRespCiv();

    string toString();
    void setId(int newId);
};
Seguro :: Seguro(): deducible(0.0),sumaAsegurada(0.0),costo(0.0),respCiv(0.0){}
Seguro :: Seguro(float d,float s,double c ,float r): deducible(d),sumaAsegurada(s),costo(c),respCiv(r){}
Seguro:: Seguro(Seguro &s): deducible(s.deducible),sumaAsegurada(s.sumaAsegurada),costo(s.costo),respCiv(s.respCiv){}

int Seguro :: getId(){
  return id;
}
float Seguro :: getDeducible(){
  return deducible;
}
float Seguro :: getSumaAsegurada(){
  return sumaAsegurada;
}
double Seguro :: getCosto(){
  return costo;
}
float Seguro :: getRespCiv(){
  return respCiv;
}

void  Seguro :: setId(int newId){
  id = newId;
}

string Seguro :: toString(){
  stringstream aux;
  aux << "-----------------------------------"<<endl;
  aux << "------------Seguro#"<<id<<"-----------------------"<<endl;
  aux<<"--------------------------------------"<<endl;
  aux<<"Deducible:                "<<deducible<<"\n";
  aux<<"Suma Asegurada:           "<<sumaAsegurada<<"\n";
  aux<<"Costo:                    "<<costo<<"\n";
  aux<<"Responsabilidad civil:    "<<respCiv<<"\n";
  return aux.str();
}


#endif