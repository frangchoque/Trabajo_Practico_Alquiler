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

	cCliente* cliente1 = new cCliente("32432431", Hoy, "981@gmail.com", "Dario Iv", 1000, "1357924680", eVehiculo::Auto);
	//cVehiculo* vehiculo1 = new cVehiculo(/**/);
	//cAlquiler* alquiler1 = new cAlquiler(/**/);
	//Agregar mas 
	//
	cAlquiler* alquiler1 = new cAlquiler("123456");
	cliente1->AsociarAlquiler(alquiler1);
	cliente1->AlquilarVehiculo(alquiler1);
	delete cliente1;
	return 0;
}
