#pragma once
#include <string>
#include "Auxiliar.h"
#include "cVehiculo.h"
#include "cCliente.h"

using namespace std;

class cAlquiler
{
	cCliente* cliente;
	tm Fecha_Devolucion;
	string ID;
	unsigned int Monto_total;
	bool Pagado;
	cVehiculo* vehiculo;
public:
	cAlquiler(string id);
	virtual ~cAlquiler();

	void CalcularMontoTotal();
	void ElegirAuto(cVehiculo vehiculo);
	void FinalizarAlquiler(tm Fecha);
	void Imprimir();
	string to_string();


};

