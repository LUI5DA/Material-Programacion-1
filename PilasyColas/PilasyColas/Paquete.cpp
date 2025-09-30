#include "Paquete.h"

Paquete::Paquete(int i, string direc, string ced)
{
    this->id = i;
    this->direccion = direc;
    this->Cedulacliente = ced;
}

string Paquete::toString()
{
    stringstream s;

    s << "id: " << this->id << endl;
    s << "direccion: " << this->direccion << endl;
    s << "cedula del cliente: " << this->Cedulacliente << endl;

    return s.str();
}

int Paquete::getId()
{
    return id;
}
