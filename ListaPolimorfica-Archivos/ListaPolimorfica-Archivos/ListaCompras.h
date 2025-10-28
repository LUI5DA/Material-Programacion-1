#pragma once
#include "Compra.h"

class NodoCompra {
public:
	Compra* p;
	NodoCompra* siguiente;
	NodoCompra(Compra* pr, NodoCompra* sig);
};

class ListaCompras
{
private:
	NodoCompra* first;

public:
	ListaCompras();
	virtual ~ListaCompras();

	void add(Compra*);
	Compra* search(int id);
	void remove(int id);

	string toString();
	void write(ofstream& f);
};

