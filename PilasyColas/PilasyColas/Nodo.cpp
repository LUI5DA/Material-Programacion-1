#include "Nodo.h"

Nodo1::Nodo1(Paquete* val, Nodo1* sig)
{
	this->value = val;
	this->siguiente = sig;
}

Nodo1::~Nodo1()
{
}

Paquete* Nodo1::getValor()
{
	return this->value;
}

void Nodo1::setValor(Paquete* val)
{
	this->value = val;
}

Nodo1* Nodo1::getSiguiente()
{
	return this->siguiente;
}

void Nodo1::setSiguiente(Nodo1* sig)
{
	this->siguiente = sig;
}



// ==============================================================================================
// ==============================================================================================



Nodo2::Nodo2(char val, Nodo2* sig)
{
	this->value = val;
	this->siguiente = sig;
}

Nodo2::~Nodo2()
{
}

char Nodo2::getValor()
{
	return this->value;
}

void Nodo2::setValor(char val)
{
	this->value = val;
}

Nodo2* Nodo2::getSiguiente()
{
	return this->siguiente;
}

void Nodo2::setSiguiente(Nodo2* sig)
{
	this->siguiente = sig;
}
