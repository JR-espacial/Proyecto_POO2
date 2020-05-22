#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H 
#include "package.h"
#include <iostream>
#include<string>

class OvernightPackage: public Package{
  public:
  float tarifa;
  
  private:
  TwoDayPackage (string r,string d, float p,float c,float t);
  virtual double calculateCost ();

};
OvernightPackage :: OvernightPackage(string r,string d, float p,float c,float t):Package(r,d,p,c),tarifa(t){}
double TwoDayPackage :: calculateCost(){
  return ((peso * tarifa)+ Package::calculateCost());
}

#endif