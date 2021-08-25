#include "cVehiculo.h"

cVehiculo::cVehiculo(int cantp,eVehiculo tipo_vehiculo , eColor color)
{
	this->Tipo_Vehiculo = tipo_vehiculo;
	this->Color = color;
	Patente = GenerarPatente();
	this->CantPasajeros = cantp;
	PrecioBase = 1000;
	PrecioDia = CalcularPrecioporDia(tipo_vehiculo);
	Alquiler = false;
	Verificado = true;
}

void cVehiculo::DevolverVehiculo()
{
	Alquiler = false;
	VerificacionSeguridad_Pendiente();
}

void cVehiculo::AlquilarVehiculo()
{
	Alquiler = true;

}

void cVehiculo::VerificacionSeguridad()
{
	cout << "\n El vehiculo es seguro para usar.";
}

void cVehiculo::VerificacionSeguridad_Pendiente()
{
	Verificado = false;//Lo dejo comentado porque en la consigna no dice que deba imprimir un mensaje
	//cout << "\n Se debe realizar la verificacion de seguridad del Vehiculo.";
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

bool cVehiculo::getEstado_de_Alquiler()
{
	return Alquiler;
}

bool cVehiculo::getEstado_de_Verificacion()
{
	return Verificado;
}

void cVehiculo::setEstado_de_Alquiler(bool Estado)
{
	Alquiler = Estado;
}

cVehiculo::~cVehiculo()
{
}

string cVehiculo::to_string()
{
	string aux = "\nPatente: " + this->Patente + "\nTipo de vehiculo: " + Vehiculo_to_string(Tipo_Vehiculo) + "\nColor: " + Color_to_string(this->Color) +
		"\nCantidad de pasajeros: " + std::to_string(this->CantPasajeros) + "\nPrecio base: " + std::to_string(this->PrecioBase) + "\n Precio dia: "
		+ std::to_string(this->PrecioDia) + "\nAlquilado: " + bool_to_string(this->Alquiler) + "\nVerificacion de seguridad: " + bool_to_string(this->Verificado);
	return aux;
}

void cVehiculo::Imprimir()
{
	cout << this->to_string() << endl;
}
