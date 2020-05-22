#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H 
#include "package.h"
#include <iostream>
#include<string>

class TwoDayPackage : public Package{
  public:
  float tarifa;
  
  private:
  TwoDayPackage (string r,string d, float p,float c,float t);
  virtual double calculateCost ();

};
TwoDayPackage :: TwoDayPackage(string r,string d, float p,float c,float t):Package(r,d,p,c),tarifa(t){}
double TwoDayPackage :: calculateCost(){
  return Package::calculateCost()+ tarifa;
}

#endif