#include <iostream>
#include "cAlquiler.h"
#include "cCliente.h"
#include "cVehiculo.h"

int main() {
	tm Fecha = {0};
	cCliente* cliente1 = new cCliente("32432431", Fecha, "981@gmail.com", "Dario Iv", 1000.89, "1357924680", 1);
	//cVehiculo* vehiculo1 = new cVehiculo(/**/);
	//cAlquiler* alquiler1 = new cAlquiler(/**/);
	//Agregar mas 
	//
	delete cliente1;
	return 0;
}
