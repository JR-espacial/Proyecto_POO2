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

void registraCliente();
void registraAutoG(Agencia& ag);
void registraAutoE(Agencia& ag);
void registraMetodoPCo(Agencia& ag);
void registraMetodoPCr(Agencia& ag);

int main (){
  Agencia ag;
  ag.agregaMetodoP(468596, .15, .5, 12, .20, .7);
  ag.agregaMetodoP(109009,.2);
  AutoElectrico ae(12000, 1, "SX13", "nissan",200 , 12, .5, "nissan","sentra 2001", "blanco", "manual", "electrico", 12, 300, "hidraulica", 4, "delantera", 12, 5);
  AutoGasolinaRegular agr;
  Cliente jorge (1,"Jorge Alan Ramirez Elias",18,4425762074,"jorge21@hotmail.com","GEC850101415","Paseo de la Reforma # 218");
  ag.agregaAuto(ae);
  ag.agregaAuto(agr);
  registraAutoE(ag);
  cout<<ag.toString();
  
return 0;
}
void registraCliente(Agencia& ag)
{
  int iD;
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
    cout <<"\n Cual es tu domicilio  ";
    cin >>domicilio;
    Cliente *c;
    c = new Cliente(0,nombre,edad,telefono,correoElectronico,rfc,domicilio);
    ag.agregaCliente(*c);
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
  cout<<"Dame el procentaje de descuento en decimal"<<endl;
  cin>>d;
  ag.agregaMetodoP(0,d);
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

  ag.agregaMetodoP(0,tazaI,tazaM,enganche,multa,plazo);
}


