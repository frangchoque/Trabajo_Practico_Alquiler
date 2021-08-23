#pragma once
#include <string>

#include "cVehiculo.h"
//#include "cCliente.h"
class cCliente;
using namespace std;

class cAlquiler//Cuando devuelve el vehiculo, quien tiene el metodo, ¿alquiler, vehiculo o cliente?¿O se lo reparten para que cada uno haga algo?
{//El cliente es el que devuelve, ¿entonces el es el que desencadena todos los metodos?
	cCliente* cliente;
	tm Fecha_Devolucion;
	tm Fecha_Alquiler;
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
	cCliente* getCliente();
	void setPagado();
	unsigned int CalcularDias();

};

