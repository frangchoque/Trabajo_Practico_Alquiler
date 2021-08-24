#include "cAlquiler.h"


cAlquiler::cAlquiler(string id)
{
	this->ID = id;
	Fecha_Alquiler = tm();
	Fecha_Devolucion = tm();
	Pagado = false;
	Monto_total = 0;
	cliente = NULL;
	Vehiculo = NULL;
}

cAlquiler::~cAlquiler()
{
}

void cAlquiler::CalcularMontoTotal()
{
	Monto_total = Vehiculo->getPrecioBase() + (Vehiculo->getPrecioDia() * Vehiculo->getCantp());
}

void cAlquiler::ElegirAuto(eVehiculo vehiculo)
{ 
	//no se si esta del todo bien pero seria algo asi, el cliente desencadena todo
	string aux = Vehiculo_to_string(vehiculo);
	if (aux == "Moto") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n La Moto esta alquilada"; }

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
			
			}
			if (Vehiculo->getEstado_de_Verificacion() == false) { cout << "/n no se puede alquilar, falta la verificacion "; }
		}
	}
	if (aux == "Auto") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n El Auto esta alquilada"; }

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
			}
		}
	}
	if (aux == "Camioneta") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n La Camioneta esta alquilada"; }

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
			}
		}
	}
	if (aux == "Bicicleta") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n La Bicicleta esta alquilada"; }

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
			}
		}
	}

}
	
	void cAlquiler::FinalizarAlquiler(tm Fecha)
	{


	};

void cAlquiler::Imprimir()
{
}

string cAlquiler::to_string()
{
	return string();
}

cCliente* cAlquiler::getCliente()
{
	return this->cliente;
}

void cAlquiler::setPagado()
{
	Pagado = true;
}

unsigned int cAlquiler::CalcularDias()
{
	return 0;
}

string cAlquiler::getID()
{
	return ID;
}

