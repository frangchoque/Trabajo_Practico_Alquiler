#pragma once
#include <string>
#include "cCliente.h"

using namespace std;

class cAlquiler
{
public:
	cAlquiler();
	virtual ~cAlquiler();

	void CalcularMontoTotal();
	void ElegirAuto(cVehiculo vehiculo);
	void FinalizarAlquiler(tm Fecha);
	void Imprimir();
	string to_string();

private:
	cCliente* cliente;

	tm Fecha_Devolucion;
	string ID;
	unsigned int Monto_total;
	bool Pagado;
};

