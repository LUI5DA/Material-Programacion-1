#include "Mascota.h"
Mascota::Mascota(int e, string i, string n, string es): edad(e), id(i), nombre(n), especie(es)
{
}

Mascota::Mascota():Mascota(0, "", "", "")
{
}

Mascota::~Mascota()
{
}

int Mascota::getEdad()
{
	return edad;
}

string Mascota::getId()
{
	return id;
}

string Mascota::getNombre()
{
	return nombre;
}

string Mascota::getEspecie()
{
	return especie;
}

void Mascota::setEdad(int e)
{
	edad = e;
}

void Mascota::setId(string i)
{
	id = i;
}

void Mascota::setNombre(string n)
{
	nombre = n;
}

void Mascota::setEspecie(string e)
{
	especie = e;
}

string Mascota::toString()
{
	stringstream s;

	s << "ID: "<< id<< endl;
	s << "Edad: "<< edad<< endl;
	s << "Nombre: "<< nombre<< endl;
	s << "Especie: "<< especie<< endl;
	return s.str();
}
