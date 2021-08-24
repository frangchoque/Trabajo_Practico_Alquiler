#include "cCliente.h"
//#include "Auxiliar.h"
cCliente::cCliente(string DNI, tm fecha_nacimiento, string mail, string nombre, float plata, string telefono, eVehiculo tipo)
{
    this->DNI = DNI;
    Fecha_Nacimiento = fecha_nacimiento;
    Mail = mail;
    Nombre = nombre;
    Plata = plata;
    Telefono = telefono;
    Tipo_Vehiculo = tipo;
    ID_Alquiler = "0";
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

void cCliente::AlquilarVehiculo(cAlquiler* alquiler)
{
    alquiler->ElegirAuto(this->Tipo_Vehiculo);

}

void cCliente::setID(string id)
{
    ID_Alquiler = id;
}

void cCliente::AsociarAlquiler(cAlquiler* alquiler)
{
    if (alquiler != NULL) {
        setID(alquiler->getID());
    }
}



string cCliente::to_string()
{
    string oracion;
    oracion = "\nNombre: " + this->Nombre + "\nDNI: " + this->DNI + "\nMail: " + this->Mail + "\nTelefono: " + this->Telefono + "\nPlata: "+
        std::to_string(this->Plata) + "\nTipo de vehiculo: " + Vehiculo_to_string(this->Tipo_Vehiculo);
    return oracion;
}

eVehiculo cCliente::getTipoVehiculo()
{
    return Tipo_Vehiculo;
}

cCliente::~cCliente()
{
}