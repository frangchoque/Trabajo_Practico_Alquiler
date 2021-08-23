#include "cAlquiler.h"

cAlquiler::cAlquiler(string id)
{
	this->ID = id;
	Fecha_Alquiler = tm();
	Fecha_Devolucion = tm();
	Pagado = false;
	Monto_total = 0;
	cliente = NULL;
	vehiculo = NULL;
}

cAlquiler::~cAlquiler()
{
}

void cAlquiler::CalcularMontoTotal()
{
	Monto_total = vehiculo->getPrecioBase() + (vehiculo->getPrecioDia() * vehiculo->getCantp());
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
	
}
