#include "cCliente.h"
#include "Auxiliar.h"
cCliente::cCliente(string DNI, tm fecha_nacimiento, string mail, string nombre, float plata, string telefono, unsigned short int tipo_vehiculo)
{
    this->DNI = DNI;
    Fecha_Nacimiento = fecha_nacimiento;
    Mail = mail;
    Nombre = nombre;
    Plata = plata;
    Telefono = telefono;
    Tipo_Vehiculo = tipo_vehiculo;
}

cCliente::~cCliente()
{
}

void cCliente::Imprimir()
{
    cout <<to_string() << endl;
}

void cCliente::Pagar(cAlquiler* Alquiler)
{
}

string cCliente::to_string()
{
    string aux, oracion;

    return string();
}
