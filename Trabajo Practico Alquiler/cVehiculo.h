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
	cVehiculo(eVehiculo Tipo_Vehiculo, eColor Color, int cantp);
	void DevolverVehiculo();
	void AqluilarVehiculo();
	void VerificacionSeguridad();
	void VerificacionSeguridad_Pendiente();
	string GenerarPatente();
	~cVehiculo();

};