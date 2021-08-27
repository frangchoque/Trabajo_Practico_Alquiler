#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cAlquiler.h"
#include "cCliente.h"
#include "cVehiculo.h"
#include <ctime>
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;


int main() {
	time_t now = time(0);
	tm* Fecha = localtime(&now);
	tm Hoy = *Fecha;
	bool aux;

	//Hago que la fecha de inicio de alquiler sea el 27/8/2021
	Hoy.tm_year = 121;
	Hoy.tm_mday = 27;
	Hoy.tm_mon = 7;
	Hoy.tm_yday = 238;
	cCliente* cliente1 = new cCliente("32432431", Hoy, "981@gmail.com", "Dario Iv", 5000, "1357924680", eVehiculo::Auto);
	cCliente* cliente2 = new cCliente("5698754", Hoy, "algo@gmail.com", "Juan Hernandez ",100000 , "78952498", eVehiculo::Moto);

	cAlquiler* alquiler1 = new cAlquiler("123456", Hoy);
	cAlquiler* alquiler2 = new cAlquiler("7835293", Hoy);

	cVehiculo* moto = new cVehiculo(2,eVehiculo::Moto,eColor::Blanco);
	sleep_for(1s);//Para que no cree la misma patente
	cVehiculo* Auto= new cVehiculo(5, eVehiculo::Auto, eColor::Gris);
	//etc
	Fecha->tm_yday = Hoy.tm_yday+9;
	Fecha->tm_mday = 4;
	Fecha->tm_mon = 8;
	alquiler2->setFechaEntrega(*Fecha);
	alquiler2->Imprimir();

	alquiler1->setFechaEntrega(*Fecha);

	aux=alquiler1->IniciarAlquiler(moto, cliente1, cliente1->getTipoVehiculo());//Como no coinciden, lo que sigue va a fallar
	if (aux) {
		cliente1->Pagar(alquiler1);
		alquiler1->FinalizarAlquiler();
		alquiler1->Imprimir();
	}
	else
	{
		cout << "No se pudo completar el alquiler" << endl;
	}
	if (alquiler1->getPagado() == false && aux)
		cout << "\nNo pudo pagar el alquiler" << endl;
	aux = alquiler1->IniciarAlquiler(Auto, cliente1, cliente1->getTipoVehiculo());
	if (aux) {
		cliente1->Pagar(alquiler1);
		Auto->Imprimir();
		alquiler1->FinalizarAlquiler();
		alquiler1->Imprimir();
	}
	else
	{
		cout << "No se pudo completar el alquiler" << endl;
	}
	if (alquiler1->getPagado() == false && aux)//No le alcanza para pagar
		cout << "\nNo pudo pagar el alquiler" << endl;
	// asi seria
	aux=alquiler2->IniciarAlquiler(moto,cliente2, cliente2->getTipoVehiculo());
	if (aux) {
		cliente2->Pagar(alquiler2);
		alquiler2->FinalizarAlquiler();
		alquiler2->Imprimir();
	}
	else
	{
		cout << "No se pudo completar el alquiler" << endl;
	}
	if (alquiler2->getPagado() == false && aux)
		cout << "\nNo pudo pagar el alquiler" << endl;
	cliente1->Imprimir();
	cliente2->Imprimir();
	Auto->Imprimir();
	moto->Imprimir();
	//cliente2->Pagar(alquiler2);



	delete cliente1;
	delete cliente2;
	delete moto;
	delete Auto;
	delete alquiler1;
	delete alquiler2;
	//terminar de liberar
	return 0;
}
