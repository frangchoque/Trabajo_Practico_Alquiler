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
	Monto_total = Vehiculo->getPrecioBase() + (Vehiculo->getPrecioDia() * this->CalcularDias());
}

bool cAlquiler::ElegirAuto(eVehiculo vehiculo)
{ 
	//no se si esta del todo bien pero seria algo asi, el cliente desencadena todo
	string aux = Vehiculo_to_string(vehiculo);
	if (aux == "Moto") {
		if (Vehiculo->getEstado_de_Alquiler() == true) {
			cout << "\n La Moto esta alquilada";
			return false;
		}

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
				return true;
			
			}
			if (Vehiculo->getEstado_de_Verificacion() == false) {
				cout << "/n no se puede alquilar, falta la verificacion ";
				return false;
			}
		}
	}
	if (aux == "Auto") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n El Auto esta alquilada";
		return false;
		}

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
				return true;
			}
			if (Vehiculo->getEstado_de_Verificacion() == false) {
				cout << "/n no se puede alquilar, falta la verificacion ";
				return false;
			}
		}
	}
	if (aux == "Camioneta") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n La Camioneta esta alquilada"; 
		return false;
		}

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
				return true;
			}
			if (Vehiculo->getEstado_de_Verificacion() == false) {
				cout << "/n no se puede alquilar, falta la verificacion ";
				return false;
			}
		}
	}
	if (aux == "Bicicleta") {
		if (Vehiculo->getEstado_de_Alquiler() == true) { cout << "\n La Bicicleta esta alquilada"; 
		return false;
		}

		if (Vehiculo->getEstado_de_Alquiler() == false) {
			if (Vehiculo->getEstado_de_Verificacion() == true) {
				Vehiculo->setEstado_de_Alquiler(true);//se alquilo
				return true;
			}
			if (Vehiculo->getEstado_de_Verificacion() == false) {
				cout << "/n no se puede alquilar, falta la verificacion ";
				return false;
			}
		}
	}

}
void cAlquiler::IniciarAlquiler(cVehiculo* vehiculo, cCliente* cliente)
{
	bool aux=this->ElegirAuto(this->cliente->getTipoVehiculo());
	if (aux)
	{
		this->Vehiculo = vehiculo;
		this->cliente = cliente;
	}
	else
		return;
	return;
}
//Crear iniciar alquiler, que le pase un vehiculo y un cliente, verfique que el vehiculo esté en condiciones (ElegirAuto), 
//señale los punteros a vehiculo y cliente.
void cAlquiler::FinalizarAlquiler()//Fecha de devolucion es un objeto
{
		if (Fecha_Alquiler.tm_year == Fecha_Devolucion.tm_year && Fecha_Alquiler.tm_mon == Fecha_Devolucion.tm_mon &&
			Fecha_Alquiler.tm_mday == Fecha_Devolucion.tm_mday)
		{
			this->Vehiculo->setEstado_de_Alquiler(false);
			Monto_total = Vehiculo->getPrecioBase();
			cliente = NULL;
		}
		else
		{
			this->Vehiculo->setEstado_de_Alquiler(false);
			this->CalcularMontoTotal();
			cliente = NULL;
		}
};

void cAlquiler::Imprimir()
{
string aux;
aux= "\n "cliente.getNombre()+" alquilo un/una " +cliente.getTipoVehiculo() + "el dia: " to_string(Fecha_Devolucion) " hasta "+to_string(Fecha_Alquiler) + (this->CalcularDias()"dias")+"\n Numero de alquiler: "+ ID +"Monto total a abonar: "+to_string(Monto_total);
}
/*cCliente* cliente;
	tm Fecha_Devolucion;
	tm Fecha_Alquiler;
	string ID;//numero de alquiler
	float Monto_total;
	bool Pagado;
	cVehiculo* Vehiculo;*/
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
	unsigned int cont = 0;
	int aux;
	if (Fecha_Devolucion.tm_year == Fecha_Alquiler.tm_year)//Supongo que no lo va a devolver antes de pedirlo
	{
		cont = Fecha_Devolucion.tm_yday - Fecha_Alquiler.tm_yday;
	}
	//Solo considero que pasó un año
	if (Fecha_Alquiler.tm_year < Fecha_Devolucion.tm_year && Fecha_Alquiler.tm_year + 1 == Fecha_Devolucion.tm_year)//Sirve pero no se puede modificar yday
	{
		if (Fecha_Alquiler.tm_year % 4 == 0)//Año bisiesto
		{
			cont = 366 - Fecha_Alquiler.tm_yday + Fecha_Devolucion.tm_yday;
		}
		else
		{
			cont = 365 - Fecha_Alquiler.tm_yday + Fecha_Devolucion.tm_yday;
		}
	}//Varios años
	else if (Fecha_Alquiler.tm_year < Fecha_Devolucion.tm_year)
	{
		aux = Fecha_Devolucion.tm_year - Fecha_Alquiler.tm_year;
		cont = cont = 365 - Fecha_Alquiler.tm_yday + Fecha_Devolucion.tm_yday + 365 * aux;
		if ((Fecha_Alquiler.tm_year + aux) % 4 > 0)
		{
			cont += (Fecha_Alquiler.tm_year + aux) % 4;
		}
	}
	else if (Fecha_Alquiler.tm_year < Fecha_Devolucion.tm_year)//Un posible error
		return 0;

	return cont;
}

string cAlquiler::getID()
{
	return ID;
}

