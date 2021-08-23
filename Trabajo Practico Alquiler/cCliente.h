#pragma once
#include <string>
#include <iostream>
//class cAlquiler;
#include "cAlquiler.h"
#include "Auxiliar.h"
using namespace std;

class cCliente
{
public:
	cCliente(string , tm , string , string , float , string , unsigned short int);
	virtual ~cCliente();//�Borrar el virtual?
	

	void Imprimir();
	void Pagar(cAlquiler* Alquiler);
	string to_string();

private:
	string DNI;
	tm Fecha_Nacimiento;
	string Mail;
	string Nombre;
	float Plata;
	string Telefono;
	eVehiculo Tipo_Vehiculo;
};

