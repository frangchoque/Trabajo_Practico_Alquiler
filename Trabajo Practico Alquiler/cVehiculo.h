#pragma once
#include <iostream>
#include <time.h>
#include "Auxiliar.h"
using namespace std;
class cVehiculo
{
	string Patente;
	eColor Color;
	eVehiculo Tipo_Vehiculo;//auto,moto, camioneta o bicicleta
	int CantPasajeros;
	float PrecioBase;
	float  PrecioDia;
	bool Alquiler;//true:alquilado , false: no oesta alquilado
	bool Verificado; //true: tiene la verificacion de seguridad, false: no
public:
	cVehiculo (int cantp,eVehiculo tipo_vehiculo, eColor color);
	void DevolverVehiculo();
	void AlquilarVehiculo();
	void VerificacionSeguridad();
	void VerificacionSeguridad_Pendiente();
	float CalcularPrecioporDia(eVehiculo v);
	string GenerarPatente();
	int getCantp();
	float getPrecioBase();
	float getPrecioDia();
	bool getEstado_de_Alquiler();
	bool getEstado_de_Verificacion();
	void setEstado_de_Alquiler(bool Estado);
	string to_string();
	void Imprimir();
	~cVehiculo();
};