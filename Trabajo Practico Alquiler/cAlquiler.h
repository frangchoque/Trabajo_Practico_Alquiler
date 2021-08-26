#pragma once
#include <string>
#include <iostream>
#include "cVehiculo.h"//Si lo saco y pongo forward declaration los errores desaparecen pero surgen problemas en cAlquiler.cpp
#include "cCliente.h"
//class cVehiculo;
class cCliente;
using namespace std;

class cAlquiler//Cuando devuelve el vehiculo, quien tiene el metodo, ¿alquiler, vehiculo o cliente?¿O se lo reparten para que cada uno haga algo?
{//El cliente es el que devuelve, ¿entonces el es el que desencadena todos los metodos? si
	cCliente* Cliente;
	tm Fecha_Devolucion;
	tm Fecha_Alquiler;
	string ID;//numero de alquiler
	float Monto_total;
	bool Pagado;
	cVehiculo* Vehiculo;
public:
	cAlquiler(string id);
	void CalcularMontoTotal();
	bool ElegirAuto(cVehiculo* vehiculo,cCliente* clientes);
	void IniciarAlquiler(cVehiculo* vehiculo, cCliente* clientes);
	void FinalizarAlquiler();//si la fecha de hoy coincide con tm fecha_devolucion se termina el alquiler
	void Imprimir();
	string to_string();
	cCliente* getCliente();
	void setPagado(bool algo);
	unsigned int CalcularDias();
	float getMontoTotal();
	//string getID();
	virtual ~cAlquiler();
};

