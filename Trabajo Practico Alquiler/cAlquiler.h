#pragma once
#include <string>
#include <iostream>
#include "cVehiculo.h"//Si lo saco y pongo forward declaration los errores desaparecen pero surgen problemas en cAlquiler.cpp
//#include "cCliente.h"
//class cVehiculo;
class cCliente;
using namespace std;

class cAlquiler
{
	cCliente* Cliente;
	tm Fecha_Devolucion;
	tm Fecha_Alquiler;
	string ID;//numero de alquiler
	float Monto_total;
	bool Pagado;
	cVehiculo* Vehiculo;
public:
	cAlquiler(string id, tm Fecha_Alquiler);
	void CalcularMontoTotal();
	bool ElegirAuto(cVehiculo* vehiculo, string Tipo_Vehiculo);
	bool IniciarAlquiler(cVehiculo* vehiculo, cCliente* clientes, string Tipo_Vehiculo);
	void FinalizarAlquiler();//si la fecha de hoy coincide con tm fecha_devolucion se termina el alquiler
	void Imprimir();
	string to_string();
	cCliente* getCliente();
	void setPagado(bool algo);
	unsigned int CalcularDias();
	float getMontoTotal();
	void setCliente(cCliente* cliente);
	void setVehiculo(cVehiculo* vehiculo);
	void setFechaEntrega(tm fecha);
	//string getID();
	~cAlquiler();
};

