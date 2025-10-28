#pragma once
#include "Producto.h"

class NodoProducto {
public:
	Producto* p;
	NodoProducto* siguiente;
	NodoProducto(Producto* pr, NodoProducto* sig);
};

class ListaProducto
{
private:
	NodoProducto* first;

public:
	ListaProducto();
	virtual ~ListaProducto();

	void add(Producto*);
	Producto* search(int id);
	void remove(int id);

	string toString();
	void write(ofstream& f);
};

