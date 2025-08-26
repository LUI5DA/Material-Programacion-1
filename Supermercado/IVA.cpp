#include "IVA.h"

IVA::IVA()
{
	iva = 0;
}

IVA::IVA(int iva)
{
	this->iva = iva;
}

IVA::~IVA()
{
}

int IVA::getIva()
{
	return iva;
}

void IVA::setIva(int iva)
{
	this->iva = iva;
}

int IVA::calcularIva(int precio)
{
	return precio * iva / 100;
}

int IVA::calcularPrecioConIva(int precio)
{
	return precio + calcularIva(precio);
}