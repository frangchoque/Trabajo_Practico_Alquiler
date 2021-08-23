#include "cVehiculo.h"
cVehiculo::cVehiculo(eVehiculo Tipo_Vehiculo, eColor Color, int cantp)
{
	this->Tipo_Vehiculo = Tipo_Vehiculo;
	this->Color = Color;
	Patente = GenerarPatente();
	this->CantPasajeros = cantp;
	PrecioBase = 1000;
	PrecioDia = 0;//lo calculamos en la clase alquiler
	Alquiler = false;
	Verificado = true;
}

void cVehiculo::DevolverVehiculo()
{
	Alquiler = false;
	VerificacionSeguridad_Pendiente();
}

void cVehiculo::AqluilarVehiculo()
{
	Alquiler = true;

}

void cVehiculo::VerificacionSeguridad()
{
	cout << "\n El vehiculo es seguro para usar.";
}

void cVehiculo::VerificacionSeguridad_Pendiente()
{
	Verificado = false;
	cout << "\n Se debe realizar la verificacion de seguridad del Vehiculo.";
}

string cVehiculo::GenerarPatente()
{
	string aux;
	srand(time(NULL));
	int aux1 = (rand() % 5) + 1;
	int aux2 = (rand() % 5);
	int aux3 = (rand() % 5) + 1;
	return aux = "ABC" + aux1 + aux2 + aux3;
}

cVehiculo::~cVehiculo()
{
}