#pragma once
#include <string>
#include <iostream>
#include "cAlquiler.h"
#include "Auxiliar.h"
//class cAlquiler;
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
	//string ID_Alquiler;//para verificar que el alquiler coincide con el cliente 

public://Probar tener un objeto puntero alquiler para poder usar los m?todos
	cCliente(string , tm , string , string , float , string , eVehiculo tipo);
	void Imprimir();
	void Pagar(cAlquiler* alquiler);
	//void AlquilarVehiculo(cAlquiler* alquiler);
	//void setID(string id);
	//void AsociarAlquiler(cAlquiler* alquiler);
	string to_string();
	string getTipoVehiculo();
	~cCliente();
};

