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


using namespace std;

void registraCliente();
void registraAutoG(Agencia& ag);
void registraAutoE(Agencia& ag);

int main (){
 Agencia ag;
 cout<<"hola"<<endl; 
 ag.imprimeDatos();
	return 0;
}
void registraCliente(Agencia& ag)
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
    cout <<"\n Cual es tu domicilio  ";
    cin >>domicilio;
    ag.agregaCliente(Cliente(nombre,edad,telefono,correoElectronico,rfc,domicilio));
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
    float pr;
    string tdc;
    float ren;
    float cap;
    string dir;
    int pue;
    string trac;

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
    cout << "Precio:"<<endl;
    cin >> pr;
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


    ag.agregaAutoG(modm, marm, cDF,tor,ac,tur,cil,mar,mod,col , tran,pr,tdc,ren, cap,dir,pue,trac);
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
    float pr;
    string tdc;
    float ren;
    float cap;
    string dir;
    int pue;
    string trac;
    float tdA;
    int aut;
    float tDR;

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
    cout << "Precio:"<<endl;
    cin >> pr;
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


     ag.agregaAutoE(modm, marm,cDF,tor,tdA,mar , mod,col , tran,	pr,tdc, ren,  cap,dir,pue,trac,aut,tDR,1);

}
