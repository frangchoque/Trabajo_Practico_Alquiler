#include "cAlquiler.h"

cAlquiler::cAlquiler(string id)
{
	this->ID = id;
	Fecha_Alquiler = tm();
	Fecha_Devolucion = tm();
	Pagado = false;
	Monto_total = 0;
	Cliente = NULL;
	Vehiculo = NULL;
}

cAlquiler::~cAlquiler()
{
}

void cAlquiler::CalcularMontoTotal()
{
	Monto_total = Vehiculo->getPrecioBase() + (Vehiculo->getPrecioDia() * this->CalcularDias());
}

bool cAlquiler::ElegirAuto(cVehiculo* vehiculo, string Tipo_Vehiculo)//Recibe el tipo de vehiculo del cliente
{
	if (vehiculo != NULL) {
		if (vehiculo->getTipoVehiculo() == Tipo_Vehiculo) {
			string aux = vehiculo->getTipoVehiculo();
			if (aux == "Moto") {
				if (Vehiculo->getEstado_de_Alquiler() == true) {
					cout << "\n La Moto esta alquilada";
					vehiculo->setEstado_de_Alquiler(false);
					return false;// no se pudo
				}

				if (Vehiculo->getEstado_de_Alquiler() == false) {
					if (Vehiculo->getEstado_de_Verificacion() == true) {
						Vehiculo->setEstado_de_Alquiler(true);//se alquilo
						return true;// se pudo

					}
					if (Vehiculo->getEstado_de_Verificacion() == false) {
						cout << "/n no se puede alquilar, falta la verificacion ";
						vehiculo->setEstado_de_Verificacion(true);
						return false;
					}
				}
			}
			if (aux == "Auto") {
				if (Vehiculo->getEstado_de_Alquiler() == true) {
					cout << "\n El Auto esta alquilada";
					vehiculo->setEstado_de_Alquiler(false);
					return false;
				}

				if (Vehiculo->getEstado_de_Alquiler() == false) {
					if (Vehiculo->getEstado_de_Verificacion() == true) {
						Vehiculo->setEstado_de_Alquiler(true);//se alquilo
						return true;
					}
					if (Vehiculo->getEstado_de_Verificacion() == false) {
						cout << "/n no se puede alquilar, falta la verificacion ";
						vehiculo->setEstado_de_Verificacion(true);
						return false;
					}
				}
			}
			if (aux == "Camioneta") {
				if (Vehiculo->getEstado_de_Alquiler() == true) {
					cout << "\n La Camioneta esta alquilada";
					vehiculo->setEstado_de_Alquiler(false);
					return false;
				}

				if (Vehiculo->getEstado_de_Alquiler() == false) {
					if (Vehiculo->getEstado_de_Verificacion() == true) {
						Vehiculo->setEstado_de_Alquiler(true);//se alquilo
						return true;
					}
					if (Vehiculo->getEstado_de_Verificacion() == false) {
						cout << "/n no se puede alquilar, falta la verificacion ";
						vehiculo->setEstado_de_Verificacion(true);
						return false;
					}
				}
			}
			if (aux == "Bicicleta") {
				if (Vehiculo->getEstado_de_Alquiler() == true) {
					cout << "\n La Bicicleta esta alquilada";
					vehiculo->setEstado_de_Verificacion(false);
					return false;
				}

				if (Vehiculo->getEstado_de_Alquiler() == false) {
					if (Vehiculo->getEstado_de_Verificacion() == true) {
						Vehiculo->setEstado_de_Alquiler(true);//se alquilo
						return true;
					}
					if (Vehiculo->getEstado_de_Verificacion() == false) {
						cout << "/n no se puede alquilar, falta la verificacion ";
						vehiculo->setEstado_de_Verificacion(true);
						return false;
					}
				}
			}
		}
		cout << "\n No coincide el vehiculo con el que quiere el cliente";
		return false;
	}
	return false;
}

void cAlquiler::IniciarAlquiler(cVehiculo* vehiculo, cCliente* clientes) //podemos poner un tm fecha inicio y un tm fecha fin 
{
	/*bool aux=this->ElegirAuto(vehiculo,clientes);
	if (aux)
	{
		
	}
	else
		return;
	return;*/
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
		Cliente = NULL;
	}
	else
	{
		this->Vehiculo->setEstado_de_Alquiler(false);
		this->CalcularMontoTotal();
		Cliente = NULL;

	}
	Vehiculo->DevolverVehiculo();
		//llamar a la funcion pagar de cliente (la funcion tiene que recibir un puntero cliente) o llamrla en el main
};

void cAlquiler::Imprimir()
{
	cout << to_string() << endl;
}

string cAlquiler::to_string()
{
	string aux = "Fecha de Alquiler: " + tm_to_string(this->Fecha_Alquiler) + "\nFecha de devolución: " + tm_to_string(this->Fecha_Devolucion) + "\nID" + this->ID +
		"\nMonto total: " + std::to_string(Monto_total) + "\nPagado: " + bool_to_string(this->Pagado);
	return aux;
}

cCliente* cAlquiler::getCliente()
{
	return this->Cliente;
}

void cAlquiler::setPagado(bool algo)
{
	Pagado = algo;
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

float cAlquiler::getMontoTotal()
{
	return Monto_total;
}



