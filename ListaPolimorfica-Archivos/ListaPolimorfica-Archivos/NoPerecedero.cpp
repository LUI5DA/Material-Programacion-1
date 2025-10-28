#include "NoPerecedero.h"

NoPerecedero::NoPerecedero(int id, string descripcion, double precio, double iva, string marca, int garantia)
	:Producto::Producto(id, descripcion, precio, iva, marca)
{
	this->aniosGarantia = garantia;
}

NoPerecedero::~NoPerecedero()
{
}

int NoPerecedero::getAniosGarantia()
{
	return this->aniosGarantia;
}

void NoPerecedero::setAniosGarantia(int a)
{
	this->aniosGarantia = a;
}

string NoPerecedero::toString() {
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "No Perecedero" << endl;
	s << Producto::toString();
	s << "Anios de garantia: " << this->aniosGarantia << endl;
	s << "--------------------------------------------------------" << endl;
	return s.str();
}