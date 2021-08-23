#pragma once
#include <string>

using namespace std;

//typedef enum {
//	Negro = 1, Blanco, Azul, Rojo, Gris
//}eColor;
//
//typedef enum {
//	Auto=1, Moto, Camioneta, Bicicleta
//}eVehiculo;


enum class eColor { Negro, Blanco, Azul, Rojo, Gris }; typedef eColor Color;
enum class eVehiculo { Auto, Moto, Camioneta, Bicicleta }; typedef eVehiculo Vehiculo;


string tm_to_string(tm fecha)
{
	return to_string(fecha.tm_mday) + "/" + to_string(fecha.tm_mon) + "/" + to_string(fecha.tm_year) + "/";
}
string Vehiculo_to_string(eVehiculo vehiculo)
{
	switch (vehiculo)
	{
	case eVehiculo::Auto:
		return "Auto";
	case eVehiculo::Moto:
		return "Moto";
	case eVehiculo::Camioneta:
		return "Camioneta";
	case eVehiculo::Bicicleta:
		return "Bicicleta";
	}
}

string bool_to_string(bool booleano)
{
	if (booleano == true)
		return "Si";
	else
		return "No";
}

string Color_to_string(eColor color)
{
	switch (color)
	{
	case eColor::Negro:
		return "Negro";
	case eColor::Blanco:
		return "Blanco";
	case eColor::Azul:
		return "Azul";
	case eColor::Rojo:
		return "Rojo";
	case eColor::Gris:
		return "Gris";
	}
}