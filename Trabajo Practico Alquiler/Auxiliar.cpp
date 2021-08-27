#include "Auxiliar.h"
string tm_to_string(tm fecha)
{
	return std::to_string(fecha.tm_mday) + "/" + std::to_string(fecha.tm_mon+1) + "/" + std::to_string(fecha.tm_year+1900) + "\n";
}
string Vehiculo_to_string(eVehiculo vehiculo)
{
	switch (vehiculo)
	{
	case eVehiculo::Auto:
		return "Auto";
		break;
	case eVehiculo::Moto:
		return "Moto";
		break;
	case eVehiculo::Camioneta:
		return "Camioneta";
		break;
	case eVehiculo::Bicicleta:
		return "Bicicleta";
		break;
	default:
		break;
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
		break;
	case eColor::Blanco:
		return "Blanco";
		break;
	case eColor::Azul:
		return "Azul";
		break;
	case eColor::Rojo:
		return "Rojo";
		break;
	case eColor::Gris:
		return "Gris";
		break;
	default:
		break;
	}
}