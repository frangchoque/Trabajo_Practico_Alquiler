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
    eVehiculo:Vehiculo:tipo_vehiculo;
}

cCliente::~cCliente()
{
}

void cCliente::Imprimir()
{
    cout <<to_string() << endl;
}

void cCliente::Pagar(cAlquiler* Alquiler)//Acordarse de hacer un método en alquiler que verifique que el cliente pueda pagar
{
    if (this->DNI == Alquiler->getCliente()->DNI)
        Alquiler->setPagado();
}

string cCliente::to_string()
{
    string oracion;
    oracion = "\nNombre: " + this->Nombre + "\nDNI: " + this->DNI + "\nMail: " + this->Mail + "\nTelefono: " + this->Telefono + "\nPlata: "+
        std::to_string(this->Plata) + "\nTipo de vehiculo: " + Vehiculo_to_string(this->Tipo_Vehiculo);
    return oracion;
}
