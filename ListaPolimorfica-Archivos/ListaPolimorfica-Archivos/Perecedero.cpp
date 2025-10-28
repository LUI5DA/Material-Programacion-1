#include "Perecedero.h"

Perecedero::Perecedero(int id, string desc, double prec, double iva, string marca, Fecha* f): Producto::Producto(id, desc, prec, iva, marca)
{
	this->expira = f;
}

Perecedero::~Perecedero()
{
	delete this->expira;
}

Fecha* Perecedero::getFecha()
{
	return this->expira;
}

void Perecedero::setFecha(Fecha* f)
{
	this->expira = f;
}

string Perecedero::toString() {
	stringstream s;

	s << "Producto Perecedero" << endl;
	s << Producto::toString();
	s << "fecha de expiracion: " << expira->toString() << endl;

	return s.str();
}
