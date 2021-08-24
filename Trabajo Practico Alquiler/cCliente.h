#pragma once
#include <string>
#include <iostream>
//class cAlquiler;
#include "cAlquiler.h"
#include "Auxiliar.h"
using namespace std;

class cCliente
{
private:
	string DNI;
	tm Fecha_Nacimiento;
	string Mail;
	string Nombre;
	float Plata;
	string Telefono;
	eVehiculo Tipo_Vehiculo;
	string ID_Alquiler;//para verificar que el alquiler coincide con el cliente 

public:
	cCliente(string , tm , string , string , float , string , eVehiculo tipo);
	void Imprimir();
	void Pagar(cAlquiler* Alquiler);
	void AlquilarVehiculo(cAlquiler* alquiler);
	void setID(string id);
	void AsociarAlquiler(cAlquiler* alquiler);
	string to_string();
 eVehiculo getTipoVehiculo();//despues borrar
	~cCliente();//�Borrar el virtual? si , no vimos polimorfismo todavia 

};

