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
	void AqluilarVehiculo();
	void VerificacionSeguridad();
	void VerificacionSeguridad_Pendiente();
	float CalcularPrecioporDia(eVehiculo v);
	string GenerarPatente();
	int getCantp();
	float getPrecioBase();
	float getPrecioDia();
	~cVehiculo();

};