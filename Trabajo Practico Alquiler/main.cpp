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

	cAlquiler* alquiler1 = new cAlquiler("123456");
	cAlquiler* alquiler2 = new cAlquiler("7835293");

	cVehiculo* moto = new cVehiculo(2,eVehiculo::Moto,eColor::Blanco);
	cVehiculo* Auto= new cVehiculo(5, eVehiculo::Auto, eColor::Gris);
	//etc
	
	// asi seria
	alquiler1->IniciarAlquiler(moto,cliente2);// y las fechas
	alquiler2->FinalizarAlquiler();
	cliente2->Pagar(alquiler1);

	delete cliente1;
	delete moto;
	delete Auto;
	delete alquiler1;
	//terminar de liberar
	return 0;
}
