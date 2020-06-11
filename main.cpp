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
#include "seguro.h"


using namespace std;

int registraCliente();
void registraAutoG(Agencia& ag);
void registraAutoE(Agencia& ag);
void registraMetodoPCo(Agencia& ag);
void registraMetodoPCr(Agencia& ag);
void registraSeguro(Agencia &ag);
void sistema(Agencia &ag);
int validaUsuario(string u, Agencia &ag,int &id);
bool sistemaCliente(Agencia &ag,int &idCliente);
bool sistemaAdmin( Agencia &ag,int &idCliente);
void comprarAuto(Agencia &ag,int &idCliente);
int venta (Agencia &ag,int idAuto,int &idCliente);
int pagoContado(Agencia &ag,int idAuto,int &mPindex);
int pagoCredito(Agencia &ag,int idAuto,int &mPindex);
int adquirirSeguro(Agencia &ag,int idAuto, int &sIndex);

int main (){
  Agencia ag;
  Credito cr(.15, .5, 12, .20, .7);
  Contado co(.2);
  Seguro s(3,3,600,3);
  Venta v(1,1,"06/06/2020", 2000, s);
  Cliente feli(1,"Felipe",19,68969696,"felipe@gmail.com","FE700","Ecuador");
  ag.agregaMetodoP(cr);
  ag.agregaMetodoP(co);
  ag.agregaSeguro(s);
  ag.agregaVenta(v);
  ag.agregaCliente(feli);
  AutoElectrico ae(12000, 3, "SX13", "nissan",200 , 12, .5,"sentra 2001" ,"nissan", "blanco", "manual", "electrico", 12, 300, "hidraulica", 4, "delantera", 12, 5);
  AutoGasolinaRegular agr;
  Cliente jorge (50,"Jorge Alan Ramirez Elias",18,4425762074,"jorge21@hotmail.com","GEC850101415","Paseo de la Reforma # 218");
  
  ag.agregaAuto(ae);
  ag.agregaAuto(agr);
  
  //registraAutoE(ag);
  //registraSeguro(ag);
  //cout<<ag.formasPToString();
  //cout<<ag.autosToString();
  //cout<<ag.segurosToString();
  //cout<<ag.ventasToString();
  //cout<<ag.clientesToString();
  sistema(ag);
  
return 0;
}
int registraCliente(Agencia& ag)
{
  string nombre;
	int edad;
	long long int telefono;
	string correoElectronico;
	string rfc;
	string domicilio;

    cout <<"Cual es tu nombre  ";
    getline(cin>>ws,nombre);
    cout << "\nCuantos anos tienes  ";
    cin >> edad;
    cout << "\nCual es tu telefono  ";
    cin >> telefono;
    cout << "\nCual es tu correo electronico  ";
    cin >> correoElectronico;
    cout<<"\nCual es tu RFC  ";
    cin >> rfc;
    cout <<"\nCual es tu domicilio  ";
    cin >>domicilio;
    Cliente *c;
    c = new Cliente(0,nombre,edad,telefono,correoElectronico,rfc,domicilio);
    ag.agregaCliente(*c);
    for (int i =0;i<ag.getClientesActuales();i++){
      if (nombre == ag.getNombreCliente(i) ){
        return i;
      }
    }
}


void registraAutoG(Agencia &ag)
{
    string modm;
    string marm;
    int cDF;
    int tor;
    float ac;
    bool tur;
    int cil;
    string mar;
    string mod;
    string col;
    string tran;
    string tdc;
    float ren;
    float cap;
    string dir;
    int pue;
    string trac;
    double price;

    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Cual es el Modelo : "<<endl;
    cin >> modm;
    cout <<"Cual es la Marca: "<<endl;
    cin >> marm;
    cout <<"Cuantos Caballos de fuerza tiene: " <<endl;
    cin >>cDF;
    cout <<"Cuantos Cilindros: " <<endl;
    cin >> cil;
    cout <<"Tiene Turbo: " <<endl;
    cin >> tur;
    cout <<"Cuanto Torque: " <<endl;
    cin >> tor;
    cout <<" Cual es la capacidad de Acilidrada: " <<endl;
    cin >> ac;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout<<"Dame el precio de auto"<<endl;
    cin>>price;
    cout <<"Marca:" <<endl;
    cin >> mar;
    cout << "Color:"<<endl;
    cin >> col;
    cout << "Modelo:"<<endl;
    cin>> mod;
    cout <<"Tipo de Combustible:" <<endl;
    cin >> tdc;
    cout <<"Transmision:" <<endl;
    cin >> tran;
    cout << "Rendimiento:"<<"km/L"<<endl;
    cin >>ren;
    cout <<"Capacidad:" <<endl;
    cin >>cap;
    cout <<"Direccion: " <<endl;
    cin >> dir;
    cout <<"Numero de Puertas:" <<endl;
    cin >>pue;
    cout <<"Traccion:" <<endl;
    cin >> trac;
    cout << "-----------------------------------"<<endl;
    AutoGasolinaRegular *a;
    a=new AutoGasolinaRegular(price,0, modm, marm, cDF,tor,ac,tur,cil,mar,mod,col , tran,tdc,ren, cap,dir,pue,trac);

    ag.agregaAuto(*a);
}
void registraAutoE(Agencia& ag)
{
    string modm;
    string marm;
    int cDF;
    int tor;
    float ac;
    bool tur;
    int cil;
    string mar;
    string mod;
    string col;
    string tran;
    string tdc;
    float ren;
    float cap;
    string dir;
    int pue;
    string trac;
    float tdA;
    int aut;
    float tDR;
    double price;

    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Cual es el Modelo : "<<endl;
    cin >> modm;
    cout <<"Cual es la Marca: "<<endl;
    cin >> marm;
    cout <<"Cuantos Caballos de fuerza tiene: " <<endl;
    cin >>cDF;
    cout <<"Cuanto Torque: " <<endl;
    cin >> tor;
    cout<< "Cual es su Tiempo de aceleracion"<<endl;
    cin >> tdA;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout<<"Dame el precio de auto"<<endl;
    cin>>price;
    cout <<"Marca:" <<endl;
    cin >> mar;
    cout << "Color:"<<endl;
    cin >> col;
    cout << "Modelo:"<<endl;
    cin>> mod;
    cout <<"Tipo de Combustible:" <<endl;
    cin >> tdc;
    cout <<"Transmision:" <<endl;
    cin >> tran;
    cout << "Rendimiento:"<<"km/L"<<endl;
    cin >>ren;
    cout <<"Capacidad:" <<endl;
    cin >>cap;
    cout <<"Direccion: " <<endl;
    cin >> dir;
    cout <<"Numero de Puertas:" <<endl;
    cin >>pue;
    cout <<"Traccion:" <<endl;
    cin >> trac;
    cout << "-----------------------------------"<<endl;
     AutoElectrico *ae;
     ae = new AutoElectrico(price,0,modm,marm,cDF,tor,tdA,mar ,mod,col ,tran,tdc,ren,cap,dir,pue,trac,aut,tDR);
     ag.agregaAuto(*ae);

}
void registraMetodoPCo(Agencia& ag){
  float d;
  if (ag.getContado() == -1){
    cout<<"Dame el procentaje de descuento en decimal"<<endl;
    cin>>d;
    Contado *co;
    co = new Contado(d);
    ag.agregaMetodoP(*co);
    }
  else{
    int op;
    float nuevoDescuento;
    cout<<"Ya hay un metodo de pago registrado en la agencia \n Deseas cambiar el decuento actual\n [1] Si\n [2] No"<<endl;
    cin>> op;
    if (op == 1){
      cout<<"intruduce aqui el nuevo descuento(en forma decimal) :";
      cin >> nuevoDescuento;
      ag.modificaContado(nuevoDescuento);
    }
  }
}
void registraMetodoPCr(Agencia& ag){
  float tazaI,tazaM,enganche,multa;
  int plazo;
  cout<<"Dame la taza de Interes en decimal"<<endl;
  cin>>tazaI;
  cout<<"Dame la taza Moratoria en decimal"<<endl;
  cin>>tazaM;
  cout<<"Dame el porcentaje de enganche en decimal"<<endl;
  cin>>enganche;
  cout<<"Dame la el porcentaje de multa en decimal"<<endl;
  cin>>multa;
  cout<<"Dame la el plazo en meses"<<endl;
  cin>>plazo;
  Credito *cr;
  cr = new Credito(tazaI,tazaM,enganche,multa,plazo);
  ag.agregaMetodoP(*cr);
}
void registraSeguro(Agencia &ag){
  float deducible;
  float sumaAsegurada;
  float costo;
  float respCiv;
  cout << "Dame el procetaje de el deducible" << endl;
  cin >> deducible;
  cout << "Dame la  suma asegurada " << endl;
  cin >> sumaAsegurada;
  cout << "Dame el costo" << endl;
  cin >> costo;
  cout << "Dame las suma de cobertra de Resposabilidad Civil"<<endl;
  cin >> respCiv;
  Seguro *s;
  s = new Seguro(deducible,sumaAsegurada,costo,respCiv);
  ag.agregaSeguro(*s);
}
void sistema(Agencia &ag){
int first,second,idCliente;
bool loop =1;
while(loop == 1){
 cout<<"--------Menu Principal------"<<endl;
 cout<<"   Bienvenido al programa esta usted registrado?\n[1] Si\n[2] No\n[3] Salir\n escriba aqui la opcion  ";
 cin >> first;
 if (first == 1){
  string nombre;
  cout<<"Dame tu nombre"<<endl;
  getline(cin>>ws,nombre);
  second =validaUsuario(nombre, ag,idCliente);
  switch (second){
    case 1:
    loop=sistemaAdmin(ag,idCliente);
    if(loop == 0){
      cout<<"END"<<endl;
    }
    break;
    case 2:
    loop = sistemaCliente(ag,idCliente);
    cout<<"END"<<endl;
    break;
    case 3:
    idCliente = registraCliente(ag);
    loop = sistemaCliente(ag,idCliente);
    cout<<"END"<<endl;
    break;
    case 4:
    cout<<"END"<<endl;
  }
 }
 else if(first == 2){
  idCliente = registraCliente(ag);
   loop = sistemaCliente(ag,idCliente);
 }
 else if(first == 3){
   loop = 0;
   cout <<"END"<<endl;
 }
 }
}


int validaUsuario(string u, Agencia &ag,int &idCliente){
  bool coincidencia =0;
  string newName;
  int op;
  while (coincidencia == 0){
  if (u == "Jorge"){
    return 1;
  }
    for (int i =0;i<ag.getClientesActuales();i++){
      if (u == ag.getNombreCliente(i) ){
        idCliente=i;
        return 2;
      }
    }
    cout<<"No hay ningun usuario resgistrado con este nombre"<<endl;
    cout<<"1- Volver a introducir nombre/ 2- Registrarse/ 3 Salir del sitema"<<endl;
    cin>> op;
    switch (op){
      case 1:
      cout<<"Dame tu nombre"<<endl;
      getline(cin>>ws,newName);
      u = newName;
      break;
      case 2:
      return 3;
      break;
      case 3:
      return 4;
      break;
    }
  }
}


bool sistemaAdmin(Agencia &ag,int &idCliente){
  int op,op2,op3,enter,temp;
  bool salir = 0;
  cout<<"Sistema admin"<<endl;
  while (salir == 0){
  cout<<"Que deseas hacer\n[1] Registrar cliente\n[2] Registrar auto\n[3] Registrar metodo de pago\n[4] Registrar seguro\n[5] Imprimir datos sobre la agencia\n[6] Imprimir autos de la agencia\n[7] Imprimir seguros de la agencia\n[8] Imprimir clientes de la agencia\n[9] Imprimir formas de pago de la agencia\n[10] Imprimir ventas de la agencia\n[11] Salir al muenu principal\n[12] Salir del programa "<<endl;
  cin>>op;
  switch (op){
    case 1:
    temp = registraCliente(ag);
    cout<<"--------Cliente Registrado Exitosamete-------\n<Escriba 1  para continuar>"<<endl;
    cin>>enter;
    break;
    case 2:
    cout << "Que tipo de auto quieres registrar\n[1] Auto electrico\n[2] Auto gasolina"<<endl;
    cin >>op2;
    if(op2 == 1 ){
      registraAutoE(ag);
    }
    else {
    registraAutoG(ag);
    }
    break;
    case 3:
    cout << "Que tipo de pago quieres registrar\n[1] Contado\n[2] Credito"<<endl;
    cin >>op3;
    if(op3 == 1 ){
      registraMetodoPCo(ag);
    }
    else {
    registraMetodoPCr(ag);
    }
    break;
    case 4:
    registraSeguro(ag);
    case 5:
    cout << ag.toString();
    break;
    case 6:
    cout << ag.autosToString();
    break;
    case  7:
    cout << ag.segurosToString();
    break;
    case 8:
    cout << ag.clientesToString();
    break;
    case 9:
    cout << ag.formasPToString();
    break;
    case 10:
    cout<< ag.ventasToString();
    break;
    case 11:
    salir = 1;
    return 1;
    break;
    case 12:
    salir =1;
    return 0;
    break;
  }
  }
}

bool sistemaCliente(Agencia &ag, int &idCliente){
int op;
bool salir = 0;
string modelo;
float precioI,precioF;
while (salir == 0){
cout<<"\nQue deseas hacer:\n\n[1] Ver todos los autos\n[2] Buscar por modelo\n[3] Buscar por precio\n[4] Comprar auto\n[5] Salir al menu principal\n[6] Salir del programa"<<endl;
cin >>op;
switch (op){
  case 1:
   cout<<ag.autosToString();
   break;

  case 2:
  cout<<"Dame el modelo que bucas"<<endl;
  getline(cin>>ws,modelo);
  ag.busca(modelo);
  break;
  case 3:
  cout <<"Dame el precio inicial"<<endl;
  cin>>precioI;
  cout<<"Dame el ragngo maximo de precio"<<endl;
  cin>>precioF;
  ag.busca(precioI, precioF);
  break;
  case 4:
  comprarAuto(ag,idCliente);
  break;
  case 5:
  salir=1;
  return 1;
  break;
  case 6:
  salir =1;
  return 0;
  break;

}
}
}

void comprarAuto(Agencia &ag,int &idCliente){
  int op,idAuto;
  bool salir = 0;
  while (salir == 0){
  cout <<"Cual es el auto que usted desea comprar\n Introduca aqui el numero: ";
  cin >> idAuto;
  ag.busca(idAuto);
  cout<< "Este es el auto que usted escogio desea comprarlo\n[1] Si\n[2] No volver a escribir el numero de auto\n[3] No volver al menu anterior"<<endl;
  cin>>op;
  switch (op){
    case 1:
     salir = venta(ag,idAuto,idCliente);
    break;

    case 2:
    break;
    case 3:
    salir = 1;
    break;
  }
  }

}
int venta (Agencia &ag,int idAuto,int &idCliente){
  int salir=0; 
  int op,mPindex,sIndex,op2;
  sIndex=-1;
  while (salir <=0){
    cout <<"Que tipo de pago quieres hacer\n[1] Contado\n[2] Credito"<<endl;
    cin>> op;
    switch (op){
      case 1:
      salir = pagoContado(ag,idAuto,mPindex);
      if (salir == -1){
        cout<< "Dease comprar un seguro para tu auto\n[1] Si\n[2] No"<<endl;
        cin>>op2;
        if (op2 == 1){
          salir = adquirirSeguro(ag,idAuto,sIndex);
        }
        ag.venderAuto(idAuto, idCliente, sIndex,mPindex);
      }
      break;
      case 2:
      salir = pagoCredito(ag,idAuto,mPindex);
      if (salir == -1){
        cout<< "Dease comprar un seguro para tu auto\n[1] Si\n[2] No"<<endl;
        cin>>op2;
        if (op2 == 1){
          salir = adquirirSeguro(ag,idAuto,sIndex);
        }
        ag.venderAuto(idAuto, idCliente, sIndex,mPindex);
        
      }
      break;
    }
  }
  if (salir ==2){
    return 1;
  }
  else{
    return 0;
  }

}
int  pagoContado(Agencia &ag,int idAuto,int &mPindex){
  int op;
  float descuento;
  mPindex= ag.getContado();
  ag.estableceMontoP(idAuto,ag.getContado());
  cout<<ag.calculosContado();
  cout<< "Deseas proceder con el pago\n[1] Si \n[2] No cambiar forma de pago\n[3] No volver a escribir el numero de auto\n[4] No volver al menu anterior"<<endl;
  cin >> op;
  switch(op){
    case 1:
    return -1;
    break;
    case 2:
    return 0;
    break;
    case 3:
    return 1;
    break;
    case 4:
    return 2;
    break; 
  }
 
}
int pagoCredito(Agencia &ag,int idAuto,int &mPindex){
  int op,pIndex;
  cout << ag.creditoToString();
  cout<<"Estas son las opciones de credito\nCuando hayas escogido una escribe  el numero del Metodo de pago escogido"<<endl;
  cin >> pIndex;
  mPindex=pIndex;
  ag.estableceMontoP(idAuto, pIndex);
   cout<< "Deseas proceder con el pago\n[1] Si \n[2] No cambiar forma de pago\n[3] No volver a escribir el numero de auto\n[4] No volver al menu anterior"<<endl;
  cin >> op;
  switch(op){
    case 1:
    return -1;
    break;
    case 2:
    return 0;
    break;
    case 3:
    return 1;
    break;
    case 4:
    return 2;
    break; 
  }

}
int adquirirSeguro(Agencia &ag, int idAuto,int &sIndex){
  cout<<ag.segurosToString();
  cout<<"Estas son las opciones de Seguros\n cuando hayas escogido una escribe  el numero del Seguro  escogido"<<endl;
  cin >> sIndex;

}


