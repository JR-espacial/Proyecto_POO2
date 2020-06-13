/*----------------------------------
 *
 * Proyecto POO 2
 * Fecha: 13 Junio 2020
 * Autor: A001701350 Jorge Alan Ramirez Elias
 *
 -----------------------------------
 Descripcion de la fucionalidad de le archivo main
 El main basicamete se encarga de administrar la llamada a metodos de la clase agencia que contiene  varios arregrlos de objetos
 dinamicos con repecto a la declaracion de la agencia que se usara durate todo el programa
 llamada ag esta se declara en la primera linea de el main y crea sus arreglos de objetos de acuerdo a los valores que se le pongan en caso de querer cambiarlo puede simplemente modificar los parametros que se le dan y volver a correr el programa
 EN CASO DE QUE NO SE LE PASE NINGUN PARAMETRO SE DECLRARAN LOS OBJETOS CON LAS CONSTANTES TAM Y FP decalradas en la clase agencia
 
 En este main atmbien ya se pre crearon varios objetos para que se pueda hacer puebas con ellos

 Los usuarios registrados son Pedro y Felipe estos son clientes 

 PARA ENTRAR EN MODO ADMIN Y PODER HACER CAMBION EN LA AGENCIA SI COMO VER LOS CONTENIDOS DE SUS ARREGLOS DEBE
 INDICAR QUE SI ESTA REGISTRADO Y QUE SU NOMBRE ES:Jorge sin espacios antes ni despues y con la primera letra mayuscula
 
 *----------------------------------*/

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
#include <stdlib.h>


using namespace std;

int valida(string mensaje,int min,int max);
float validaPrecio(string mensaje,float min, float max);
long long int validaTelefono(string mensaje,long long int min,long long int max);
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
int comprarAuto(Agencia &ag,int &idCliente);
int venta (Agencia &ag,int idAuto,int &idCliente);
int pagoContado(Agencia &ag,int idAuto,int &mPindex);
int pagoCredito(Agencia &ag,int idAuto,int &mPindex);
int adquirirSeguro(Agencia &ag,int idAuto, int &sIndex);

int main (){
  Agencia ag("Agencia JA", 4423789396, "agenciaJA@gmail.com", "Queretaro,Qro",25, 20,5,25,4);
  Credito cr(.15, .5, 12, .20, .7);
  Contado co(.2);
  Seguro s(3,3,600,3);
  Venta v(1,1,"06/06/2020", 2000, s);
  Cliente feli(1,"Felipe",19,68969696,"felipe@gmail.com","FE700","Ecuador");
   AutoElectrico ae(200000, 3, "SX13", "Tesla",200 , 12, .5,"Model X" ,"Telsa", "negro", "automatico", "electrico", 12, 300, "hidraulica", 4, "delantera", 12, 5);
   AutoGasolinaRegular agr(30000,0, "SDR8" ,"nissan" ,300,18 , .3,  0  ,8 ,"sentra 2001" ,"nissan"  , "blanco" ,"manual" ,"gasolina premium" , 18 , 64,"hidraulica",4,"4x4"  );
  Cliente pedro (50,"Pedro",18,4425762074,"pedro@hotmail.com","GEC850101415","Paseo de la Reforma # 218");

  ag.agregaMetodoP(cr);
  ag.agregaMetodoP(co);
  ag.agregaSeguro(s);
  ag.agregaVenta(v);
  ag.agregaCliente(feli);
  ag.agregaCliente(pedro);
  ag.agregaAuto(ae);
  ag.agregaAuto(agr);

  sistema(ag);
  
return 0;
}
int valida(string mensaje,int min,int max){
  int i;
  string cad;
  bool valido = false;

  do {
      getline(cin, cad);
      stringstream mystream(cad);
      
      if(mystream >> i) {
          if(i >= min && i <= max) valido = true;
      }
      for (int j=0; j < cad.length(); j++){
        if (!(cad[j] >= '0' && cad[j] <= '9')){
          valido = false;
        }
      } 
      if(!valido) cout << "El valor no es valido"<< endl<< mensaje<<min<<" y "<<max<<endl;
  } while(!valido);
  return i;
}
float validaPrecio(string mensaje,float min,float max){
  float i;
  string cad;
  bool valido = false;

  do {
      getline(cin, cad);
      stringstream mystream(cad);
      
      if(mystream >> i) {
          if(i >= min && i <= max) valido = true;
      }
       
      if(!valido) cout << "El valor no es valido"<< endl<< mensaje<<min<<" y "<<max<<endl;
  } while(!valido);
  return i;
}
long long int validaTelefono(string mensaje,long long int min,long long int max){
  long long int i;
  string cad;
  bool valido = false;

  do {
      getline(cin, cad);
      stringstream mystream(cad);
      
      if(mystream >> i) {
          if(i >= min && i <= max) valido = true;
      }
       
      if(!valido) cout << "El valor no es valido"<< endl<< mensaje<<min<<" y "<<max<<endl;
  } while(!valido);
  return i;
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
    edad = valida("Introduce un numero entre", 0, 2130000000);
    cout << "\nCual es tu telefono  ";
    telefono= validaTelefono("Introduce un numero entre",0, 10000000000000000);
    cout << "\nCual es tu correo electronico  ";
    getline(cin>>ws,correoElectronico);
    cout<<"\nCual es tu RFC  ";
    getline(cin>>ws,rfc);
    cout <<"\nCual es tu domicilio  "<<endl;
    getline(cin>>ws,domicilio);
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
    getline(cin>>ws,modm);
    cout <<"Cual es la Marca: "<<endl;
    getline(cin>>ws,marm);
    cout <<"Cuantos Caballos de fuerza tiene: " <<endl;
    cDF = valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Cuantos Cilindros: " <<endl;
    cil= valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Tiene Turbo([1] si  [0] no): " <<endl;
    tur = valida("Introduce un numero entre", 0, 1);
    cout <<"Cuanto Torque: " <<endl;
    tor = valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Cual es la capacidad de Acilidrada: " <<endl;
    ac = validaPrecio("Ingresa un valor entre",0, 100000000000);
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout<<"Dame el precio de auto"<<endl;
    price = validaPrecio("Ingresa un valor entre",0, 100000000000);
    cout <<"Marca:" <<endl;
    getline(cin>>ws,mar);
    cout << "Color:"<<endl;
    getline(cin>>ws,col);
    cout << "Modelo:"<<endl;
    getline(cin>>ws,mod);
    cout <<"Tipo de Combustible:" <<endl;
    getline(cin>>ws,tdc);
    cout <<"Transmision:" <<endl;
    getline(cin>>ws,tran);
    cout << "Rendimiento:"<<"km/L"<<endl;
    ren =  valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Capacidad del tanque:" <<endl;
    cap =  valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Direccion: " <<endl;
    getline(cin>>ws,dir);
    cout <<"Numero de Puertas:" <<endl;
    pue =  valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Traccion:" <<endl;
    getline(cin>>ws,trac);
    cout << "-----------------------------------"<<endl;
    AutoGasolinaRegular *a;
    a=new AutoGasolinaRegular(price,0, modm, marm, cDF,tor,ac,tur,cil,mod,mar,col , tran,tdc,ren, cap,dir,pue,trac);

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
    getline(cin>>ws,modm);
    cout <<"Cual es la Marca: "<<endl;
    getline(cin>>ws,marm);
    cout <<"Cuantos Caballos de fuerza tiene: " <<endl;
    cDF = valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Cuanto Torque: " <<endl;
    tor = valida("Ingresa un valor entre", 0, 1000000000);
    cout<< "Cual es su Tiempo de aceleracion de 0 a 100"<<endl;
    tdA = valida("Ingresa un valor entre", 0, 1000000000);
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout<<"Dame el precio de auto"<<endl;
    price = validaPrecio("Ingresa un valor entre",0, 100000000000);
    cout <<"Marca:" <<endl;
    getline(cin>>ws,mar);
    cout << "Color:"<<endl;
    getline(cin>>ws,col);
    cout << "Modelo:"<<endl;
    getline(cin>>ws,mod);
    cout <<"Tipo de Combustible:" <<endl;
    getline(cin>>ws,tdc);
    cout <<"Transmision:" <<endl;
    getline(cin>>ws,tran);
    cout << "Rendimiento:"<<"Wh/100km"<<endl;
    ren = valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Capacidad de la bateria:" <<endl;
    cap = valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Direccion: " <<endl;
    getline(cin>>ws,dir);
    cout <<"Numero de Puertas:" <<endl;
    pue= valida("Ingresa un valor entre", 0, 1000000000);
    cout <<"Traccion:" <<endl;
    getline(cin>>ws,trac);
    cout << "-----------------------------------"<<endl;
     AutoElectrico *ae;
     ae = new AutoElectrico(price,0,modm,marm,cDF,tor,tdA,mar ,mod,col ,tran,tdc,ren,cap,dir,pue,trac,aut,tDR);
     ag.agregaAuto(*ae);

}
void registraMetodoPCo(Agencia& ag){
  float d;
  string limpia;
  if (ag.getContado() == -1){
    cout<<"Dame el procentaje de descuento en decimal"<<endl;
    d = validaPrecio("Ingresa un valor entre",0, 1);
    Contado *co;
    co = new Contado(d);
    ag.agregaMetodoP(*co);
    }
  else{
    int op;
    float nuevoDescuento;
    cout<<"Ya hay un metodo de pago registrado en la agencia \n Deseas cambiar el decuento actual\n [1] Si\n [2] No"<<endl;
    op = valida("Ingresa un valor entre",1, 2);
    if (op == 1){
      cout<<"intruduce aqui el nuevo descuento(en forma decimal) :";
      nuevoDescuento = validaPrecio("Ingresa un valor entre",0, 1);
      ag.modificaContado(nuevoDescuento);
    }
  }
}
void registraMetodoPCr(Agencia& ag){
  float tazaI,tazaM,enganche,multa;
  int plazo;
  cout<<"Dame la taza de Interes en decimal"<<endl;
  tazaI = validaPrecio("Ingresa un valor entre",0, 1);
  cout<<"Dame la taza Moratoria en decimal"<<endl;
  tazaM = validaPrecio("Ingresa un valor entre",0, 1);
  cout<<"Dame el porcentaje de enganche en decimal"<<endl;
  enganche = validaPrecio("Ingresa un valor entre",0, 1);
  cout<<"Dame la el porcentaje de multa en decimal"<<endl;
  multa = validaPrecio("Ingresa un valor entre",0, 1);
  cout<<"Dame la el plazo en meses"<<endl;
  plazo  = valida("Ingresa un valor entre",0, 1000000000);
  Credito *cr;
  cr = new Credito(tazaI,tazaM,enganche,multa,plazo);
  ag.agregaMetodoP(*cr);
}
void registraSeguro(Agencia &ag){
  float deducible;
  float sumaAsegurada;
  double costo;
  float respCiv;
  cout << "Dame el deducible" << endl;
  deducible = validaPrecio("Ingresa un valor entre",0, 1000000000000000000);
  cout << "Dame la  suma asegurada " << endl;
  sumaAsegurada = validaPrecio("Ingresa un valor entre",0, 1000000000000000000);
  cout << "Dame el costo" << endl;
  costo = validaPrecio("Ingresa un valor entre",0, 1000000000000000000);
  cout << "Dame la suma de cubiertra de Resposabilidad Civil"<<endl;
  respCiv = validaPrecio("Ingresa un valor entre",0, 1000000000000000000);
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
 first = valida("Introduce un valor entre ", 1, 3);
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
    loop = 0;
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
  system("clear");
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
    op = valida("Introduce un valor entre ", 1, 3);
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
  string continuar;
  bool salir = 0;
  system("clear");
  cout<<"Sistema admin"<<endl;
  while (salir == 0){
  cout<<"Que deseas hacer\n[1] Registrar cliente\n[2] Registrar auto\n[3] Registrar metodo de pago\n[4] Registrar seguro\n[5] Imprimir datos sobre la agencia\n[6] Imprimir autos de la agencia\n[7] Imprimir seguros de la agencia\n[8] Imprimir clientes de la agencia\n[9] Imprimir formas de pago de la agencia\n[10] Imprimir ventas de la agencia\n[11] Cerrar sesion\n[12] Salir del programa "<<endl;
  op = valida("Introduce un valor entre ", 1, 12);
  system("clear");
  switch (op){
    case 1:
    temp = registraCliente(ag);
    cout<<"--------Cliente Registrado Exitosamete-------"<<endl;
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 2:
    cout << "Que tipo de auto quieres registrar\n[1] Auto electrico\n[2] Auto gasolina"<<endl;
    op2 = valida("Introduce un valor entre ", 1, 2);
    if(op2 == 1 ){
      registraAutoE(ag);
    }
    else {
      registraAutoG(ag);
    }
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 3:
    cout << "Que tipo de pago quieres registrar\n[1] Contado\n[2] Credito"<<endl;
    op3 = valida("Introduce un valor entre ", 1, 2);
    if(op3 == 1 ){
      registraMetodoPCo(ag);
    }
    else {
    registraMetodoPCr(ag);
    }
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 4:
    registraSeguro(ag);
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 5:
    cout << ag.toString();
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 6:
    cout << ag.autosToString();
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case  7:
    cout << ag.segurosToString();
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 8:
    cout << ag.clientesToString();cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 9:
    cout << ag.formasPToString();
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
    break;
    case 10:
    cout<< ag.ventasToString();
    cout<<"Da enter para continuar ";
    getline(cin,continuar);
    system("clear");
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
string continuar;
system("clear");
int salir = 0;
string modelo;
float precioI,precioF;
while (salir == 0){
cout<<"Que deseas hacer:\n[1] Ver todos los autos\n[2] Buscar por modelo\n[3] Buscar por precio\n[4] Comprar auto\n[5] Cerrar sesion\n[6] Salir del programa"<<endl;
op = valida("Introduce un valor entre ", 1, 6);
system("clear");
switch (op){
  case 1:
   cout<<ag.autosToString();
   cout<<"Da enter para continuar ";
   getline(cin,continuar);
   system("clear");
   break;

  case 2:
  int valida;
  cout<<"Dame el modelo que bucas"<<endl;
  getline(cin>>ws,modelo);
  cout<<ag.buscaAuto(modelo); 
  cout<<"Da enter para continuar ";
  getline(cin,continuar);
  system("clear");
  break;
  case 3:
  cout <<"Dame el precio inicial"<<endl;
  precioI = validaPrecio("Introduce un valor entre ", 0, 1000000000000000000);
  cout<<"Dame el precio maximo de el auto que buscas"<<endl;
  precioF = validaPrecio("Introduce un valor entre ", 0, 1000000000000000000);
  while(precioF < precioI){
    cout <<"El precio maximo debe ser mayor al inicial"<<endl;
    cout << "El precio inicial que usted introdujo fue: "<<precioI<<endl;
    cout<<"Porfavor vuelve a darme el precio maximo de el auto que buscas"<<endl;
    precioF = validaPrecio("Introduce un valor entre ", 0, 1000000000000000000);
  }
  cout << ag.buscaAuto(precioI, precioF);
  cout<<"Da enter para continuar ";
  getline(cin,continuar);
  system("clear");
  break;
  case 4:
  salir = comprarAuto(ag,idCliente);
  if (salir == 2){
    return 0;
  }
  else if(salir == 1){
    return 1;
  }
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


int comprarAuto(Agencia &ag,int &idCliente){
  int op,idAuto;
  string limpia,continuar;
  int salir = 0;
  while (salir == 0){
  cout <<ag.modelosActualesToString();
  cout <<"Cual es el auto que usted desea comprar\n Introduca aqui el numero: ";
  idAuto = valida("Introduce un valor entre ", 0, ag.getAutosActuales()-1);
  system("clear");
  cout << ag.buscaAuto(idAuto);
  cout<< "Este es el auto que usted escogio desea comprarlo\n[1] Si\n[2] No volver a escribir el numero de auto\n[3] No volver al menu anterior"<<endl;
  op = valida("Introduce un valor entre ", 1, 3);
  system("clear");
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
  if (salir == 3){
    return 2;
  }
  else if (salir ==2){
    return 1;
  }
  else if (salir == 1){
    return 0;
  }

}
int venta (Agencia &ag,int idAuto,int &idCliente){
  int salir=0; 
  int op,mPindex,sIndex,op2,op3;
  sIndex=-1;
  while (salir <=0){
    system("clear");
    cout <<"Que tipo de pago quieres hacer\n[1] Contado\n[2] Credito"<<endl;
    op = valida("Introduce un valor entre ", 1, 2);
    system("clear");
    switch (op){
      case 1:
      salir = pagoContado(ag,idAuto,mPindex);
      if (salir == -1){
        cout<< "Dease comprar un seguro para tu auto\n[1] Si\n[2] No"<<endl;
        op2 = valida("Introduce un valor entre ", 1, 2);
        if (op2 == 1){
          salir = adquirirSeguro(ag,idAuto,sIndex);
        }
        ag.venderAuto(idAuto, idCliente, sIndex,mPindex);
        cout<<"Que  deseas hacer\n[1] Volver al menu principal\n[2] Cerrar sesion\n[3] Salir del programa"<<endl;
        op3 = valida("Introduce un valor entre ", 1, 3);
        system("clear");
        switch (op3){
          case 1:
          salir=2;
          break;
          case 2:
          salir= 3;
          break;
          case 3:
          salir =4;
          break;
        }
      }
      break;
      case 2:
      salir = pagoCredito(ag,idAuto,mPindex);
      if (salir == -1){
        cout<< "Dease comprar un seguro para tu auto\n[1] Si\n[2] No"<<endl;
        op2 = valida("Introduce un valor entre ", 1, 2);
        if (op2 == 1){
          salir = adquirirSeguro(ag,idAuto,sIndex);
        }
        ag.venderAuto(idAuto, idCliente, sIndex,mPindex);
        cout<<"Que  deseas hacer\n[1] Volver al menu principal\n[2] Cerrar sesion\n[3] Salir del programa"<<endl;
        op3 = valida("Introduce un valor entre ", 1, 3);
        switch (op3){
          case 1:
          salir=2;
          break;
          case 2:
          salir= 3;
          break;
          case 3:
          salir =4;
          break;
        }
        
      }
      break;
    }
  }
  if (salir ==2){
    return 1;
  }
  else if( salir ==3){
    return 2;
  }
   else if( salir ==4){
    return 3;
  }
  else{
    return 0;
  }

}
int  pagoContado(Agencia &ag,int idAuto,int &mPindex){
  int op,temp;
  float descuento;
  mPindex= ag.getContado();
  temp= ag.estableceMontoP(idAuto,ag.getContado(),"Contado");
  cout<<ag.calculosContado();
  cout<< "Deseas proceder con el pago\n[1] Si \n[2] No cambiar forma de pago\n[3] No volver a escribir el numero de auto\n[4] No volver al menu anterior"<<endl;
  op = valida("Introduce un valor entre ", 1, 4);
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
  int op,pIndex,valida2,op2;
  cout << ag.creditoToString();
  cout<<"Estas son las opciones de credito\nCuando hayas escogido una escribe  el numero del Metodo de pago escogido"<<endl;
  pIndex = valida("Introduce un valor entre ", 1, ag.getFormasPMax());
  valida2 = ag.estableceMontoP(idAuto, pIndex,"Credito");
  while (valida2 != 1){
    system("clear");
    switch (valida2){
      case 0:
      cout << "El metodo de pago seleccionado no existe\n";
      break;
      case 2:
      cout << "El metodo que usted seleciono no es de Credito\n";
      break;
    }
    cout << "Por favor vuelva a introducir el numero de pago que desea"<<endl;
    pIndex = valida("Introduce un valor entre ", 1, ag.getFormasPMax());
    valida2 = ag.estableceMontoP(idAuto,pIndex,"Credito");
  }
   mPindex=pIndex;
   cout<< "Deseas proceder con el pago\n[1] Si \n[2] No cambiar forma de pago\n[3] No volver a escribir el numero de auto\n[4] No volver al menu anterior"<<endl;
   op = valida("Introduce un valor entre ", 1, 4);
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
  cout<<"Estas son las opciones de Seguros\nCuando hayas escogido una escribe  el numero del Seguro  escogido"<<endl;
  
  sIndex =valida("El seguro no existe  porfavor introduce un valor entre ", 0, ag.getSegurosAct()-1);
  
}


