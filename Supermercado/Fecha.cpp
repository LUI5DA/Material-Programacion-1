#include "Fecha.h"

Fecha::Fecha()
{
	this->dia = new int(1);
	this->mes = new int(1);
	this->anio = new int(1990);
}

Fecha::Fecha(int dia, int mes, int anio)
{
	this->dia = new int(dia);
	this->mes = new int(mes);
	this->anio = new int(anio);
}

Fecha::Fecha(Fecha* fecha)
{
	this->dia = new int(fecha->getDia());
	this->mes = new int(fecha->getMes());
	this->anio = new int(fecha->getAnio());
}

Fecha::~Fecha()
{
	delete dia;
	delete mes;
	delete anio;
}

int Fecha::getDia()
{
	return *dia;
}

void Fecha::setDia(int dia)
{
	if (this->dia != NULL)
	{
		delete this->dia;
	}

	this->dia = new int(dia);
}

int Fecha::getMes()
{
	return *mes;
}

void Fecha::setMes(int mes)
{
	if (this->mes != NULL)
	{
		delete this->mes;
	}

	this->mes = new int(mes);
}

int Fecha::getAnio()
{
	return* anio;
}

void Fecha::setAnio(int anio)
{
	if (this->anio != NULL)
	{
		delete this->anio;
	}

	this->anio = new int(anio);
}

string Fecha::mostrarFecha()
{
	stringstream ss;
	ss << *dia << "/" << *mes << "/" << *anio << endl;
	return ss.str();
}

string Fecha::mostrarFechaCorta()
{
	stringstream ss;
	ss << *dia << "/" << *mes << "/" << (*anio % 100) << endl;
	return ss.str();
}