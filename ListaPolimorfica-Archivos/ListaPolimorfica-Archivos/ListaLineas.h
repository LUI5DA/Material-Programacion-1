#pragma once
#include "LineaCompra.h"

class NodoLinea {
public:
	LineaCompra* p;
	NodoLinea* siguiente;
	NodoLinea(LineaCompra* pr, NodoLinea* sig);
};

class ListaLineas
{
private:
	NodoLinea* first;

public:
	ListaLineas();
	virtual ~ListaLineas();

	void add(LineaCompra*);
	LineaCompra* search(int id);
	void remove(int id);

	string toString();
	void write(ofstream& f);
};

