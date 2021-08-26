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
    //ID_Alquiler = "0";
}

void cCliente::Imprimir()
{
    cout <<to_string() << endl;
}

void cCliente::Pagar(cAlquiler *alquiler)//Acordarse de hacer un método en alquiler que verifique que el cliente pueda pagar
{
    if (alquiler != NULL) {
        if (this->DNI == alquiler->getCliente()->DNI)// njo se si eso funciona bien, creo que hay que guardar el DNI en una variable de alquiler y comparlos asi
        {
            if (Plata > alquiler->getMontoTotal())
                Plata -= alquiler->getMontoTotal();
            alquiler->setPagado(true);
            if (Plata < alquiler->getMontoTotal()) { cout << "\n no tiene la suficiente plata"; }
        }
        else cout << "\n No coincide el DNI de la persona con el DNI del Alquiler";
    }
}

//void cCliente::AlquilarVehiculo(cAlquiler* alquiler)
//{
//    alquiler->ElegirAuto(this->Tipo_Vehiculo);
//
//}



    



string cCliente::to_string()
{
    string oracion;
    oracion = "\nNombre: " + this->Nombre + "\nDNI: " + this->DNI + "\nMail: " + this->Mail + "\nTelefono: " + this->Telefono + "\nPlata: "+
        std::to_string(this->Plata) + "\nTipo de vehiculo: " + Vehiculo_to_string(this->Tipo_Vehiculo);
    return oracion;
}

string cCliente::getTipoVehiculo()
{
   
    return Vehiculo_to_string(Tipo_Vehiculo);
}

cCliente::~cCliente()
{
}