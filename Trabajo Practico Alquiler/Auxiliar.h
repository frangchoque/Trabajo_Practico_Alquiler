#pragma once
#include <string>

using namespace std;

enum class eColor { Negro, Blanco, Azul, Rojo, Gris }; typedef eColor Color;
enum class eVehiculo { Auto, Moto, Camioneta, Bicicleta }; typedef eVehiculo Vehiculo;

string tm_to_string(tm fecha);

string Vehiculo_to_string(eVehiculo vehiculo);


string bool_to_string(bool booleano);


string Color_to_string(eColor color);