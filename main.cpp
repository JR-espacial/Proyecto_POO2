#include <iostream>
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"
#include <string>
using namespace std;

int main (){
	Package p("sender1","recipient1",10,2.35);
  TwoDayPackage t("sender1","recipient1",10,2.35,14.44);
  OvernightPackage o("sender1","recipient1",10,2.35,);

	return 0;
}
