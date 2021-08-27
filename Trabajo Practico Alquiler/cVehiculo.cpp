#include "cVehiculo.h"


cVehiculo::cVehiculo(int cantp,eVehiculo tipo_vehiculo , eColor color)
{
	this->Tipo_Vehiculo = tipo_vehiculo;
	this->Color = color;
	Patente = this->GenerarPatente();
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


void cVehiculo::VerificacionSeguridad()
{
	if (Verificado == true) {
		cout << "\n El vehiculo ya estaba verificado";
	}
	if (Verificado == false) {
		Verificado = true;
		cout << "\n el vehiculo es seguro para ser usado.";
	}
}

void cVehiculo::VerificacionSeguridad_Pendiente()
{
	Verificado = false;
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
	aux = "ABC" + std::to_string(aux1) + std::to_string(aux2) + std::to_string(aux3);
	return aux;
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

string cVehiculo::getTipoVehiculo()
{
	return Vehiculo_to_string(Tipo_Vehiculo);
}

bool cVehiculo::getEstado_de_Alquiler()
{
	return this->Alquiler;
}

bool cVehiculo::getEstado_de_Verificacion()
{
	return Verificado;
}

void cVehiculo::setEstado_de_Alquiler(bool Estado)
{
	Alquiler = Estado;
}

void cVehiculo::setEstado_de_Verificacion(bool estado)
{
	Verificado = estado;
}

cVehiculo::~cVehiculo()
{
}

string cVehiculo::to_string()
{
	string aux = "\nPatente: " + this->Patente + "\nTipo de vehiculo: " + Vehiculo_to_string(Tipo_Vehiculo) + "\nColor: " + Color_to_string(this->Color) +
		"\nCantidad de pasajeros: " + std::to_string(this->CantPasajeros) + "\nPrecio base: " + std::to_string(this->PrecioBase) + "\nPrecio dia: "
		+ std::to_string(this->PrecioDia) + "\nAlquilado: " + bool_to_string(this->Alquiler) + "\nVerificacion de seguridad: " + bool_to_string(this->Verificado);
	return aux;
}

void cVehiculo::Imprimir()
{
	cout << this->to_string() << endl;
}
