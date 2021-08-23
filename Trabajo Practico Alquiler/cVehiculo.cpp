#include "cVehiculo.h"
cVehiculo::cVehiculo(int cantp,eVehiculo tipo_vehiculo , eColor color)
{
	this->Tipo_Vehiculo = tipo_vehiculo;
	this->Color = color;
	Patente = GenerarPatente();
	this->CantPasajeros = cantp;
	PrecioBase = 1000;
	PrecioDia = 0;
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

float cVehiculo::CalcularPrecioporDia(eVehiculo v)
{
	switch (v)
	{
	case eVehiculo::Auto:
		return 1000;
		break;
	case eVehiculo::Moto:
		return 800;
		break;
	case eVehiculo::Camioneta:
		return 1200;
		break;
	case eVehiculo::Bicicleta:
		return 300;
		break;
	default:
		break;
	}
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

int cVehiculo::getCantp()
{
	return CantPasajeros;
}

float cVehiculo::getPrecioBase()
{
	return PrecioBase;
}

float cVehiculo::getPrecioDia()
{
	return PrecioDia;
}

cVehiculo::~cVehiculo()
{
}