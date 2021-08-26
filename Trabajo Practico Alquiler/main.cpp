#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cAlquiler.h"
#include "cCliente.h"
#include "cVehiculo.h"
#include <ctime>


int main() {
	time_t now = time(0);
	tm* Fecha = localtime(&now);
	tm Hoy = *Fecha;

	cCliente* cliente1 = new cCliente("32432431", Hoy, "981@gmail.com", "Dario Iv", 5000, "1357924680", eVehiculo::Auto);
	cCliente* cliente2 = new cCliente("5698754", Hoy, "algo@gmail.com", "Juan Hernandez ",100000 , "78952498", eVehiculo::Moto);

	cAlquiler* alquiler1 = new cAlquiler("123456", Hoy);
	cAlquiler* alquiler2 = new cAlquiler("7835293", Hoy);

	cVehiculo* moto = new cVehiculo(2,eVehiculo::Moto,eColor::Blanco);
	cVehiculo* Auto= new cVehiculo(5, eVehiculo::Auto, eColor::Gris);
	//etc
	Fecha->tm_yday += 10;
	Fecha->tm_mday = 4;
	Fecha->tm_mon = 8;
	alquiler2->setFechaEntrega(*Fecha);
	alquiler2->Imprimir();
	// asi seria
	alquiler2->IniciarAlquiler(moto,cliente2, cliente2->getTipoVehiculo());// y las fechas
	cliente2->Pagar(alquiler2);
	alquiler2->FinalizarAlquiler();
	alquiler2->Imprimir();
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
