#include "Cliente.h"
Cliente::Cliente(int id, string nombre)
{
	this->id = id;
	this->nombre = nombre;
}

int Cliente::getId()
{
    return id;
}

string Cliente::getNombre()
{
    return nombre;
}

string Cliente::toString()
{
	stringstream ss;
	ss << "ID: " << id << ", Nombre: " << nombre;
	return ss.str();
}


void Cliente::setId(int i)
{
	this->id = i;
}

void Cliente::setNombre(string)
{
	this->nombre = nombre;
}

void Cliente::write(ofstream& descriptor)
{
	descriptor << id << '\t';
	descriptor << nombre << '\n';
}

Cliente* Cliente::read(ifstream& descriptor)
{
	int id;
	string nombre;
	descriptor >> id;
	descriptor >> nombre;
	return new Cliente(id, nombre);
}
